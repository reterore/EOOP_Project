#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string> // Inclure la bibliothèque pour les objets string
#include "Client.h" // Assurez-vous d'inclure le fichier d'en-tête de la classe Client si nécessaire

class Bike {
private:
    string model;
    string id;
    int dailyRentalPrice;
    string rentalShopId; // Utilisation d'un objet string pour rentalShopId

public:
    // Constructeur
    Bike(const string& model, const string& id, int dailyRentalPrice);

    // Destructeur
    ~Bike();

    // Méthode pour afficher les détails du vélo
    void printBike() const;

    // Méthode pour obtenir le magasin de location associé au vélo
    const string& getRentalShopId() const;
};

#endif // BIKE_H
