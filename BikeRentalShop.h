#ifndef EOOP_PROJECT_BIKERENTALSHOP_H
#define EOOP_PROJECT_BIKERENTALSHOP_H

#include "Client.h"
#include "Employee.h"
#include "Bike.h"
#include <iostream>
#include <cstring>

using namespace std;

class BikeRentalShop {
private:
    char* id;
    Client* HeadClient;
    Employee* HeadEmployee;
    Bike* HeadBike;
    BikeRentalShop* next;

    friend class Employee;
    friend class Client;
    friend class Bike;
    friend class BikeRentalCompany;

    BikeRentalShop() : id(NULL), HeadBike(NULL), HeadClient(NULL), HeadEmployee(NULL) {}

public:
    // Destructor to clean up resources associated with the BikeRentalShop object
    ~BikeRentalShop();

    // Method to print details of the bike rental shop
    void print() const;

    // Getter method to retrieve the ID of the bike rental shop
    const char* getId() const { return id; }

    // Methods to insert a client, employee, or bike into the shop
    bool insertClient(char* name, char* Id);
    bool insertEmployee(char* name, char* Id);
    bool insertBike(char* model, char* Id, int dailyRentalprice);

    // Method to rent a bike to a client
    bool rent(char* clientId, char* bikeId);

    // Method to stop rental of a bike by a client
    bool stopRentalClient(char* clientId);

    // Method to stop rental of a bike
    bool stopRentalBike(char* bikeId);

    // Methods to remove a client, employee, or bike from the shop
    bool removeClient(char* Id);
    bool removeEmployee(char* Id);
    bool removeBike(char* Id);

    void clear();
};

#endif // EOOP_PROJECT_BIKERENTALSHOP_H
