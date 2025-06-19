#pragma once
#ifndef SALON_HPP
#define SALON_HPP

#include <vector>
#include <memory>
#include <string>
#include <map>

class Client;
class Employee;
class Stylist;
class Service;
class Appointment;

class Salon {
private:
    std::string salonName;
    std::string address;
    std::string phone;
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Employee>> employees;
    std::vector<std::shared_ptr<Service>> services;
    std::vector<std::shared_ptr<Appointment>> appointments;
    static int nextClientId;
    static int nextEmployeeId;
    static int nextServiceId;
    static int nextAppointmentId;

public:
    Salon(const std::string& name = "", const std::string& address = "", const std::string& phone = "");

    // Getters
    std::string getSalonName() const { return salonName; }
    std::string getAddress() const { return address; }
    std::string getPhone() const { return phone; }

    // ��������� �볺�����
    std::shared_ptr<Client> addClient(const std::string& name, const std::string& phone, int age, bool isVip = false);
    std::shared_ptr<Client> findClientById(const std::string& clientId) const;
    std::shared_ptr<Client> findClientByPhone(const std::string& phone) const;
    void displayAllClients() const;
    bool removeClient(const std::string& clientId);

    // ��������� �������������
    std::shared_ptr<Employee> addEmployee(const std::string& name, const std::string& phone,
        int age, const std::string& position, double salary);
    std::shared_ptr<Stylist> addStylist(const std::string& name, const std::string& phone,
        int age, double salary, int experienceYears);
    std::shared_ptr<Employee> findEmployeeById(const std::string& employeeId) const;
    std::shared_ptr<Stylist> findStylistById(const std::string& employeeId) const;
    void displayAllEmployees() const;
    void displayAllStylists() const;
    bool removeEmployee(const std::string& employeeId);

    // ��������� ���������
    std::shared_ptr<Service> addService(const std::string& name, const std::string& description,
        double price, int durationMinutes, const std::string& category);
    std::shared_ptr<Service> findServiceById(const std::string& serviceId) const;
    std::shared_ptr<Service> findServiceByName(const std::string& name) const;
    void displayAllServices() const;
    void displayServicesByCategory(const std::string& category) const;
    bool removeService(const std::string& serviceId);

    // ��������� ��������
    std::shared_ptr<Appointment> createAppointment(const std::string& clientId, const std::string& stylistId,
        const std::string& dateTime);
    std::shared_ptr<Appointment> findAppointmentById(const std::string& appointmentId) const;
    void displayAllAppointments() const;
    void displayAppointmentsByClient(const std::string& clientId) const;
    void displayAppointmentsByStylist(const std::string& stylistId) const;
    bool cancelAppointment(const std::string& appointmentId);

    // ����������
    void displaySalonStatistics() const;
    double calculateTotalRevenue() const;
    std::map<std::string, int> getServiceStatistics() const;
    void displaySalonInfo() const;

 
};

#endif