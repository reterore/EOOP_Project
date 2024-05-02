#ifndef EOOP_PROJECT_BIKERENTALCOMPANY_H
#define EOOP_PROJECT_BIKERENTALCOMPANY_H

#include "BikeRentalShop.h"

class BikeRentalCompany {
private:
    int numberOfShops;
    BikeRentalShop* head;

public:
    // Constructor
    BikeRentalCompany();

    // Destructor
    ~BikeRentalCompany();

    // Print method to display information about all shops in the company
    void print();

    // Method to insert a new bike rental shop into the company
    bool insertShop(char* Id);

    // Method to remove a bike rental shop from the company by its ID
    bool removeShop(char* Id);

    // Method to insert a new client, employee, or bike into a specific shop
    bool insertClient(char* shopId, char* name, char* Id);
    bool insertEmployee(char* shopId, char* name, char* Id);
    bool insertBike(char* shopId, char* model, char* Id, int dailyRentalPrice);

    // Method to rent a bike for a client from a specific shop
    bool rent(char* shopId, char* clientId, char* bikeId);

    // Method to stop rental of a bike by a client at a specific shop
    bool stopRentalClient(char* shopId, char* clientId);

    // Method to stop rental of a bike at a specific shop
    bool stopRentalBike(char* shopId, char* bikeId);

    // Method to remove a client, employee, or bike from a specific shop
    bool removeClient(char* shopId, char* clientId);
    bool removeEmployee(char* shopId, char* employeeId);
    bool removeBike(char* shopId, char* bikeId);
    void clear();
};
#endif //EOOP_PROJECT_BIKERENTALCOMPANY_H
