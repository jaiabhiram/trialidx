#include "notificationMgr.hpp"


NotificationMgr* NotificationMgr::notificationMgrInstance = nullptr;
// mutex NotificationMgr::mtx;

NotificationMgr* NotificationMgr::getNotificationMgr() {
	cout<<"In Notification MGR"<<endl;
	if (notificationMgrInstance == nullptr) {
		// mtx.lock();
		if (notificationMgrInstance == nullptr) {
			notificationMgrInstance = new NotificationMgr();
		}
		// mtx.unlock();
	}
	return notificationMgrInstance;
}

void NotificationMgr::addNotificationSender(string tripId, string userId, INotificationSender* notificationSender) {
		std::cout << "hey I am there out" << std::endl;
		pair<string, INotificationSender*> p = make_pair(userId, notificationSender);
		addElement(p);
		// vec.push_back(make_pair(userId, notificationSender));
		cout<<userId<<endl;
		cout<<vec.size()<<endl;
		cout<<vec.back().first<<endl;
    // auto& senders = notificationSendersMap[tripId];
    // std::cout << "Size of senders vector before addition: " << senders.size() << std::endl;

    // auto it = std::find_if(senders.begin(), senders.end(), [&](const std::pair<std::string, INotificationSender*>& p) {
    //     return p.first == userId && p.second == notificationSender;
    // });

    // if (it == senders.end()) {
    //     senders.push_back(std::make_pair(userId, notificationSender));
    //     std::cout << "Added sender for user " << userId << " for trip " << tripId << std::endl;
    // } else {
    //     std::cout << "Sender for user " << userId << " already exists for trip " << tripId << std::endl;
    // }

    // std::cout << "Size of senders vector after addition: " << senders.size() << std::endl;
	}


	void NotificationMgr::removeNotificationSender(string tripId, string userId, INotificationSender* notificationSender) {
		auto senderPos = find(notificationSendersMap[tripId].begin(),
			notificationSendersMap[tripId].end(), make_pair(userId, notificationSender));
		if (senderPos != notificationSendersMap[tripId].end()) {
			notificationSendersMap[tripId].erase(senderPos);
		}
	}


	void NotificationMgr::notify(std::string tripId, std::string message) {
    std::cout << "I reached here" << std::endl;
    for (const auto& x : vec) {
		cout<<x.first<<endl;
        std::cout << "Notifying user: " << x.first << " with message: " << message << std::endl;
        if (x.second) {
            x.second->sendNotification(x.first, message);
        } else {
            std::cout << "Notification sender is null for user: " << x.first << std::endl;
        }
    }
    std::cout << "I am done" << std::endl;
}

	void NotificationMgr::notifyParticularUser(string pUserId, string pMsg, INotificationSender* sender) {
		sender->sendNotification(pUserId, pMsg);
	}

	NotificationMgr::~NotificationMgr() {
        for (auto& pair : vec) {
            delete pair.second; // Clean up dynamically allocated objects
        }
	}