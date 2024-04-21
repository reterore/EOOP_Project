#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

using namespace std;

class Bike; // Forward declaration of the Bike class
class BikeRentalShop; // Forward declaration of the BikeRentalShop class

class Client {
private:
    char* name;
    char* clientID;
    char* rentalShopId; // Rental shop ID for the client

    friend class BikeRentalShop; // to access data from bikeRentalShop methods

public:
    // Constructor to initialize a Client object with provided name and ID
    Client(const char* name, const char* id);

    // Destructor to clean up resources associated with the Client object
    ~Client();

    // Method to print the details of the client
    void printClient() const;

    // Getter methods to retrieve information about the client
    const char* getName() const {return name;}
    const char* getClientID() const {return clientID;}
    const char* getRentalShopId() const {return rentalShopId;}
};

#endif // CLIENT_H
