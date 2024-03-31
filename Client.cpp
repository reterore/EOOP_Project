#include "Client.h"

Client::Client(const string& n, const string& id) : name(n), clientID(id), next(NULL), rentedBike(NULL), rentalShop(NULL) {}

Client::~Client() {
}

void Client::printClient() const {
    // You can print information about the client
    cout << "(ID:" << clientID << ") | name: " << name << endl;
    if (rentedBike == NULL) {
        cout << "No bike rented.";
    } else {
        cout << "A bike rented";
    }
    cout << endl;
}

const string& Client::getName() const {
    return name;
}

const string& Client::getClientID() const {
    return clientID;
}

Bike* Client::getBike() const {
    return rentedBike;
}

Client*& Client::getNextClient()  {
    return next;
}

void Client::setRentalShop(BikeRentalShop* shop) {
    rentalShop = shop;
}

BikeRentalShop* Client::getRentalShop() const {
    return rentalShop;
}

void Client::changeBike(Bike* rentedBike) {
    this->rentedBike = rentedBike;
}
