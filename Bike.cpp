#include "Bike.h"

// Constructeur
Bike::Bike(const string& model, const string& id, int dailyRentalPrice) : model(model), id(id), dailyRentalPrice(dailyRentalPrice), nextBike(NULL), user(NULL), rentalShop(NULL) {}

Bike::~Bike() {
}

void Bike::printBike() const {
    cout << "Model: " << model;
    cout << " (ID:" << id << ")" << endl;
    cout << "Daily Rental Price: " << dailyRentalPrice << endl;
    if (user) {
        cout << "Currently rented by: " << user->getName() << endl;
    } else {
        cout << "Currently not rented" << endl;
    }
}

Bike*& Bike::getNextBike() {
    return nextBike;
}

Client* Bike::getUser() const {
    return user;
}

bool Bike::getRentalInfo() const {
    if (user){
        return true;
    } else {
        return false;
    }
}

BikeRentalShop* Bike::getRentalShop() const{
    return rentalShop;
}

void Bike::setRentalShop(BikeRentalShop* shop) {
    rentalShop = shop;
}

void Bike::changeUser(Client* client) {
    // On change simplement le pointeur vers le nouveau client
    user = client;
}
