#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include "Client.h"

class Bike {
private:
    char* model;
    char* id;
    int dailyRentalPrice;
    char* rentalShopId;

    friend class BikeRentalShop; // to access data from bikeRentalShop methods

public:
    // Constructor to initialize a Bike object with provided parameters
    Bike(const char* model, const char* id, int dailyRentalPrice);

    // Destructor to clean up resources associated with the Bike object
    ~Bike();

    // Method to print the details of the bike
    void printBike() const;

    // Getters to retrieve information about the bike
    const char* getModel() const { return model; }
    const char* getBikeId() const { return id; }
    int getDailyRentalPrice() const { return dailyRentalPrice; }
    const char* getRentalShopId() const { return rentalShopId; }

};

#endif // BIKE_H
