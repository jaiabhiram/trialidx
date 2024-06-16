#include "notificationMgr.hpp"


NotificationMgr* NotificationMgr::notificationMgrInstance = nullptr;
mutex NotificationMgr::mtx;

NotificationMgr* NotificationMgr::getNotificationMgr() {
	if (notificationMgrInstance == nullptr) {
		mtx.lock();
		if (notificationMgrInstance == nullptr) {
			notificationMgrInstance = new NotificationMgr();
		}
		mtx.unlock();
	}
	return notificationMgrInstance;
}

void NotificationMgr::addNotificationSender(string tripId, string userId, INotificationSender* notificationSender) {
		if (find(notificationSendersMap[tripId].begin(), notificationSendersMap[tripId].end(), make_pair(userId, notificationSender))
			== notificationSendersMap[tripId].end()) {
			notificationSendersMap[tripId].push_back(make_pair(userId, notificationSender));
		}
	}


	void NotificationMgr::removeNotificationSender(string tripId, string userId, INotificationSender* notificationSender) {
		auto senderPos = find(notificationSendersMap[tripId].begin(),
			notificationSendersMap[tripId].end(), make_pair(userId, notificationSender));
		if (senderPos != notificationSendersMap[tripId].end()) {
			notificationSendersMap[tripId].erase(senderPos);
		}
	}


	void NotificationMgr::notify(std::string tripId, std::string message) {
    for (auto sender : notificationSendersMap[tripId])
			sender.second->sendNotification(sender.first, message);
}

	void NotificationMgr::notifyParticularUser(string pUserId, string pMsg, INotificationSender* sender) {
		sender->sendNotification(pUserId, pMsg);
	}
