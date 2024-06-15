#pragma once
#include "smsNotificationSender.hpp"

void SMSNotificationSender::sendNotification(std::string userId, std::string message) {
    std::cout << "SMS Notification for " << userId << " is " << message << std::endl;
}
