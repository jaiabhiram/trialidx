#pragma once
#include <thread>
#include "mutex"
#include <unordered_map>
#include <string>
#include "trip.hpp"
#include "common.hpp"
#include "notificationMgr.hpp"
#include "tripNotFoundException.cpp"
#include "iNotificationSender.hpp"
#include "smsNotificationSender.hpp"
#include "uniqueIdGenerator.hpp"

class TripManager
{
    static TripManager* tripManagerInstance;
    static mutex mtx;
    NotificationMgr* notificationMgr;
    unordered_map<string, Trip*> notInProgressTrips;
    unordered_map<string, Trip*> inProgressTrips;
    TripManager() {
        NotificationMgr* notificationMgr = NotificationMgr::getNotificationMgr();
    };
    void addUserForNotificationUpdates(string tripId, User* user);
    public:
    static TripManager* getTripManagerInstance();
    string createTrip(Traveler* travler, Location* startLoc,Location* endLoc);
    void startTrip(string tripId);
    void addTravelerCompanion(string tripId, TravelerCompanion* travelerCompanion);
    void completeTrip(string tripId);
    void notifyUpdatesToTravelerCompanions(string tripId,string message);
    Trip* getTrip(string tripId);
    vector<string> getAvailableTrips();
    vector<Trip*> getTrips();
    void addFeedbackToTrip(string tripId,User* user, string message);
    void showFeedbackToATrip(string tripId);
};

