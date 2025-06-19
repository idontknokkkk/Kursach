#pragma once
#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
    std::string phone;
    int age;

public:
    Person(const std::string& name = "", const std::string& phone = "", int age = 0);
    virtual ~Person() = default;

    // Getters
    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
    int getAge() const { return age; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setPhone(const std::string& phone) { this->phone = phone; }
    void setAge(int age) { this->age = age; }

    // Віртуальні методи для поліморфізму
    virtual void displayInfo() const = 0;
    virtual std::string getType() const = 0;
};

#endif