#include "../include/Logger.hpp"
#include <iostream>
#include <ctime>

std::string currentTimestamp() {
    std::time_t t = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&t));
    return std::string(buf);
}

void Logger::info(const std::string& message) {
    std::cout << "\033[1;32m[" << currentTimestamp() << "] [INFO] " << message << "\033[0m\n";
}

void Logger::warn(const std::string& message) {
    std::cout << "\033[1;33m[" << currentTimestamp() << "] [WARN] " << message << "\033[0m\n";
}

void Logger::error(const std::string& message) {
    std::cerr << "\033[1;31m[" << currentTimestamp() << "] [ERROR] " << message << "\033[0m\n";
}
