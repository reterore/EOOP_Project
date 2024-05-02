#ifndef BIKE_H
#define BIKE_H

#include "Client.h"
#include <iostream>
using namespace std;

class Client;

class Bike {
private:
    char* model;
    char* id;
    int dailyRentalPrice;
    char* rentalShopId;
    Client* user;
    Bike* next;

    friend class BikeRentalShop; // to access data from bikeRentalShop methods

    Bike() : model(NULL), id(NULL), dailyRentalPrice(0), rentalShopId(NULL), user(NULL), next(NULL) {}
public:
    // Destructor to clean up resources associated with the Bike object
    ~Bike();

    // Method to print the details of the bike
    void printBike() const;

    // Getters to retrieve information about the bike
    const char* getModel() const { return model; }
    const char* getBikeId() const { return id; }
    int getDailyRentalPrice() const { return dailyRentalPrice; }
    const char* getRentalShopId() const { return rentalShopId; }
    bool isBeingRented();
};

#endif // BIKE_H
