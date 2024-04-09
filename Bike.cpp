#include "Bike.h"

// Constructeur
Bike::Bike(const string& model, const string& id, int dailyRentalPrice) : model(model), id(id), dailyRentalPrice(dailyRentalPrice) {
    // Aucun besoin de l'allocation dynamique de mémoire pour les objets string
}

// Destructeur
Bike::~Bike() {
    cout << "Bike model " << model << " (ID:" << id << ") destroyed!\n";
}

// Méthode pour afficher les détails du vélo
void Bike::printBike() const {
    cout << "- Model: " << model << " (ID:" << id << ")" << endl;
    cout << "  Daily Rental Price: " << dailyRentalPrice << endl;
}

// Méthode pour obtenir le magasin de location associé au vélo
const string& Bike::getRentalShopId() const {
    return rentalShopId;
}
