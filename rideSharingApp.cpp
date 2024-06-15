#include<bits/stdc++.h>
#include "traveler.hpp"
#include "travelerCompanion.cpp"
// #include "admin.hpp"
#include "common.cpp"
#include "trip.hpp"
#include "tripMgr.hpp"
using namespace std;

int main()
{
    cout<<"hi"<<endl;
    Traveler* traveler1 = new Traveler("Abhiram", "8919578343", "AP5588");
    cout<<"hi1"<<endl;
    TravelerCompanion* tc1 = new TravelerCompanion("Alpha", "XYZ");
    cout<<"hi2"<<endl;

    TripManager* tripManager = TripManager::getTripManagerInstance();
    cout<<"hi3"<<endl;
    string tripId = tripManager->createTrip(traveler1, new Location(5,5), new Location(10,10));
    cout<<tripId<<endl;
    cout<<"hi4"<<endl;
    vector<string> trips = tripManager->getAvailableTrips();
    cout<<"hi5"<<endl;
    cout<<trips.size()<<endl;
    cout<<trips[0]<<endl;
    tripManager->addTravelerCompanion(trips[0], tc1);
    cout<<"hi6"<<endl;
    tripManager->startTrip(trips[0]);
    cout<<"hi7"<<endl;
    tripManager->notifyUpdatesToTravelerCompanions(trips[0], "Almost reached to destination");
    cout<<"hi8"<<endl;
    tripManager->completeTrip(trips[0]);
    cout<<"hi9"<<endl;
    return(0);
}