#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include "Salon.hpp"
#include "Client.hpp"
#include "Employee.hpp"
#include "Stylist.hpp"
#include "Service.hpp"
#include "Appointment.hpp"

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseConsole() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void displayMainMenu() {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "        SALON MANAGEMENT SYSTEM           " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << " 1. Manage clients                        " << std::endl;
    std::cout << " 2. Manage employees                      " << std::endl;
    std::cout << " 3. Manage services                       " << std::endl;
    std::cout << " 4. Manage appointments                   " << std::endl;
    std::cout << " 5. Salon statistics                      " << std::endl;
    std::cout << " 6. Salon information                     " << std::endl;
    std::cout << " 0. Exit                                 " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Select option: ";
}

void displayClientsMenu() {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "           CLIENT MANAGEMENT              " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << " 1. Add client                           " << std::endl;
    std::cout << " 2. Show all clients                     " << std::endl;
    std::cout << " 3. Find client by ID                    " << std::endl;
    std::cout << " 4. Find client by phone                 " << std::endl;
    std::cout << " 5. Remove client                        " << std::endl;
    std::cout << " 0. Return to main menu                  " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Select option: ";
}

void displayEmployeesMenu() {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "          EMPLOYEE MANAGEMENT             " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << " 1. Add employee                        " << std::endl;
    std::cout << " 2. Add stylist                         " << std::endl;
    std::cout << " 3. Show all employees                  " << std::endl;
    std::cout << " 4. Show all stylists                   " << std::endl;
    std::cout << " 5. Find employee by ID                 " << std::endl;
    std::cout << " 6. Remove employee                     " << std::endl;
    std::cout << " 0. Return to main menu                 " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Select option: ";
}

void displayServicesMenu() {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "           SERVICE MANAGEMENT             " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << " 1. Add service                        " << std::endl;
    std::cout << " 2. Show all services                  " << std::endl;
    std::cout << " 3. Show services by category          " << std::endl;
    std::cout << " 4. Find service by name               " << std::endl;
    std::cout << " 5. Remove service                     " << std::endl;
    std::cout << " 0. Return to main menu                " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Select option: ";
}

void displayAppointmentsMenu() {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "          APPOINTMENT MANAGEMENT          " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << " 1. Create appointment                 " << std::endl;
    std::cout << " 2. Show all appointments              " << std::endl;
    std::cout << " 3. Client appointments                " << std::endl;
    std::cout << " 4. Stylist appointments               " << std::endl;
    std::cout << " 5. Cancel appointment                 " << std::endl;
    std::cout << " 0. Return to main menu                " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Select option: ";
}


void handleClientsMenu(Salon& salon) {
    int choice;
    do {
        clearConsole();
        displayClientsMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string name, phone;
            int age;
            bool isVip;

            std::cout << "Client name: ";
            std::getline(std::cin, name);
            std::cout << "Phone: ";
            std::getline(std::cin, phone);
            std::cout << "Age: ";
            std::cin >> age;
            std::cout << "VIP status (1 - yes, 0 - no): ";
            std::cin >> isVip;

            auto client = salon.addClient(name, phone, age, isVip);
            if (client) {
                std::cout << "Client added successfully! ID: " << client->getClientId() << std::endl;
            }
            pauseConsole();
            break;
        }
        case 2:
            salon.displayAllClients();
            pauseConsole();
            break;
        case 3: {
            std::string clientId;
            std::cout << "Enter client ID: ";
            std::getline(std::cin, clientId);
            auto client = salon.findClientById(clientId);
            if (client) {
                client->displayInfo();
            }
            else {
                std::cout << "Client with ID " << clientId << " not found." << std::endl;
            }
            pauseConsole();
            break;
        }
        case 4: {
            std::string phone;
            std::cout << "Enter client phone: ";
            std::getline(std::cin, phone);
            auto client = salon.findClientByPhone(phone);
            if (client) {
                client->displayInfo();
            }
            else {
                std::cout << "Client with phone " << phone << " not found." << std::endl;
            }
            pauseConsole();
            break;
        }
        case 5: {
            std::string clientId;
            std::cout << "Enter client ID to remove: ";
            std::getline(std::cin, clientId);
            if (salon.removeClient(clientId)) {
                std::cout << "Client removed successfully!" << std::endl;
            }
            else {
                std::cout << "Client not found." << std::endl;
            }
            pauseConsole();
            break;
        }
        }
    } while (choice != 0);
}

void handleEmployeesMenu(Salon& salon) {
    int choice;
    do {
        clearConsole();
        displayEmployeesMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string name, phone, position;
            int age;
            double salary;

            std::cout << "Employee name: ";
            std::getline(std::cin, name);
            std::cout << "Phone: ";
            std::getline(std::cin, phone);
            std::cout << "Age: ";
            std::cin >> age;
            std::cin.ignore();
            std::cout << "Position: ";
            std::getline(std::cin, position);
            std::cout << "Salary: ";
            std::cin >> salary;

            auto employee = salon.addEmployee(name, phone, age, position, salary);
            if (employee) {
                std::cout << "Employee added successfully! ID: " << employee->getEmployeeId() << std::endl;
            }
            pauseConsole();
            break;
        }
        case 2: {
            std::string name, phone;
            int age, experience;
            double salary;

            std::cout << "Stylist name: ";
            std::getline(std::cin, name);
            std::cout << "Phone: ";
            std::getline(std::cin, phone);
            std::cout << "Age: ";
            std::cin >> age;
            std::cout << "Salary: ";
            std::cin >> salary;
            std::cout << "Experience (years): ";
            std::cin >> experience;

            auto stylist = salon.addStylist(name, phone, age, salary, experience);
            if (stylist) {
                std::cout << "Stylist added successfully! ID: " << stylist->getEmployeeId() << std::endl;

                // Adding specializations
                std::string spec;
                std::cin.ignore();
                std::cout << "Add specializations (empty line to finish):" << std::endl;
                while (true) {
                    std::cout << "Specialization: ";
                    std::getline(std::cin, spec);
                    if (spec.empty()) break;
                    stylist->addSpecialization(spec);
                }
            }
            pauseConsole();
            break;
        }
        case 3:
            salon.displayAllEmployees();
            pauseConsole();
            break;
        case 4:
            salon.displayAllStylists();
            pauseConsole();
            break;
        case 5: {
            std::string employeeId;
            std::cout << "Enter employee ID: ";
            std::getline(std::cin, employeeId);
            auto employee = salon.findEmployeeById(employeeId);
            if (employee) {
                employee->displayInfo();
            }
            else {
                std::cout << "Employee with ID " << employeeId << " not found." << std::endl;
            }
            pauseConsole();
            break;
        }
        case 6: {
            std::string employeeId;
            std::cout << "Enter employee ID to remove: ";
            std::getline(std::cin, employeeId);
            if (salon.removeEmployee(employeeId)) {
                std::cout << "Employee removed successfully!" << std::endl;
            }
            else {
                std::cout << "Employee not found." << std::endl;
            }
            pauseConsole();
            break;
        }
        }
    } while (choice != 0);
}

void handleServicesMenu(Salon& salon) {
    int choice;
    do {
        clearConsole();
        displayServicesMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string name, description, category;
            double price;
            int duration;

            std::cout << "Service name: ";
            std::getline(std::cin, name);
            std::cout << "Description: ";
            std::getline(std::cin, description);
            std::cout << "Price: ";
            std::cin >> price;
            std::cout << "Duration (minutes): ";
            std::cin >> duration;
            std::cin.ignore();
            std::cout << "Category: ";
            std::getline(std::cin, category);

            auto service = salon.addService(name, description, price, duration, category);
            if (service) {
                std::cout << "Service added successfully! ID: " << service->getServiceId() << std::endl;
            }
            pauseConsole();
            break;
        }
        case 2:
            salon.displayAllServices();
            pauseConsole();
            break;
        case 3: {
            std::string category;
            std::cout << "Enter category: ";
            std::getline(std::cin, category);
            salon.displayServicesByCategory(category);
            pauseConsole();
            break;
        }
        case 4: {
            std::string name;
            std::cout << "Enter service name: ";
            std::getline(std::cin, name);
            auto service = salon.findServiceByName(name);
            if (service) {
                service->displayInfo();
            }
            else {
                std::cout << "Service with name '" << name << "' not found." << std::endl;
            }
            pauseConsole();
            break;
        }
        case 5: {
            std::string serviceId;
            std::cout << "Enter service ID to remove: ";
            std::getline(std::cin, serviceId);
            if (salon.removeService(serviceId)) {
                std::cout << "Service removed successfully!" << std::endl;
            }
            else {
                std::cout << "Service not found." << std::endl;
            }
            pauseConsole();
            break;
        }
        }
    } while (choice != 0);
}

void handleAppointmentsMenu(Salon& salon) {
    int choice;
    do {
        clearConsole();
        displayAppointmentsMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string clientId, stylistId, serviceId, dateTime;

            std::cout << "Client ID: ";
            std::getline(std::cin, clientId);
            std::cout << "Stylist ID: ";
            std::getline(std::cin, stylistId);
            std::cout << "Date and time (DD.MM.YYYY HH:MM): ";
            std::getline(std::cin, dateTime);

            auto appointment = salon.createAppointment(clientId, stylistId, dateTime);
            if (appointment) {
                std::cout << "Appointment created successfully! ID: " << appointment->getAppointmentId() << std::endl;
            }
            else {
                std::cout << "Error creating appointment. Please check the entered data." << std::endl;
            }
            pauseConsole();
            break;
        }
        case 2:
            salon.displayAllAppointments();
            pauseConsole();
            break;
        case 3: {
            std::string clientId;
            std::cout << "Enter client ID: ";
            std::getline(std::cin, clientId);
            salon.displayAppointmentsByClient(clientId);
            pauseConsole();
            break;
        }
        case 4: {
            std::string stylistId;
            std::cout << "Enter stylist ID: ";
            std::getline(std::cin, stylistId);
            salon.displayAppointmentsByStylist(stylistId);
            pauseConsole();
            break;
        }
        case 5: {
            std::string appointmentId;
            std::cout << "Enter appointment ID to cancel: ";
            std::getline(std::cin, appointmentId);
            if (salon.cancelAppointment(appointmentId)) {
                std::cout << "Appointment cancelled successfully!" << std::endl;
            }
            else {
                std::cout << "Appointment not found." << std::endl;
            }
            pauseConsole();
            break;
        }
        }
    } while (choice != 0);
}

void displaySalonInfo(Salon& salon) {
    clearConsole();
    salon.displaySalonInfo();
}

int main() {

    // Creating salon object
    Salon salon("Beauty Salon 'Elegance'", "15 Shevchenko Street", "+380671234567");

    int choice;

    std::cout << "Welcome to the salon management system!" << std::endl;

    do {
        clearConsole();
        displayMainMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            handleClientsMenu(salon);
            break;
        case 2:
            handleEmployeesMenu(salon);
            break;
        case 3:
            handleServicesMenu(salon);
            break;
        case 4:
            handleAppointmentsMenu(salon);
            break;
        case 5:
            salon.displaySalonStatistics();
            pauseConsole();
            break;
        case 6:
            displaySalonInfo(salon);
            pauseConsole();
            break;
        case 0:
            std::cout << "Thank you for using the salon management system!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            pauseConsole();
            break;
        }
    } while (choice != 0);

    return 0;
}