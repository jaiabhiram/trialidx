#pragma once
#include "common.hpp"
#include "user.hpp"

class Feedback
{

    User* user;
    string message;
    public:
    Feedback(User* fuser, string fMessage) : user(fuser),message(fMessage) {};
    void displayFeedback();
};