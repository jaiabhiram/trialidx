#include "trip.hpp"
Trip:: Trip(Traveler* driver,Location* startLoc, Location* endLoc) {
    this->traveler = driver;
    this->startLocation = startLoc;
    this->endLocation = endLoc;
};

void Trip::addTravelerCompanion(TravelerCompanion* travelerCompanion) {
    cout<<"hey"<<endl;
    status = TRIP_STATUS :: CRAETED;
    cout<<"hey1"<<endl; 
    travelerCompanions.push_back(travelerCompanion);
    cout<<"hey2"<<endl;
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

void Trip::displayFeedbacks()
{
    for(auto x : feedbacks)
    {
        // x->display();
    }
}