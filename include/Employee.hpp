#pragma once
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Person.hpp"
#include <vector>
#include <string>

class Employee : public Person {
protected:
    std::string employeeId;
    std::string position;
    double salary;
    std::vector<std::string> schedule;
    bool isAvailable;

public:
    Employee(const std::string& name = "", const std::string& phone = "",
        int age = 0, const std::string& employeeId = "",
        const std::string& position = "", double salary = 0.0);

    // Getters
    std::string getEmployeeId() const { return employeeId; }
    std::string getPosition() const { return position; }
    double getSalary() const { return salary; }
    bool getAvailability() const { return isAvailable; }
    const std::vector<std::string>& getSchedule() const { return schedule; }

    // Setters
    void setEmployeeId(const std::string& id) { this->employeeId = id; }
    void setPosition(const std::string& pos) { this->position = pos; }
    void setSalary(double sal) { this->salary = sal; }
    void setAvailability(bool available) { this->isAvailable = available; }

    // Методи
    void addScheduleSlot(const std::string& timeSlot);
    void clearSchedule();

    // Віртуальні методи
    virtual double calculateBonus() const { return salary * 0.1; }

    // Перевизначені віртуальні методи
    void displayInfo() const override;
    std::string getType() const override { return "Employee"; }
};

#endif