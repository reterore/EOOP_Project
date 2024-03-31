#ifndef BIKE_H
#define BIKE_H

#include <string> // Utilisez <string> au lieu de <cstring> pour les chaînes de caractères
#include <iostream>
#include "Client.h" // Assurez-vous d'inclure le fichier d'en-tête de la classe Client si nécessaire

class Bike {
private:
    std::string model; // Utilisation de std::string au lieu de char*
    std::string id; // Utilisation de std::string au lieu de char*
    int dailyRentalPrice;
    Bike* nextBike;
    Client* user; // Utilisation du pointeur Client*
    BikeRentalShop* rentalShop;

public:
    // Constructeur
    Bike(const std::string& model, const std::string& id, int dailyRentalPrice);

    // Destructeur
    ~Bike();

    // Méthode pour afficher les détails du vélo
    void printBike() const;

    // Méthode pour obtenir le prochain vélo dans la liste
    Bike*& getNextBike();

    // Méthode pour obtenir l'utilisateur actuel du vélo
    Client* getUser() const;

    // Méthode pour obtenir l'état de location du vélo
    bool getRentalInfo() const;

    void setRentalShop(BikeRentalShop* shop);

    BikeRentalShop* getRentalShop() const;

    // Méthode pour changer l'utilisateur du vélo
    void changeUser(Client* client);
};

#endif // BIKE_H
