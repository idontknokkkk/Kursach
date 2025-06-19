#include "Service.hpp"
#include <iostream>

Service::Service(const std::string& serviceId, const std::string& name,
    const std::string& description, double price,
    int durationMinutes, const std::string& category)
    : serviceId(serviceId), name(name), description(description),
    price(price), durationMinutes(durationMinutes), category(category) {
}

void Service::displayInfo() const {
    std::cout << "=== SERVICE INFORMATION ===" << std::endl;
    std::cout << "ID: " << serviceId << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Price: " << price << " UAH" << std::endl;
    std::cout << "Duration: " << durationMinutes << " min" << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "=============================" << std::endl;
}

double Service::calculateDiscountedPrice(double discountPercent) const {
    return price * (1.0 - discountPercent / 100.0);
}
