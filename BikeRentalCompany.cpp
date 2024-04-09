#include "BikeRentalCompany.h"
#include <iostream>

BikeRentalCompany::BikeRentalCompany() : head(NULL) {
    numberOfShops = 0;
}

BikeRentalCompany::~BikeRentalCompany() {
    // Libère la mémoire allouée pour chaque magasin dans la liste
    cout << "Bike Rental Company destroyed!\n";
}

void BikeRentalCompany::print() {
    if (!head) {
        cout << "No shops registered at the moment!" << endl;
        return;
    }
    cout << "Shops owned by the Company :| " << numberOfShops << " |\n";
    shopNode* current = head;
    while (current) {
        current->shop->print();
        cout << endl;
        current = current->next;
    }
}

bool BikeRentalCompany::insertShop(BikeRentalShop* bikeRentalShop) {
    // Vérifie si le magasin existe déjà
    shopNode* current = head;
    if (!current) {
        // Si la liste est vide, le nouveau magasin devient la tête de la liste
        head = new shopNode;
        head->shop = bikeRentalShop;
        head->next = NULL;
        cout << "insertion of " << bikeRentalShop->getId() << " shop!\n\n";
        numberOfShops++;
        return true;
    }
    while (current->next) {
        if (current->shop->getId() == bikeRentalShop->getId()) {
            cout << "There is already a shop in " << bikeRentalShop->getId() << endl;
            return false;
        }
        current = current->next;
    }
    if (current->shop->getId() == bikeRentalShop->getId()) {
        cout << "There is already a shop in " << bikeRentalShop->getId() << endl;
        return false;
    }
    // Allocation d'un nouveau noeud
    current->next = new shopNode;
    current->next->shop = bikeRentalShop;
    current->next->next = NULL;
    cout << "insertion of " << bikeRentalShop->getId() << " shop!\n\n";
    numberOfShops++;
    return true;
}

bool BikeRentalCompany::removeShop(BikeRentalShop* bikeRentalShop) {
    shopNode* current = head;
    shopNode* prev = NULL;

    // Parcourt la liste pour trouver le magasin à supprimer
    while (current != NULL) {
        if (current->shop == bikeRentalShop) {
            // Le magasin a été trouvé
            if (prev != NULL) {
                // Le magasin n'est pas en tête de liste
                prev->next = current->next;
            } else {
                // Le magasin est en tête de liste
                head = current->next;
            }
            cout << "removal of " << bikeRentalShop->getId() << " shop!\n\n";
            numberOfShops--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    // Le magasin n'a pas été trouvé dans la liste
    cout << "This shop is not registered!\n";
    return false;
}

bool BikeRentalCompany::removeShop(const string& shopId) {
    shopNode* current = head;
    shopNode* prev = NULL;

    // Parcourt la liste pour trouver le magasin à supprimer
    while (current != NULL) {
        if (current->shop->getId() == shopId) {
            // Le magasin a été trouvé
            if (prev != NULL) {
                // Le magasin n'est pas en tête de liste
                prev->next = current->next;
            } else {
                // Le magasin est en tête de liste
                head = current->next;
            }
            cout << "removal of " << shopId << " shop!\n\n";
            numberOfShops--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    // Le magasin n'a pas été trouvé dans la liste
    cout << "This shop is not registered!\n";
    return false;
}