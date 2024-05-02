#include "BikeRentalShop.h"
#include <iostream>
#include <cstring> // Ajout de l'inclusion de la bibliothèque cstring

using namespace std; // Ajout du namespace std

BikeRentalShop::~BikeRentalShop() {
    cout << "Destroying Bike Rental Shop: " << getId() << endl;

    // Libérer la mémoire allouée pour l'ID
    delete[] id;

    // Libérer la mémoire allouée pour la liste chaînée des clients
    while (HeadClient != NULL) {
        Client* temp = HeadClient;
        HeadClient = HeadClient->next;
        delete temp;
    }

    // Libérer la mémoire allouée pour la liste chaînée des employés
    while (HeadEmployee != NULL) {
        Employee* temp = HeadEmployee;
        HeadEmployee = HeadEmployee->next;
        delete temp;
    }

    // Libérer la mémoire allouée pour la liste chaînée des vélos
    while (HeadBike != NULL) {
        Bike* temp = HeadBike;
        HeadBike = HeadBike->next;
        delete temp;
    }
}


void BikeRentalShop::print() const {
    cout << "___________________________________" << endl;
    cout << "Bike Rental Shop of: " << id << endl;
    cout << "___________________________________" << endl;

    // Liste des employés
    cout << "List of employees:" << endl;
    if (HeadEmployee) {
        Employee* currentEmployee = HeadEmployee;
        while (currentEmployee) {
            cout << "___________________________________" << endl;
            currentEmployee->printEmployee();
            currentEmployee = currentEmployee->next;
        }
    } else {
        cout << "/!\\ No employees in this shop /!\\" << endl;
    }
    cout << "___________________________________" << endl;

    // Liste des clients
    cout << "List of clients:" << endl;
    if (HeadClient) {
        Client* currentClient = HeadClient;
        while (currentClient) {
            cout << "___________________________________" << endl;
            currentClient->printClient();
            currentClient = currentClient->next;
        }
    } else {
        cout << "/!\\ No clients in this shop /!\\" << endl;
    }
    cout << "___________________________________" << endl;

    // Liste des vélos
    cout << "List of bikes:" << endl;
    if (HeadBike) {
        Bike* currentBike = HeadBike;
        while (currentBike) {
            cout << "___________________________________" << endl;
            currentBike->printBike();
            currentBike = currentBike->next;
        }
    } else {
        cout << "/!\\ No bikes in this shop /!\\" << endl;
    }
    cout << "___________________________________" << endl;
}

// Method to insert a client into the shop
bool BikeRentalShop::insertClient(char* name, char* Id) {
    if (name == NULL || Id == NULL) {
        cout << "Error: Name or ID is NULL." << endl;
        return false;
    }

    // Check if the ID already exists
    Client* currentClient = HeadClient;
    while (currentClient != NULL) {
        if (strcmp(currentClient->clientID, Id) == 0) {
            cout << "Error: Client with the same ID already exists." << endl;
            return false;
        }
        currentClient = currentClient->next;
    }

    // Create a new client
    Client* newClient = new Client;
    newClient->name = new char[strlen(name) + 1];
    strcpy(newClient->name, name);
    newClient->clientID = new char[strlen(Id) + 1];
    strcpy(newClient->clientID, Id);
    newClient->rentalShopId = id;

    // Insert the new client into the shop
    if (HeadClient == NULL) {
        HeadClient = newClient;
    } else {
        Client* tempClient = HeadClient;
        while (tempClient->next != NULL) {
            tempClient = tempClient->next;
        }
        tempClient->next = newClient;
    }

    return true;
}

// Method to insert an employee into the shop
bool BikeRentalShop::insertEmployee(char* name, char* Id) {
    if (name == NULL || Id == NULL) {
        cout << "Error: Name or ID is NULL." << endl;
        return false;
    }

    // Check if the ID already exists
    Employee* currentEmployee = HeadEmployee;
    while (currentEmployee != NULL) {
        if (strcmp(currentEmployee->employeeId, Id) == 0) {
            cout << "Error: Employee with the same ID already exists." << endl;
            return false;
        }
        currentEmployee = currentEmployee->next;
    }

    // Create a new employee
    Employee* newEmployee = new Employee;
    newEmployee->name = new char[strlen(name) + 1];
    strcpy(newEmployee->name, name);
    newEmployee->employeeId = new char[strlen(Id) + 1];
    strcpy(newEmployee->employeeId, Id);
    newEmployee->rentalShopId = id;

    // Insert the new employee into the shop
    if (HeadEmployee == NULL) {
        HeadEmployee = newEmployee;
    } else {
        Employee* tempEmployee = HeadEmployee;
        while (tempEmployee->next != NULL) {
            tempEmployee = tempEmployee->next;
        }
        tempEmployee->next = newEmployee;
    }

    return true;
}

// Method to insert a bike into the shop
bool BikeRentalShop::insertBike(char* model, char* Id, int dailyRentalPrice) {
    if (model == NULL || Id == NULL) {
        cout << "Error: Model or ID is NULL." << endl;
        return false;
    }

    // Check if the ID already exists
    Bike* currentBike = HeadBike;
    while (currentBike != NULL) {
        if (strcmp(currentBike->id, Id) == 0) {
            cout << "Error: Bike with the same ID already exists." << endl;
            return false;
        }
        currentBike = currentBike->next;
    }

    // Create a new bike
    Bike* newBike = new Bike;
    newBike->model = new char[strlen(model) + 1];
    strcpy(newBike->model, model);
    newBike->id = new char[strlen(Id) + 1];
    strcpy(newBike->id, Id);
    newBike->dailyRentalPrice = dailyRentalPrice; // Default value for dailyRentalPrice
    newBike->rentalShopId = id;

    // Insert the new bike into the shop
    if (HeadBike == NULL) {
        HeadBike = newBike;
    } else {
        Bike* tempBike = HeadBike;
        while (tempBike->next != NULL) {
            tempBike = tempBike->next;
        }
        tempBike->next = newBike;
    }

    return true;
}


bool BikeRentalShop::rent(char* clientId, char* bikeId) {
    // Vérifier si les IDs sont NULL
    if (clientId == NULL || bikeId == NULL) {
        cout << "Error: Client ID or Bike ID is NULL." << endl;
        return false;
    }

    // Recherche du client avec l'ID spécifié
    Client* client = NULL;
    Client* currentClient = HeadClient;
    while (currentClient != NULL) {
        if (strcmp(currentClient->clientID, clientId) == 0) {
            client = currentClient;
            break;
        }
        currentClient = currentClient->next;
    }

    // Vérifier si le client avec l'ID spécifié existe
    if (client == NULL) {
        cout << "Error: Client with the specified ID does not exist." << endl;
        return false;
    }

    // Recherche du vélo avec l'ID spécifié
    Bike* bike = NULL;
    Bike* currentBike = HeadBike;
    while (currentBike != NULL) {
        if (strcmp(currentBike->id, bikeId) == 0) {
            bike = currentBike;
            break;
        }
        currentBike = currentBike->next;
    }

    // Vérifier si le vélo avec l'ID spécifié existe
    if (bike == NULL) {
        cout << "Error: Bike with the specified ID does not exist." << endl;
        return false;
    }

    // Vérifier si le client n'a pas déjà loué un vélo
    if (client->bike != NULL) {
        cout << "Error: Client has already rented a bike." << endl;
        return false;
    }

    // Vérifier si le vélo n'est pas déjà loué
    if (bike->user != NULL) {
        cout << "Error: Bike is already rented." << endl;
        return false;
    }

    // Lier le client et le vélo
    client->bike = bike;
    bike->user = client;

    cout << "Bike rented successfully." << endl;
    return true;
}


bool BikeRentalShop::stopRentalClient(char* clientId) {
    // Vérifier si l'ID du client est NULL
    if (clientId == NULL) {
        cout << "Error: Client ID is NULL." << endl;
        return false;
    }

    // Recherche du client avec l'ID spécifié
    Client* client = NULL;
    Client* currentClient = HeadClient;
    while (currentClient != NULL) {
        if (strcmp(currentClient->clientID, clientId) == 0) {
            client = currentClient;
            break;
        }
        currentClient = currentClient->next;
    }

    // Vérifier si le client avec l'ID spécifié existe
    if (client == NULL) {
        cout << "Error: Client with the specified ID does not exist." << endl;
        return false;
    }

    // Vérifier si le client a un vélo loué
    if (client->bike == NULL) {
        cout << "Error: Client does not have a bike rented." << endl;
        return false;
    }

    // Dissocier le client du vélo
    client->bike->user = NULL;
    client->bike = NULL;

    cout << "Rental stopped successfully." << endl;
    return true;
}

bool BikeRentalShop::stopRentalBike(char* bikeId) {
    // Vérifier si l'ID du vélo est NULL
    if (bikeId == NULL) {
        cout << "Error: Bike ID is NULL." << endl;
        return false;
    }

    // Recherche du vélo avec l'ID spécifié
    Bike* bike = NULL;
    Bike* currentBike = HeadBike;
    while (currentBike != NULL) {
        if (strcmp(currentBike->id, bikeId) == 0) {
            bike = currentBike;
            break;
        }
        currentBike = currentBike->next;
    }

    // Vérifier si le vélo avec l'ID spécifié existe
    if (bike == NULL) {
        cout << "Error: Bike with the specified ID does not exist." << endl;
        return false;
    }

    // Vérifier si le vélo est actuellement loué
    if (bike->user == NULL) {
        cout << "Error: Bike is not currently rented." << endl;
        return false;
    }

    // Dissocier le vélo du client
    bike->user->bike = NULL;
    bike->user = NULL;

    cout << "Rental stopped successfully." << endl;
    return true;
}



bool BikeRentalShop::removeClient(char* Id) {
    // Vérifier si l'ID du client est NULL
    if (Id == NULL) {
        cout << "Error: Client ID is NULL." << endl;
        return false;
    }
    // Recherche du client avec l'ID spécifié
    Client* prevClient = NULL;
    Client* currentClient = HeadClient;
    while (currentClient != NULL) {
        if (strcmp(currentClient->clientID, Id) == 0) {
            // Si le client est le premier élément de la liste
            if (prevClient == NULL)
                HeadClient = currentClient->next;
            else
                prevClient->next = currentClient->next;

            // Libérer la mémoire allouée pour le client
            if (currentClient->bike != NULL) {
                currentClient->bike->user = NULL;
                currentClient->bike = NULL;
            }
            delete currentClient;
            return true;
        }
        prevClient = currentClient;
        currentClient = currentClient->next;
    }

    cout << "Error: Client with the specified ID does not exist." << endl;
    return false;
}

bool BikeRentalShop::removeEmployee(char* Id) {
    // Vérifier si l'ID de l'employé est NULL
    if (Id == NULL) {
        cout << "Error: Employee ID is NULL." << endl;
        return false;
    }
    // Recherche de l'employé avec l'ID spécifié
    Employee* prevEmployee = NULL;
    Employee* currentEmployee = HeadEmployee;
    while (currentEmployee != NULL) {
        if (strcmp(currentEmployee->employeeId, Id) == 0) {
            // Si l'employé est le premier élément de la liste
            if (prevEmployee == NULL)
                HeadEmployee = currentEmployee->next;
            else
                prevEmployee->next = currentEmployee->next;
            // Libérer la mémoire allouée pour l'employé
            delete currentEmployee;
            return true;
        }
        prevEmployee = currentEmployee;
        currentEmployee = currentEmployee->next;
    }

    cout << "Error: Employee with the specified ID does not exist." << endl;
    return false;
}

bool BikeRentalShop::removeBike(char* Id) {
    // Vérifier si l'ID du vélo est NULL
    if (Id == NULL) {
        cout << "Error: Bike ID is NULL." << endl;
        return false;
    }
    // Recherche du vélo avec l'ID spécifié
    Bike* prevBike = NULL;
    Bike* currentBike = HeadBike;
    while (currentBike != NULL) {
        if (strcmp(currentBike->id, Id) == 0) {
            // Si le vélo est le premier élément de la liste
            if (prevBike == NULL)
                HeadBike = currentBike->next;
            else
                prevBike->next = currentBike->next;

            // Libérer la mémoire allouée pour le vélo
            // Dissocier le vélo du client
            if (currentBike->user != NULL) {
                currentBike ->user->bike = NULL;
                currentBike->user = NULL;
            }

            delete currentBike;
            return true;
        }
        prevBike = currentBike;
        currentBike = currentBike->next;
    }

    cout << "Error: Bike with the specified ID does not exist." << endl;
    return false;
}

void BikeRentalShop::clear() {
    Employee* currentEmployee = HeadEmployee;
    while (currentEmployee){
        removeEmployee(currentEmployee->employeeId);
        currentEmployee = currentEmployee->next;
    }
    Client* currentClient = HeadClient;
    while (currentClient){
        removeClient(currentClient->clientID);
        currentClient = currentClient->next;
    }
    Bike* currentBike = HeadBike;
    while (currentBike){
        removeBike(currentBike->id);
        currentBike = currentBike->next;
    }
}