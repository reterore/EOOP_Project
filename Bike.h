#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string>
#include "Client.h"

class Bike {
private:
    string model;
    string id;
    int dailyRentalPrice;
    string rentalShopId;

public:
    // Constructeur
    Bike(const string& model, const string& id, int dailyRentalPrice);

    // Destructeur
    ~Bike();

    // Méthode pour afficher les détails du vélo
    void printBike() const;

    // Getters
    const string& getModel() const { return model; }
    const string& getBikeId() const { return id; }
    int getDailyRentalPrice() const { return dailyRentalPrice; }
    const string& getRentalShopId() const { return rentalShopId; }
    void setRentalShopId(const string& id);
};

#endif // BIKE_H
