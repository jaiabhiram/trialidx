#pragma once
#include <exception>
#include <string>
#include "tripException.cpp"

class TripNotFoundException : public TripException  {
public:
    explicit TripNotFoundException(const std::string& tripId);

    const char* what() const noexcept override;

private:
    std::string message;
};