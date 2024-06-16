#include "traveler.hpp"

string Traveler::getCarNumber()
{
    return(carNumber);
}

void Traveler::addToTripHistory(string tripId)
{
    tripHistory.push_back(tripId);
}