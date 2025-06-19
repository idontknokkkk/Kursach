#pragma once
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Person.hpp"
#include <vector>
#include <string>

class Client : public Person {
private:
    std::string clientId;
    std::vector<std::string> visitHistory;
    bool isVip;
    std::string preferredStylust;

public:
    Client(const std::string& name = "", const std::string& phone = "",
        int age = 0, const std::string& clientId = "", bool isVip = false);

    // Getters
    std::string getClientId() const { return clientId; }
    bool getIsVip() const { return isVip; }
    std::string getPreferredStylist() const { return preferredStylust; }
    const std::vector<std::string>& getVisitHistory() const { return visitHistory; }

    // Setters
    void setClientId(const std::string& id) { this->clientId = id; }
    void setVip(bool vip) { this->isVip = vip; }
    void setPreferredStylist(const std::string& stylist) { this->preferredStylust = stylist; }

    // Методи
    void addVisit(const std::string& visitDetails);

    // Перевизначені віртуальні методи
    void displayInfo() const override;
    std::string getType() const override { return "Client"; }
};

#endif