#pragma once
#include <iostream>
#include "iNotificationSender.hpp"

class SMSNotificationSender : public INotificationSender {
public:
    void sendNotification(std::string userId, std::string message) override;
};
