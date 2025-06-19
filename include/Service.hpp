#pragma once
#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <string>
#include <iostream>

class Service {
private:
    std::string serviceId;
    std::string name;
    std::string description;
    double price;
    int durationMinutes;
    std::string category;

public:
    Service(const std::string& serviceId = "", const std::string& name = "",
        const std::string& description = "", double price = 0.0,
        int durationMinutes = 0, const std::string& category = "");

    // Getters
    std::string getServiceId() const { return serviceId; }
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    double getPrice() const { return price; }
    int getDurationMinutes() const { return durationMinutes; }
    std::string getCategory() const { return category; }

    // Setters
    void setServiceId(const std::string& id) { this->serviceId = id; }
    void setName(const std::string& name) { this->name = name; }
    void setDescription(const std::string& desc) { this->description = desc; }
    void setPrice(double price) { this->price = price; }
    void setDurationMinutes(int duration) { this->durationMinutes = duration; }
    void setCategory(const std::string& cat) { this->category = cat; }

    // Методи
    void displayInfo() const;
    double calculateDiscountedPrice(double discountPercent) const;
};

#endif