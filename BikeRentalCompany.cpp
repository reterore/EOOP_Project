#include "BikeRentalCompany.h"
#include <iostream>
#include <cstring>

BikeRentalCompany::BikeRentalCompany() : head(NULL), numberOfShops(0) {}

BikeRentalCompany::~BikeRentalCompany() {
    std::cout << "Destruction of the Company:\n";
    BikeRentalShop* currentShop = head;
    while (currentShop) {
        BikeRentalShop* temp = currentShop;
        currentShop = currentShop->next;
        delete temp;
    }
}

void BikeRentalCompany::print() {
    cout << "\n___________________________________" << endl;

    if (!head) {
        std::cout << "No shops registered at the moment!" << std::endl;
        cout << "___________________________________" << endl;

        return;
    }
    std::cout << "Shops owned by the Company :| " << numberOfShops << " |\n";
    BikeRentalShop* current = head;
    while (current) {
        current->print();
        std::cout << std::endl;
        current = current->next;
    }
}

bool BikeRentalCompany::insertShop(char* Id) {
    // Check if the shopId is NULL
    if (Id == NULL) {
        std::cout << "Error: Shop ID is NULL." << std::endl;
        return false;
    }

    // Check if the shop with the same ID already exists
    BikeRentalShop* currentShop = head;
    while (currentShop != NULL) {
        if (strcmp(currentShop->getId(), Id) == 0) {
            std::cout << "Error: Shop with the same ID already exists." << std::endl;
            return false;
        }
        currentShop = currentShop->next;
    }

    // Create a new shop
    BikeRentalShop* newShop = new BikeRentalShop;
    newShop->id = new char[strlen(Id) + 1];
    strcpy(newShop->id, Id);
    newShop->next = NULL;

    // Insert the new shop into the company
    if (head == NULL) {
        head = newShop;
    } else {
        BikeRentalShop* tempShop = head;
        while (tempShop->next != NULL) {
            tempShop = tempShop->next;
        }
        tempShop->next = newShop;
    }

    numberOfShops++;
    return true;
}

bool BikeRentalCompany::removeShop(char* Id) {
    if (Id == NULL) {
        std::cout << "Error: Shop ID is NULL." << std::endl;
        return false;
    }

    // Search for the shop with the specified ID
    BikeRentalShop *prev = NULL;
    BikeRentalShop *current = head;
    while (current) {
        if (strcmp(current->getId(), Id) == 0) {
            // If the shop is found
            if (prev == NULL)
                head = current->next;
            else
                prev->next = current->next;

            // Delete the shop
            delete current;
            numberOfShops--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    std::cout << "Error: Shop with the specified ID does not exist." << std::endl;
    return false;
}

bool BikeRentalCompany::insertClient(char* shopId, char* name, char* Id) {
    // Find the shop with the specified ID
    BikeRentalShop* currentShop = head;
    while (currentShop) {
        if (strcmp(currentShop->getId(), shopId) == 0) {
            // Call the insertClient method of the shop
            return currentShop->insertClient(name, Id);
        }
        currentShop = currentShop->next;
    }

    // If shopId is not found
    std::cout << "Error: Shop with the specified ID does not exist." << std::endl;
    return false;
}

bool BikeRentalCompany::insertEmployee(char* shopId, char* name, char* Id) {
    // Find the shop with the specified ID
    BikeRentalShop* currentShop = head;
    while (currentShop) {
        if (strcmp(currentShop->getId(), shopId) == 0) {
            // Call the insertEmployee method of the shop
            return currentShop->insertEmployee(name, Id);
        }
        currentShop = currentShop->next;
    }

    // If shopId is not found
    std::cout << "Error: Shop with the specified ID does not exist." << std::endl;
    return false;
}

bool BikeRentalCompany::insertBike(char* shopId, char* model, char* Id, int dailyRentalPrice) {
    // Find the shop with the specified ID
    BikeRentalShop* currentShop = head;
    while (currentShop) {
        if (strcmp(currentShop->getId(), shopId) == 0) {
            // Call the insertBike method of the shop
            return currentShop->insertBike(model, Id, dailyRentalPrice);
        }
        currentShop = currentShop->next;
    }

    // If shopId is not found
    std::cout << "Error: Shop with the specified ID does not exist." << std::endl;
    return false;
}

bool BikeRentalCompany::rent(char* shopId, char* clientId, char* bikeId) {
    // Vérifier si les IDs sont NULL
    if (shopId == NULL || clientId == NULL || bikeId == NULL) {
        cout << "Error: Shop ID, Client ID, or Bike ID is NULL." << endl;
        return false;
    }

    // Recherche du magasin avec l'ID spécifié
    BikeRentalShop* shop = NULL;
    BikeRentalShop* currentShop = head;
    while (currentShop != NULL) {
        if (strcmp(currentShop->id, shopId) == 0) {
            shop = currentShop;
            break;
        }
        currentShop = currentShop->next;
    }

    // Vérifier si le magasin avec l'ID spécifié existe
    if (shop == NULL) {
        cout << "Error: Bike rental shop with the specified ID does not exist." << endl;
        return false;
    }

    // Appeler la fonction de location dans le magasin correspondant
    return shop->rent(clientId, bikeId);
}

bool BikeRentalCompany::stopRentalClient(char* shopId, char* clientId) {
    // Vérifier si les IDs sont NULL
    if (shopId == NULL || clientId == NULL) {
        cout << "Error: Shop ID or Client ID is NULL." << endl;
        return false;
    }

    // Recherche du magasin avec l'ID spécifié
    BikeRentalShop* shop = NULL;
    BikeRentalShop* currentShop = head;
    while (currentShop != NULL) {
        if (strcmp(currentShop->id, shopId) == 0) {
            shop = currentShop;
            break;
        }
        currentShop = currentShop->next;
    }

    // Vérifier si le magasin avec l'ID spécifié existe
    if (shop == NULL) {
        cout << "Error: Bike rental shop with the specified ID does not exist." << endl;
        return false;
    }

    // Appeler la fonction d'arrêt de location du client dans le magasin correspondant
    return shop->stopRentalClient(clientId);
}

bool BikeRentalCompany::stopRentalBike(char* shopId, char* bikeId) {
    // Vérifier si les IDs sont NULL
    if (shopId == NULL || bikeId == NULL) {
        cout << "Error: Shop ID or Bike ID is NULL." << endl;
        return false;
    }

    // Recherche du magasin avec l'ID spécifié
    BikeRentalShop* shop = NULL;
    BikeRentalShop* currentShop = head;
    while (currentShop != NULL) {
        if (strcmp(currentShop->id, shopId) == 0) {
            shop = currentShop;
            break;
        }
        currentShop = currentShop->next;
    }

    // Vérifier si le magasin avec l'ID spécifié existe
    if (shop == NULL) {
        cout << "Error: Bike rental shop with the specified ID does not exist." << endl;
        return false;
    }

    // Appeler la fonction d'arrêt de location du vélo dans le magasin correspondant
    return shop->stopRentalBike(bikeId);
}

bool BikeRentalCompany::removeClient(char* shopId, char* clientId) {
    // Vérifier si les IDs sont NULL
    if (shopId == NULL || clientId == NULL) {
        cout << "Error: Shop ID or Client ID is NULL." << endl;
        return false;
    }

    // Recherche du magasin avec l'ID spécifié
    BikeRentalShop* shop = NULL;
    BikeRentalShop* currentShop = head;
    while (currentShop != NULL) {
        if (strcmp(currentShop->id, shopId) == 0) {
            shop = currentShop;
            break;
        }
        currentShop = currentShop->next;
    }

    // Vérifier si le magasin avec l'ID spécifié existe
    if (shop == NULL) {
        cout << "Error: Bike rental shop with the specified ID does not exist." << endl;
        return false;
    }

    // Appeler la fonction de suppression du client dans le magasin correspondant
    return shop->removeClient(clientId);
}

bool BikeRentalCompany::removeEmployee(char* shopId, char* employeeId) {
    // Vérifier si les IDs sont NULL
    if (shopId == NULL || employeeId == NULL) {
        cout << "Error: Shop ID or Employee ID is NULL." << endl;
        return false;
    }

    // Recherche du magasin avec l'ID spécifié
    BikeRentalShop* shop = NULL;
    BikeRentalShop* currentShop = head;
    while (currentShop != NULL) {
        if (strcmp(currentShop->id, shopId) == 0) {
            shop = currentShop;
            break;
        }
        currentShop = currentShop->next;
    }

    // Vérifier si le magasin avec l'ID spécifié existe
    if (shop == NULL) {
        cout << "Error: Bike rental shop with the specified ID does not exist." << endl;
        return false;
    }

    // Appeler la fonction de suppression de l'employé dans le magasin correspondant
    return shop->removeEmployee(employeeId);
}

bool BikeRentalCompany::removeBike(char* shopId, char* bikeId) {
    // Vérifier si les IDs sont NULL
    if (shopId == NULL || bikeId == NULL) {
        cout << "Error: Shop ID or Bike ID is NULL." << endl;
        return false;
    }

    // Recherche du magasin avec l'ID spécifié
    BikeRentalShop* shop = NULL;
    BikeRentalShop* currentShop = head;
    while (currentShop != NULL) {
        if (strcmp(currentShop->id, shopId) == 0) {
            shop = currentShop;
            break;
        }
        currentShop = currentShop->next;
    }

    // Vérifier si le magasin avec l'ID spécifié existe
    if (shop == NULL) {
        cout << "Error: Bike rental shop with the specified ID does not exist." << endl;
        return false;
    }

    // Appeler la fonction de suppression du vélo dans le magasin correspondant
    return shop->removeBike(bikeId);
}

void BikeRentalCompany::clear() {
    cout << "The company is being Clear!\n";
    BikeRentalShop* currentRentalShop = head;
    while (currentRentalShop){
        currentRentalShop->clear();
        currentRentalShop = currentRentalShop->next;
    }
}

