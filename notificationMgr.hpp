#pragma once

#include <algorithm>
#include <map>
#include "common.hpp"
#include "unordered_map"
#include "vector"
#include "mutex"
#include "iNotificationSender.hpp"
#include "smsNotificationSender.hpp"

class NotificationMgr {
	static NotificationMgr* notificationMgrInstance;
	static mutex mtx;
	vector<int> tempvec;
	unordered_map<string, vector<pair<string,INotificationSender*>>> notificationSendersMap;
	NotificationMgr() {}
public:

	static NotificationMgr* getNotificationMgr();
	void addNotificationSender(string tripId, string userId, INotificationSender* notificationSender);
	void removeNotificationSender(string tripId, string userId, INotificationSender* notificationSender);
	void notify(string tripId, string message);
	void notifyParticularUser(string pUserId, string pMsg, INotificationSender* sender);
};