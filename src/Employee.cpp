#include "Employee.hpp"
#include <iostream>

Employee::Employee(const std::string& name, const std::string& phone, int age,
    const std::string& employeeId, const std::string& position, double salary)
    : Person(name, phone, age), employeeId(employeeId), position(position),
    salary(salary), isAvailable(true) {
}

void Employee::addScheduleSlot(const std::string& timeSlot) {
    schedule.push_back(timeSlot);
}

void Employee::clearSchedule() {
    schedule.clear();
}

void Employee::displayInfo() const {
    std::cout << "=== EMPLOYEE INFORMATION ===" << std::endl;
    std::cout << "ID: " << employeeId << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Position: " << position << std::endl;
    std::cout << "Salary: " << salary << " UAH" << std::endl;
    std::cout << "Available: " << (isAvailable ? "Yes" : "No") << std::endl;
    std::cout << "Bonus: " << calculateBonus() << " UAH" << std::endl;
    std::cout << "Schedule (" << schedule.size() << " slots):" << std::endl;
    for (const auto& slot : schedule) {
        std::cout << "  - " << slot << std::endl;
    }
    std::cout << "===================================" << std::endl;
}
