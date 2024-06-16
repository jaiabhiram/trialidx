#pragma once

#include "tripMgr.hpp"
class Admin
{
    TripManager* tripManager;
    public:
    Admin()
    {
        tripManager = TripManager::getTripManagerInstance();
    }
    vector<Trip*> getAllTrips();
    Trip* getTripDetails(string tripId);
    void showFeedbackForTrip(string tripId);
};