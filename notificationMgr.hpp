#pragma once

#include <algorithm>
#include <map>
#include "common.cpp"
#include "unordered_map"
#include "vector"
#include "mutex"
#include "iNotificationSender.hpp"
#include "smsNotificationSender.hpp"
//This class corresponds to subject in the observer design pattern
//NotificationSender is the observer interface

class NotificationMgr {
	static NotificationMgr* notificationMgrInstance;
	// static mutex mtx;
	vector<int> tempvec;
	vector<pair<string,INotificationSender*>> vec;
	unordered_map<string, vector<pair<string,INotificationSender*>>> notificationSendersMap;
	unordered_map<int,int> test;
	NotificationMgr() {
		cout<<vec.size()<<endl;
		// vec.push_back(make_pair("non1", new SMSNotificationSender()));
		cout<<vec.size()<<endl;
		cout<<"In Notification Mgr Construction..."<<endl;
	}
	void addElement(pair<string, INotificationSender*>& p)
	{
		cout<<"new"<<endl;
		cout<<"Size : "<<vec.size()<<" "<<endl;
		// tempvec.push_back(1);
		vec.push_back(p);
		cout<<"Size : "<<vec.size()<<" "<<endl;
		for(int i=0;i<15;i++)
		{
			cout<<i<<" ";
			cout<<vec[i].first<<endl;
		}
	}
public:

	~NotificationMgr(); 
	static NotificationMgr* getNotificationMgr();
	//register observer
	void addNotificationSender(string tripId, string userId, INotificationSender* notificationSender);

	//unregister observer
	void removeNotificationSender(string tripId, string userId, INotificationSender* notificationSender);

	//notify Observers
	void notify(string tripId, string message);

	//notify particular user by a particular method
	void notifyParticularUser(string pUserId, string pMsg, INotificationSender* sender);
};