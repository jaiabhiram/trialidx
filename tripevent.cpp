#pragma once
#include <string>
// #include<time>
using namespace std;
class TripEvent
{
    // time_t time;
    string message;
    public:
    TripEvent(string eMessage)
    {
        // time=std::time(nullptr); 
        message = eMessage;
    } 
};