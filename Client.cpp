#include "Client.h"
#include <iostream>
using namespace std; // Ajout du namespace std


Client::~Client() {
    cout << "Client " << name << " (ID:" << clientID << ") destroyed!\n";
    // Libérer la mémoire allouée pour le nom du client
    delete[] name;
    // Libérer la mémoire allouée pour l'ID du client
    delete[] clientID;
}

void Client::printClient() const {
    cout << "- (ID:" << clientID << ") | name: " << name  << " at : " << rentalShopId << endl;
    if (bike) {
        cout << "  Renting : " << bike->getModel() << " (ID:" << bike->getBikeId() << ")\n";
    } else {
        cout << "  Does not rent any bike\n";
    }
}

bool Client::isRentingABike() { return bike != NULL; }

