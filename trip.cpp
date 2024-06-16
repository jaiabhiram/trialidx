#include "trip.hpp"
Trip:: Trip(Traveler* driver,Location* startLoc, Location* endLoc) {
    this->traveler = driver;
    this->startLocation = startLoc;
    this->endLocation = endLoc;
};

void Trip::addTravelerCompanion(TravelerCompanion* travelerCompanion) {
    status = TRIP_STATUS :: CRAETED;
    travelerCompanions.push_back(travelerCompanion);
    cout<<travelerCompanions.size()<<endl;
}

void Trip::setTripStatus(TRIP_STATUS status)
{
    this->status = status;
}

void Trip::getTripDetails()
{
    cout<<"Driver Name : "<<traveler->getName()<<endl;
    cout<<"Car Number : "<<traveler->getCarNumber()<<endl;
    cout<<"StartLocation : "<<startLocation->getLatitude()<<" "<<startLocation->getLongitude()<<endl;
    cout<<"EndLocation : "<<endLocation->getLatitude()<<" "<<endLocation->getLongitude()<<endl;
}

void Trip::addEvent(TripEvent* event)
{
    events.push_back(event);
}

void Trip::displayEvents()
{
    for(auto event : events)
    event->displayEvent();
}

void Trip::displayFeedbacks()
{
    for(auto x : feedbacks)
    {
        x->displayFeedback();
    }
}

void Trip::addFeedback(Feedback* feedback)
{
    feedbacks.push_back(feedback);
}