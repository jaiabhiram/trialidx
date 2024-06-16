#include<bits/stdc++.h>
#include "traveler.hpp"
#include "travelerCompanion.cpp"
#include "admin.hpp"
#include "common.hpp"
#include "trip.hpp"
#include "tripMgr.hpp"
using namespace std;

int main()
{
    Traveler* traveler1 = new Traveler("Abhiram", "8919578343", "AP5588");
    TravelerCompanion* tc1 = new TravelerCompanion("Alpha", "XYZ");

    TripManager* tripManager = TripManager::getTripManagerInstance();

    string tripId = tripManager->createTrip(traveler1, new Location(5,5), new Location(10,10));

    vector<string> trips = tripManager->getAvailableTrips();
    tripManager->addTravelerCompanion(trips[0], tc1);

    tripManager->startTrip(trips[0]);
    tripManager->notifyUpdatesToTravelerCompanions(trips[0], "Almost reached to destination");
    tripManager->completeTrip(trips[0]);
    
    return(0);
}