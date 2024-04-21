#include "Bike.h"
#include "cstring"

Bike::Bike(const char* model, const char* id, int dailyRentalPrice) : dailyRentalPrice(dailyRentalPrice), rentalShopId("") {
    if (!model) {
        // Default Model
        this->model = new char[strlen("DefaultModel") + 1];
        strcpy(this->model, "DefaultModel");
    } else {
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }
    if (!id) {
        // Default Id
        this->id = new char[strlen("DefaultBikeId") + 1];
        strcpy(this->id, "DefaultBikeId");
    } else {
        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);
    }
}

Bike::~Bike() {
    cout << "Bike model " << model << " (ID:" << id << ") destroyed!\n";
    // Libérer la mémoire allouée pour le modèle du vélo
    delete[] model;
    // Libérer la mémoire allouée pour l'ID du vélo
    delete[] id;
}


// Méthode pour afficher les détails du vélo
void Bike::printBike() const {
    cout << "- Model: " << model << " (ID:" << id << ") at : "<< rentalShopId << endl;
    cout << "  Daily Rental Price: " << dailyRentalPrice << "$" <<endl;

}

