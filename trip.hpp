#pragma once
#include "common.hpp"
#include "user.hpp"
#include "traveler.hpp"
#include "travelerCompanion.cpp"
#include "tripevent.hpp"
#include "feedback.hpp"
class Trip
{
    string tripId;
    Traveler* traveler;
    vector<TravelerCompanion*> travelerCompanions;
    TRIP_STATUS status;
    Location* startLocation;
    Location* endLocation;
    time_t startTime;
    vector<TripEvent*> events;
    vector<Feedback*> feedbacks;
    public:
    Trip(Traveler* driver, Location* startLoc, Location* endLoc);
    void addTravelerCompanion(TravelerCompanion* travelerCompanion);
    void setTripStatus(TRIP_STATUS status);
    void getTripDetails();
    void addEvent(TripEvent* event);
    void displayEvents();
    void displayFeedbacks();
    void addFeedback(Feedback* feedback);
};