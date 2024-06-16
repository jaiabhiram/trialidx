#include "admin.hpp"

vector<Trip*> Admin::getAllTrips()
{
    tripManager->getTrips();
}

Trip* Admin::getTripDetails(string tripId)
{
    tripManager->getTrip(tripId);
}

void Admin::showFeedbackForTrip(string tripId)
{
    tripManager->showFeedbackToATrip(tripId);
}