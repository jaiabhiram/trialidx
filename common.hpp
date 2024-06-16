#pragma once
#include <iostream>
#include <chrono>
using namespace std;

enum class TRIP_STATUS {
	CRAETED,
	IN_PROCESS,
    COMPLETED,
	CANCELLED
};

class Location {
	double latitude;
	double longitude;
public:
	Location(double pLat, double pLong) : latitude(pLat), longitude(pLong) {}
	double getLatitude() {
		return latitude;
	}
	double getLongitude() {
		return longitude;
	}
};