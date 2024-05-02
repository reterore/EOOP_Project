#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "Bike.h"

class Bike;

class Client {
private:
    char* name;
    char* clientID;
    char* rentalShopId; // Rental shop ID for the client
    Bike* bike;
    Client* next;

    friend class BikeRentalShop; // to access data from bikeRentalShop methods
    friend class Bike;

    Client() : name(NULL), clientID(NULL), rentalShopId(""), bike(NULL), next(NULL) {}
public:
    // Constructor to initialize a Client object with provided name and ID

    // Destructor to clean up resources associated with the Client object
    ~Client();

    // Method to print the details of the client
    void printClient() const;

    // Getter methods to retrieve information about the client
    const char* getName() const {return name;}
    const char* getClientID() const {return clientID;}
    const char* getRentalShopId() const {return rentalShopId;}

    bool isRentingABike();
};

#endif // CLIENT_H
