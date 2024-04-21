#ifndef EOOP_PROJECT_BIKERENTALCOMPANY_H
#define EOOP_PROJECT_BIKERENTALCOMPANY_H

#include "BikeRentalShop.h"
#include "cstring"

class BikeRentalCompany {
private:
    struct shopNode {
        BikeRentalShop *shop;
        shopNode *next;
    };
    int numberOfShops;
    shopNode *head;
public:
    // Constructor
    BikeRentalCompany();

    // Destructor
    ~BikeRentalCompany();

    // Print method to display information about all shops in the company
    void print();

    // Method to insert a new bike rental shop into the company
    bool insertShop(BikeRentalShop *bikeRentalShop);

    // Method to remove a bike rental shop from the company
    bool removeShop(BikeRentalShop *bikeRentalShop);

    // Method to remove a bike rental shop from the company by its ID
    bool removeShop(const string &shopId);

    // Method to insert a new client, employee, or bike into a specific shop
    bool insert(string shopId, Client* client);
    bool insert(string shopId, Employee* employee);
    bool insert(string shopId, Bike* bike);

    // Method to rent a bike for a client from a specific shop
    bool rent(string shopId, Client* client, Bike* bike);

    // Method to stop rental of a bike by a client at a specific shop
    bool stopRental(string shopId, Client* client);

    // Method to stop rental of a bike at a specific shop
    bool stopRental(string shopId, Bike* bike);

    // Method to remove a client, employee, or bike from a specific shop
    bool remove(string shopId, Client* client);
    bool remove(string shopId, Employee* employee);
    bool remove(string shopId, Bike* bike);
};
#endif //EOOP_PROJECT_BIKERENTALCOMPANY_H
