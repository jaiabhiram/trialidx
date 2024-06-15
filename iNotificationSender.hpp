#pragma once
#include "common.cpp"


//This class corresponds to observer interface in the observer design pattern
//Notification Mgr is the subject

class INotificationSender {
public:
    virtual void sendNotification(string userId, string message) = 0;
    virtual ~INotificationSender() = default; // Ensure a virtual destructor
};
