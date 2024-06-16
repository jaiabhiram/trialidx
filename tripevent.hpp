#pragma once
#include <iostream>
#include<time.h>
using namespace std;
class TripEvent
{
    time_t timeStamp;
    string message;
    public:
    TripEvent(string eMessage);
    void displayEvent();
};