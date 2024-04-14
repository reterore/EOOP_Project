#include "Bike.h"

// Constructeur
Bike::Bike(const string& model, const string& id, int dailyRentalPrice) : model(model), id(id),
    dailyRentalPrice(dailyRentalPrice), rentalShopId("") {

}

// Destructeur
Bike::~Bike() {
    cout << "Bike model " << model << " (ID:" << id << ") destroyed!\n";
}

// Méthode pour afficher les détails du vélo
void Bike::printBike() const {
    cout << "- Model: " << model << " (ID:" << id << ")" << endl;
    cout << "  Daily Rental Price: " << dailyRentalPrice << "$" <<endl;
}

void Bike::setRentalShopId(const string& id) {
    rentalShopId = id;
}