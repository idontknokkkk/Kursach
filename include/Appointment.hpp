#pragma once
#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include <string>
#include <vector>
#include <memory>

class Client;
class Stylist;
class Service;

enum class AppointmentStatus {
    SCHEDULED,
    IN_PROGRESS,
    COMPLETED,
    CANCELLED
};

class Appointment {
private:
    std::string appointmentId;
    std::shared_ptr<Client> client;
    std::shared_ptr<Stylist> stylist;
    std::vector<std::shared_ptr<Service>> services;
    std::string dateTime;
    AppointmentStatus status;
    std::string notes;
    double totalPrice;

public:
    Appointment(const std::string& appointmentId = "",
        std::shared_ptr<Client> client = nullptr,
        std::shared_ptr<Stylist> stylist = nullptr,
        const std::string& dateTime = "");

    // Getters
    std::string getAppointmentId() const { return appointmentId; }
    std::shared_ptr<Client> getClient() const { return client; }
    std::shared_ptr<Stylist> getStylist() const { return stylist; }
    const std::vector<std::shared_ptr<Service>>& getServices() const { return services; }
    std::string getDateTime() const { return dateTime; }
    AppointmentStatus getStatus() const { return status; }
    std::string getNotes() const { return notes; }
    double getTotalPrice() const { return totalPrice; }

    // Setters
    void setAppointmentId(const std::string& id) { this->appointmentId = id; }
    void setClient(std::shared_ptr<Client> client) { this->client = client; }
    void setStylist(std::shared_ptr<Stylist> stylist) { this->stylist = stylist; }
    void setDateTime(const std::string& dateTime) { this->dateTime = dateTime; }
    void setStatus(AppointmentStatus status) { this->status = status; }
    void setNotes(const std::string& notes) { this->notes = notes; }

    // Методи
    void addService(std::shared_ptr<Service> service);
    void removeService(const std::string& serviceId);
    void calculateTotalPrice();
    std::string getStatusString() const;
    void displayInfo() const;
};

#endif