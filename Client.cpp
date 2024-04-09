#include "Client.h"
#include <iostream>

Client::Client(const string& n, const string& id) : name(n), clientID(id), rentalShopId("") {}

Client::~Client() {
    cout << "Client " << name << " (ID:" << clientID << ") destroyed!\n";
}

void Client::printClient() const {
    cout << "- (ID:" << clientID << ") | name: " << name << endl;
    cout << "  Rental shop ID: " << rentalShopId << endl;
}

void Client::setRentalShopId(const string& id) {
    rentalShopId = id;
}

const string& Client::getName() const {
    return name;
}

const string& Client::getClientID() const {
    return clientID;
}

const string& Client::getRentalShopId() const {
    return rentalShopId;
}
