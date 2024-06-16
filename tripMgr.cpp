#include "tripMgr.hpp"
#include <mutex>

TripManager* TripManager::tripManagerInstance = nullptr;
mutex TripManager::mtx;

TripManager* TripManager::getTripManagerInstance()
{
    if(tripManagerInstance == nullptr)
    {
        mtx.lock();
        if(tripManagerInstance == nullptr) {
            tripManagerInstance = new TripManager();
        }
        mtx.unlock();
    }
    return tripManagerInstance;
}

void TripManager::addUserForNotificationUpdates(string tripId, User* user) {
	notificationMgr->addNotificationSender(tripId, user->getUserId(), new SMSNotificationSender());
}

string TripManager::createTrip(Traveler* traveler, Location* startLoc,Location* endLoc)
{
    string tripId = "Trip1";
    Trip* trip = new Trip(traveler, startLoc, endLoc);
    trip->addEvent(new TripEvent("Trip Created"));
    inProgressTrips[tripId] = trip;
    traveler->addToTripHistory(tripId);
    return(tripId);
}

void TripManager::startTrip(string tripId)
{
    Trip* trip = inProgressTrips[tripId];
    trip->addEvent(new TripEvent("Trip started"));
    trip->setTripStatus(TRIP_STATUS::IN_PROCESS);
}

void TripManager::addTravelerCompanion(string tripId, TravelerCompanion* travelerCompanion)
{
    Trip* trip = inProgressTrips[tripId];
    trip->addTravelerCompanion(travelerCompanion);
    travelerCompanion->addToSharedRides(tripId);
    addUserForNotificationUpdates(tripId, travelerCompanion);
}

void TripManager:: completeTrip(string tripId)
{
    Trip* trip = inProgressTrips[tripId];
    inProgressTrips.erase(tripId);
    notInProgressTrips[tripId] = trip;
    trip->setTripStatus(TRIP_STATUS::COMPLETED);
    trip->addEvent(new TripEvent("Trip completed"));
    notificationMgr->notify(tripId, "Trip Completed");
}

void TripManager::notifyUpdatesToTravelerCompanions(string tripId,string message)
{
    notificationMgr->notify(tripId, message);
}

Trip* TripManager::getTrip(string tripId)
{
    if(inProgressTrips.count(tripId)) return(inProgressTrips[tripId]);
    else if(notInProgressTrips.count(tripId)) return(notInProgressTrips[tripId]);
    throw TripNotFoundException(tripId);
}

vector<string> TripManager::getAvailableTrips()
{
    vector<string> trips;
    for(auto x : inProgressTrips)
    {
        trips.push_back(x.first);
    }
    return(trips);
}

vector<Trip*> TripManager::getTrips()
{
    vector<Trip*> allTrips;
    for(auto x : inProgressTrips) allTrips.push_back(x.second);
    for(auto x : notInProgressTrips) allTrips.push_back(x.second);
    return(allTrips);
}

void TripManager::addFeedbackToTrip(string tripId,User* user, string message)
{
    Feedback* feedback = new Feedback(user,message);
    notInProgressTrips[tripId]->addFeedback(feedback);
}

void TripManager::showFeedbackToATrip(string tripId)
{
    notInProgressTrips[tripId]->displayFeedbacks();
}