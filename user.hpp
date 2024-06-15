#ifndef USER_H
#define USER_H
#pragma once
#include <string>
#include <vector>
using namespace std;

class User {
protected:
    string userId;
    string name;
    string phoneNumber;
public:
    User(const string& name, const string& phoneNumber);
    // virtual ~User() = default;

    string getName() const;
    string getPhoneNumber() const;
    string getUserId() const;
};

#endif // USER_H
