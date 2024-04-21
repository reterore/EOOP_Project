#ifndef EOOP_PROJECT_BIKERENTALSHOP_H
#define EOOP_PROJECT_BIKERENTALSHOP_H

#include "Client.h"
#include "Employee.h"
#include "Bike.h"

class BikeRentalShop {
private:
    char* id;
    // Node structure to handle clients
    struct clientNode{
        Client* client;
        Bike* bike;
        clientNode* next;
    };
    clientNode* HeadClient;
    // Node structure to handle employees
    struct employeeNode{
        Employee* employee;
        employeeNode* next;
    };
    employeeNode* HeadEmployee;
    // Node structure to handle bikes
    struct bikeNode{
        Bike* bike;
        Client* user;
        bikeNode* next;
    };
    bikeNode* HeadBike;

public:
    // Constructor to initialize a BikeRentalShop object with provided shop ID
    BikeRentalShop(const char* shopId);

    // Destructor to clean up resources associated with the BikeRentalShop object
    ~BikeRentalShop();

    // Method to print details of the bike rental shop
    void print() const;

    // Getter method to retrieve the ID of the bike rental shop
    const char* getId() const { return id;}

    // Methods to insert a client, employee, or bike into the shop
    bool insert(Client* client);
    bool insert(Employee* employee);
    bool insert(Bike* bike);

    // Method to rent a bike to a client
    bool rent(Client* client, Bike* bike);

    // Method to stop rental of a bike by a client
    bool stopRental(Client* client);

    // Method to stop rental of a bike
    bool stopRental(Bike* bike);

    // Methods to remove a client, employee, or bike from the shop
    bool remove(Client* client);
    bool remove(Employee* employee);
    bool remove(Bike* bike);
};

#endif // EOOP_PROJECT_BIKERENTALSHOP_H
