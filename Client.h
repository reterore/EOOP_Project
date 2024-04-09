#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>

using namespace std;

class Bike;
class BikeRentalShop;

class Client {
private:
    string name;
    string clientID;
    string rentalShopId;
public:
    Client(const string& n, const string& id); // Ajout du pointeur vers le magasin
    ~Client();
    void setRentalShopId(const string& id);
    void printClient() const;
    const string& getName() const;
    const string& getClientID() const;
    const string& getRentalShopId() const;
};

#endif // CLIENT_H
