#include "Bike.h"

Bike::~Bike() {
    std::cout << "Bike model " << model << " (ID:" << id << ") destroyed!\n"; // Utilisation de std::cout au lieu de cout
    // Libérer la mémoire allouée pour le modèle du vélo
    delete[] model;
    // Libérer la mémoire allouée pour l'ID du vélo
    delete[] id;
    user = NULL;
}


// Méthode pour afficher les détails du vélo
void Bike::printBike() const {
    std::cout << "- Model: " << model << " (ID:" << id << ") at : "<< rentalShopId << std::endl; // Utilisation de std::cout au lieu de cout
    std::cout << "  Daily Rental Price: " << dailyRentalPrice << "$" <<std::endl; // Utilisation de std::cout au lieu de cout
    if (user) {
        cout << "  Rented by " << user->getName() << " (ID:" << user->getClientID() << ")\n";
    } else {
        cout << "  Available for clients\n";
    }
}

bool Bike::isBeingRented() { return user != NULL; }

