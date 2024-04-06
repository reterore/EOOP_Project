//
// Created by lucas on 25/03/2024.
//

#include "BikeRentalCompany.h"

BikeRentalCompany::BikeRentalCompany() : head(NULL), shopNb(0) {
    // Initialise les membres de données
}




BikeRentalShop* BikeRentalCompany::getHead(){
    return head;
}


bool BikeRentalCompany::insertShop(BikeRentalShop* bikeRentalShop) {
    if (bikeRentalShop == NULL) {
        cout << "Invalid shop!" << endl;
        return false;
    }

    if (head == NULL) {
        head = bikeRentalShop;
    } else {
        BikeRentalShop* current = head;
        while (current->getNextShop() != NULL) {
            current = current->getNextShop();
        }
        current->getNextShop() = bikeRentalShop;
    }
    bikeRentalShop->getNextShop() = NULL; // Assurez-vous que le dernier magasin a son prochain pointeur à NULL
    return true;
}

void BikeRentalCompany::print() {
    if (head != NULL){
        BikeRentalShop* currentShop = head;
        while (currentShop != NULL){
            currentShop->print();
            currentShop = currentShop->getNextShop();
        }
    } else {
        cout << "No shop in the company!" << endl;
    }
}

bool BikeRentalCompany::removeShop(BikeRentalShop* bikeRentalShop) {
    if (bikeRentalShop == NULL) {
        cout << "Invalid shop!" << endl;
        return false;
    }

    BikeRentalShop* current = head;
    BikeRentalShop* previous = NULL;

    // Recherche du magasin à supprimer
    while (current != NULL && current != bikeRentalShop) {
        previous = current;
        current = current->getNextShop();
    }

    // Si le magasin n'a pas été trouvé
    if (current == NULL) {
        cout << "Shop not found!" << endl;
        return false;
    }

    // Si le magasin à supprimer est la tête de la liste
    if (previous == NULL) {
        head = current->getNextShop();
    } else {
        // Si le magasin à supprimer n'est pas la tête de la liste
        previous->getNextShop() = current->getNextShop();
    }

    cout << "Shop removed successfully!" << endl;
    return true;
}

bool BikeRentalCompany::removeShop(const char* shopId) {
    if (head == NULL) {
        cout << "No shops in the company!" << endl;
        return false;
    }

    BikeRentalShop* current = head;
    BikeRentalShop* previous = NULL;

    // Recherche du magasin à supprimer
    while (current != NULL && strcmp(current->getId(), shopId) != 0) {
        previous = current;
        current = current->getNextShop();
    }

    // Si le magasin n'a pas été trouvé
    if (current == NULL) {
        cout << "Shop with ID " << shopId << " not found!" << endl;
        return false;
    }

    // Si le magasin à supprimer est la tête de la liste
    if (previous == NULL) {
        head = current->getNextShop();
    } else {
        // Si le magasin à supprimer n'est pas la tête de la liste
        previous->getNextShop() = current->getNextShop();
    }

    cout << "Shop with ID " << shopId << " removed successfully!" << endl;
    return true;
}
