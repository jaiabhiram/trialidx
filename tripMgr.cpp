#include "tripMgr.hpp"
#include <mutex>

TripManager* TripManager::tripManagerInstance = nullptr;
// mutex TripManager::mtx;

TripManager* TripManager::getTripManagerInstance()
{
    if(tripManagerInstance == nullptr)
    {
        // mtx.lock();
        if(tripManagerInstance == nullptr) {
            tripManagerInstance = new TripManager();
        }
        // mtx.unlock();
    }
    return tripManagerInstance;
}

void TripManager::addUserForNotificationUpdates(string tripId, User* user) {
	cout<<"add1 "<<endl;
    cout<<user->getUserId()<<endl;
	notificationMgr->addNotificationSender(tripId, user->getUserId(), new SMSNotificationSender());
    cout<<"add2"<<endl;
}

string TripManager::createTrip(Traveler* traveler, Location* startLoc,Location* endLoc)
{

    string tripId = "Trip1";
    Trip* trip = new Trip(traveler, startLoc, endLoc);
    trip->addEvent(new TripEvent("Trip Created"));
    inProgressTrips[tripId] = trip;
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
    cout<<"In ADDTC "<<tripId;
    Trip* trip = inProgressTrips[tripId];
    cout<<"st1"<<endl;
    trip->addTravelerCompanion(travelerCompanion);
    cout<<"st2"<<endl;
    addUserForNotificationUpdates(tripId, travelerCompanion);
    cout<<"st3"<<endl;
}

void TripManager:: completeTrip(string tripId)
{
    Trip* trip = inProgressTrips[tripId];
    inProgressTrips.erase(tripId);
    completedTrips[tripId] = trip;
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
    else if(completedTrips.count(tripId)) return(completedTrips[tripId]);
    // throw TripNotFoundException(tripId);
}

vector<string> TripManager::getAvailableTrips()
{
    vector<string> trips;
    cout<<"size of map "<<inProgressTrips.size()<<endl;
    for(auto x : inProgressTrips)
    {
        trips.push_back(x.first);
    }
    return(trips);
}