#pragma once
#include <iostream>
#include <sstream>
#include <chrono>
#include <random>
#include <iomanip>

std::string generate_unique_string_id() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);

    std::stringstream ss;
    ss << std::hex << millis;
    for (int i = 0; i < 4; ++i) {
        ss << std::hex << dis(gen);
    }

    return ss.str();
}