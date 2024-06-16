#pragma once
#include "iNotificationSender.hpp"

class WhatsAppNotificationSender : public INotificationSender {
public:
    void sendNotification(string userId, string message) {
        cout << "whatsapp Notification for "<< userId <<" is " << message << endl;
    }
};