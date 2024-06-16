#pragma once
#include "common.hpp"

class INotificationSender {
public:
    virtual void sendNotification(string userId, string message) = 0;
    virtual ~INotificationSender() = default;
};
