#pragma once
#include <thread>
#include "mutex"
#include <unordered_map>
#include <string>
// #include "travelerCompanion.hpp"
#include "trip.hpp"
#include "common.cpp"
#include "notificationMgr.hpp"
#include "tripNotFoundException.cpp"
#include "iNotificationSender.hpp"
#include "smsNotificationSender.hpp"
// #include "uniqueIdGenerator.cpp"
// using namespace std;

class TripManager
{
    static TripManager* tripManagerInstance;
    // static mutex mtx;
    NotificationMgr* notificationMgr;
    unordered_map<string, Trip*> completedTrips;
    unordered_map<string, Trip*> inProgressTrips;
    TripManager() {
        cout<<"hi bro"<<endl;
        NotificationMgr* notificationMgr = NotificationMgr::getNotificationMgr();
        cout<<"got Notification Manager"<<endl;
    };
    public:
    static TripManager* getTripManagerInstance();
    void addUserForNotificationUpdates(string tripId, User* user);
    string createTrip(Traveler* travler, Location* startLoc,Location* endLoc);
    void startTrip(string tripId);
    void addTravelerCompanion(string tripId, TravelerCompanion* travelerCompanion);
    void completeTrip(string tripId);
    void notifyUpdatesToTravelerCompanions(string tripId,string message);
    Trip* getTrip(string tripId);
    vector<string> getAvailableTrips();
};

