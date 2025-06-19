#include "Client.hpp"
#include <iostream>

Client::Client(const std::string& name, const std::string& phone, int age,
    const std::string& clientId, bool isVip)
    : Person(name, phone, age), clientId(clientId), isVip(isVip) {
}

void Client::addVisit(const std::string& visitDetails) {
    visitHistory.push_back(visitDetails);
}

void Client::displayInfo() const {
    std::cout << "=== CLIENT INFORMATION ===" << std::endl;
    std::cout << "ID: " << clientId << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "VIP Status: " << (isVip ? "Yes" : "No") << std::endl;
    std::cout << "Preferred Stylist: " << preferredStylust << std::endl;
    std::cout << "Visit History (" << visitHistory.size() << "):" << std::endl;
    for (const auto& visit : visitHistory) {
        std::cout << "  - " << visit << std::endl;
    }
    std::cout << "==============================" << std::endl;
}
