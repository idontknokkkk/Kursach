#include "Appointment.hpp"
#include "Client.hpp"
#include "Stylist.hpp"
#include "Service.hpp"
#include <iostream>
#include <algorithm>

Appointment::Appointment(const std::string& appointmentId,
    std::shared_ptr<Client> client,
    std::shared_ptr<Stylist> stylist,
    const std::string& dateTime)
    : appointmentId(appointmentId), client(client), stylist(stylist),
    dateTime(dateTime), status(AppointmentStatus::SCHEDULED), totalPrice(0.0) {
}

void Appointment::addService(std::shared_ptr<Service> service) {
    if (service) {
        services.push_back(service);
        calculateTotalPrice();
    }
}

void Appointment::removeService(const std::string& serviceId) {
    services.erase(
        std::remove_if(services.begin(), services.end(),
            [&serviceId](const std::shared_ptr<Service>& service) {
                return service && service->getServiceId() == serviceId;
            }),
        services.end()
    );
    calculateTotalPrice();
}

void Appointment::calculateTotalPrice() {
    totalPrice = 0.0;
    for (const auto& service : services) {
        if (service) {
            totalPrice += service->getPrice();
        }
    }

    // VIP discount 10%
    if (client && client->getIsVip()) {
        totalPrice *= 0.9;
    }
}

std::string Appointment::getStatusString() const {
    switch (status) {
    case AppointmentStatus::SCHEDULED: return "Scheduled";
    case AppointmentStatus::IN_PROGRESS: return "In Progress";
    case AppointmentStatus::COMPLETED: return "Completed";
    case AppointmentStatus::CANCELLED: return "Cancelled";
    default: return "Unknown";
    }
}

void Appointment::displayInfo() const {
    std::cout << "=== APPOINTMENT INFORMATION ===" << std::endl;
    std::cout << "Appointment ID: " << appointmentId << std::endl;
    std::cout << "Date and Time: " << dateTime << std::endl;
    std::cout << "Status: " << getStatusString() << std::endl;

    if (client) {
        std::cout << "Client: " << client->getName() << " (ID: " << client->getClientId() << ")" << std::endl;
        std::cout << "VIP: " << (client->getIsVip() ? "Yes" : "No") << std::endl;
    }

    if (stylist) {
        std::cout << "Stylist: " << stylist->getName() << " (ID: " << stylist->getEmployeeId() << ")" << std::endl;
    }

    std::cout << "Services (" << services.size() << "):" << std::endl;
    for (const auto& service : services) {
        if (service) {
            std::cout << "  - " << service->getName() << " (" << service->getPrice() << " UAH)" << std::endl;
        }
    }

    std::cout << "Total Price: " << totalPrice << " UAH" << std::endl;
    if (!notes.empty()) {
        std::cout << "Notes: " << notes << std::endl;
    }
    std::cout << "============================" << std::endl;
}
