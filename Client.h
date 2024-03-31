#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>

using namespace std;

class Bike;
class BikeRentalShop; // Forward declaration

class Client {
private:
    string name;
    string clientID;
    Bike* rentedBike;
    Client* next;
    BikeRentalShop* rentalShop; // Nouveau membre pour stocker le magasin associé

public:
    Client(const string& n, const string& id); // Ajout du pointeur vers le magasin
    ~Client();

    void printClient() const;

    const string& getName() const;
    const string& getClientID() const;
    Bike* getBike() const;
    Client*& getNextClient();
    void changeBike(Bike* rentedBike);
    void setRentalShop(BikeRentalShop* shop);
    // Ajoutez une fonction pour obtenir le magasin associé
    BikeRentalShop* getRentalShop() const;
};

#endif // CLIENT_H
