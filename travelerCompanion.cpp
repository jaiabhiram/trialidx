#pragma once
#include "user.hpp"
class TravelerCompanion : public User
{
    vector<string> sharedRides;
    public:
    TravelerCompanion(string name, string phoneNumber) : User(name, phoneNumber) {};
    void addToSharedRides(string tripId)
    {
        sharedRides.push_back(tripId);
    }
};