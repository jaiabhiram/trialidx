#include "tripevent.hpp"

TripEvent::TripEvent(string eMessage)
{
    timeStamp=time(nullptr); 
    message = eMessage;
}

void TripEvent::displayEvent()
{
    cout<<message<<endl;
}