#include "Salon.hpp"
#include "Client.hpp"
#include "Employee.hpp"
#include "Stylist.hpp"
#include "Service.hpp"
#include "Appointment.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

int Salon::nextClientId = 1;
int Salon::nextEmployeeId = 1;
int Salon::nextServiceId = 1;
int Salon::nextAppointmentId = 1;

Salon::Salon(const std::string& name, const std::string& address, const std::string& phone)
    : salonName(name), address(address), phone(phone) {
}

// Client management
std::shared_ptr<Client> Salon::addClient(const std::string& name, const std::string& phone, int age, bool isVip) {
    std::string clientId = "C" + std::to_string(nextClientId++);
    auto client = std::make_shared<Client>(name, phone, age, clientId, isVip);
    clients.push_back(client);
    return client;
}

std::shared_ptr<Client> Salon::findClientById(const std::string& clientId) const {
    auto it = std::find_if(clients.begin(), clients.end(),
        [&clientId](const std::shared_ptr<Client>& client) {
            return client && client->getClientId() == clientId;
        });
    return (it != clients.end()) ? *it : nullptr;
}

std::shared_ptr<Client> Salon::findClientByPhone(const std::string& phone) const {
    auto it = std::find_if(clients.begin(), clients.end(),
        [&phone](const std::shared_ptr<Client>& client) {
            return client && client->getPhone() == phone;
        });
    return (it != clients.end()) ? *it : nullptr;
}

void Salon::displayAllClients() const {
    std::cout << "\n=== SALON CLIENT LIST ===" << std::endl;
    if (clients.empty()) {
        std::cout << "No clients found." << std::endl;
    }
    else {
        for (const auto& client : clients) {
            if (client) {
                client->displayInfo();
                std::cout << std::endl;
            }
        }
    }
    std::cout << "Total clients: " << clients.size() << std::endl;
}

bool Salon::removeClient(const std::string& clientId) {
    auto it = std::find_if(clients.begin(), clients.end(),
        [&clientId](const std::shared_ptr<Client>& client) {
            return client && client->getClientId() == clientId;
        });

    if (it != clients.end()) {
        clients.erase(it);
        return true;
    }
    return false;
}

// Employee management
std::shared_ptr<Employee> Salon::addEmployee(const std::string& name, const std::string& phone,
    int age, const std::string& position, double salary) {
    std::string employeeId = "E" + std::to_string(nextEmployeeId++);
    auto employee = std::make_shared<Employee>(name, phone, age, employeeId, position, salary);
    employees.push_back(employee);
    return employee;
}

std::shared_ptr<Stylist> Salon::addStylist(const std::string& name, const std::string& phone,
    int age, double salary, int experienceYears) {
    std::string employeeId = "S" + std::to_string(nextEmployeeId++);
    auto stylist = std::make_shared<Stylist>(name, phone, age, employeeId, salary, experienceYears);
    employees.push_back(stylist);
    return stylist;
}

std::shared_ptr<Employee> Salon::findEmployeeById(const std::string& employeeId) const {
    auto it = std::find_if(employees.begin(), employees.end(),
        [&employeeId](const std::shared_ptr<Employee>& employee) {
            return employee && employee->getEmployeeId() == employeeId;
        });
    return (it != employees.end()) ? *it : nullptr;
}

std::shared_ptr<Stylist> Salon::findStylistById(const std::string& employeeId) const {
    auto employee = findEmployeeById(employeeId);
    return std::dynamic_pointer_cast<Stylist>(employee);
}

void Salon::displayAllEmployees() const {
    std::cout << "\n=== SALON EMPLOYEE LIST ===" << std::endl;
    if (employees.empty()) {
        std::cout << "No employees found." << std::endl;
    }
    else {
        for (const auto& employee : employees) {
            if (employee) {
                employee->displayInfo();
                std::cout << std::endl;
            }
        }
    }
    std::cout << "Total employees: " << employees.size() << std::endl;
}

void Salon::displayAllStylists() const {
    std::cout << "\n=== SALON STYLIST LIST ===" << std::endl;
    int stylistCount = 0;
    for (const auto& employee : employees) {
        auto stylist = std::dynamic_pointer_cast<Stylist>(employee);
        if (stylist) {
            stylist->displayInfo();
            std::cout << std::endl;
            stylistCount++;
        }
    }
    if (stylistCount == 0) {
        std::cout << "No stylists found." << std::endl;
    }
    std::cout << "Total stylists: " << stylistCount << std::endl;
}

bool Salon::removeEmployee(const std::string& employeeId) {
    auto it = std::find_if(employees.begin(), employees.end(),
        [&employeeId](const std::shared_ptr<Employee>& employee) {
            return employee && employee->getEmployeeId() == employeeId;
        });

    if (it != employees.end()) {
        employees.erase(it);
        return true;
    }
    return false;
}

// Service management
std::shared_ptr<Service> Salon::addService(const std::string& name, const std::string& description,
    double price, int durationMinutes, const std::string& category) {
    std::string serviceId = "SRV" + std::to_string(nextServiceId++);
    auto service = std::make_shared<Service>(serviceId, name, description, price, durationMinutes, category);
    services.push_back(service);
    return service;
}

std::shared_ptr<Service> Salon::findServiceById(const std::string& serviceId) const {
    auto it = std::find_if(services.begin(), services.end(),
        [&serviceId](const std::shared_ptr<Service>& service) {
            return service && service->getServiceId() == serviceId;
        });
    return (it != services.end()) ? *it : nullptr;
}

std::shared_ptr<Service> Salon::findServiceByName(const std::string& name) const {
    auto it = std::find_if(services.begin(), services.end(),
        [&name](const std::shared_ptr<Service>& service) {
            return service && service->getName() == name;
        });
    return (it != services.end()) ? *it : nullptr;
}

void Salon::displayAllServices() const {
    std::cout << "\n=== SALON SERVICE LIST ===" << std::endl;
    if (services.empty()) {
        std::cout << "No services found." << std::endl;
    }
    else {
        for (const auto& service : services) {
            if (service) {
                service->displayInfo();
                std::cout << std::endl;
            }
        }
    }
    std::cout << "Total services: " << services.size() << std::endl;
}

void Salon::displayServicesByCategory(const std::string& category) const {
    std::cout << "\n=== SERVICES IN CATEGORY: " << category << " ===" << std::endl;
    int count = 0;
    for (const auto& service : services) {
        if (service && service->getCategory() == category) {
            service->displayInfo();
            std::cout << std::endl;
            count++;
        }
    }
    if (count == 0) {
        std::cout << "No services found in category '" << category << "'." << std::endl;
    }
    std::cout << "Services found: " << count << std::endl;
}

bool Salon::removeService(const std::string& serviceId) {
    auto it = std::find_if(services.begin(), services.end(),
        [&serviceId](const std::shared_ptr<Service>& service) {
            return service && service->getServiceId() == serviceId;
        });

    if (it != services.end()) {
        services.erase(it);
        return true;
    }
    return false;
}

// Appointment management
std::shared_ptr<Appointment> Salon::createAppointment(const std::string& clientId, const std::string& stylistId,
    const std::string& dateTime) {
    auto client = findClientById(clientId);
    auto stylist = findStylistById(stylistId);

    if (!client || !stylist) {
        return nullptr;
    }

    std::string appointmentId = "APT" + std::to_string(nextAppointmentId++);
    auto appointment = std::make_shared<Appointment>(appointmentId, client, stylist, dateTime);
    appointments.push_back(appointment);

    return appointment;
}

std::shared_ptr<Appointment> Salon::findAppointmentById(const std::string& appointmentId) const {
    auto it = std::find_if(appointments.begin(), appointments.end(),
        [&appointmentId](const std::shared_ptr<Appointment>& appointment) {
            return appointment && appointment->getAppointmentId() == appointmentId;
        });
    return (it != appointments.end()) ? *it : nullptr;
}

void Salon::displayAllAppointments() const {
    std::cout << "\n=== SALON APPOINTMENT LIST ===" << std::endl;
    if (appointments.empty()) {
        std::cout << "No appointments found." << std::endl;
    }
    else {
        for (const auto& appointment : appointments) {
            if (appointment) {
                appointment->displayInfo();
                std::cout << std::endl;
            }
        }
    }
    std::cout << "Total appointments: " << appointments.size() << std::endl;
}

void Salon::displayAppointmentsByClient(const std::string& clientId) const {
    std::cout << "\n=== APPOINTMENTS OF CLIENT " << clientId << " ===" << std::endl;
    int count = 0;
    for (const auto& appointment : appointments) {
        if (appointment && appointment->getClient() &&
            appointment->getClient()->getClientId() == clientId) {
            appointment->displayInfo();
            std::cout << std::endl;
            count++;
        }
    }
    if (count == 0) {
        std::cout << "No appointments found for client." << std::endl;
    }
    std::cout << "Appointments found: " << count << std::endl;
}

void Salon::displayAppointmentsByStylist(const std::string& stylistId) const {
    std::cout << "\n=== APPOINTMENTS OF STYLIST " << stylistId << " ===" << std::endl;
    int count = 0;
    for (const auto& appointment : appointments) {
        if (appointment && appointment->getStylist() &&
            appointment->getStylist()->getEmployeeId() == stylistId) {
            appointment->displayInfo();
            std::cout << std::endl;
            count++;
        }
    }
    if (count == 0) {
        std::cout << "No appointments found for stylist." << std::endl;
    }
    std::cout << "Appointments found: " << count << std::endl;
}

bool Salon::cancelAppointment(const std::string& appointmentId) {
    auto appointment = findAppointmentById(appointmentId);
    if (appointment) {
        appointment->setStatus(AppointmentStatus::CANCELLED);
        return true;
    }
    return false;
}

// Statistics
void Salon::displaySalonStatistics() const {
    std::cout << "\n=== SALON STATISTICS ===" << std::endl;
    std::cout << "Salon name: " << salonName << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Clients: " << clients.size() << std::endl;
    std::cout << "Employees: " << employees.size() << std::endl;
    std::cout << "Services: " << services.size() << std::endl;
    std::cout << "Appointments: " << appointments.size() << std::endl;
    std::cout << "Total revenue: " << std::fixed << std::setprecision(2)
        << calculateTotalRevenue() << " UAH" << std::endl;
    std::cout << "=========================" << std::endl;
}

double Salon::calculateTotalRevenue() const {
    double totalRevenue = 0.0;
    for (const auto& appointment : appointments) {
        if (appointment && appointment->getStatus() == AppointmentStatus::COMPLETED) {
            totalRevenue += appointment->getTotalPrice();
        }
    }
    return totalRevenue;
}

std::map<std::string, int> Salon::getServiceStatistics() const {
    std::map<std::string, int> stats;
    for (const auto& appointment : appointments) {
        if (appointment && appointment->getStatus() == AppointmentStatus::COMPLETED) {
            for (const auto& service : appointment->getServices()) {
                if (service) {
                    stats[service->getName()]++;
                }
            }
        }
    }
    return stats;
}

void Salon::displaySalonInfo() const {
    std::cout << "\n=== SALON INFORMATION ===" << std::endl;
    std::cout << "🏢 Name: " << salonName << std::endl;
    std::cout << "📍 Address: " << address << std::endl;
    std::cout << "📞 Phone: " << phone << std::endl;
    std::cout << "============================" << std::endl;
}
