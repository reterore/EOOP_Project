#include "BikeRentalShop.h"
#include <cstring>
#include <iostream>

BikeRentalShop::BikeRentalShop(const string& shopId) : HeadClient(NULL), HeadEmployee(NULL), HeadBike(NULL), id(shopId){
}

BikeRentalShop::~BikeRentalShop() {
    cout << "Bike shop of " << getId() << " destroyed!\n";
}

void BikeRentalShop::print() const {
    cout << "_______________________________" << endl;
    cout << "Bike Rental Shop of: " << id << endl;
    cout << "_______________________________" << endl;

    // Liste des employés
    cout << "List of employees:" << endl;
    if (HeadEmployee) {
        employeeNode* currentEmployee = HeadEmployee;
        while (currentEmployee) {
            cout << "_______________________________" << endl;
            currentEmployee->employee->printEmployee();
            currentEmployee = currentEmployee->next;
        }
    } else {
        cout << "/!\\ No employees in this shop /!\\" << endl;
    }
    cout << "_______________________________" << endl;

    // Liste des clients
    cout << "List of clients:" << endl;
    if (HeadClient) {
        clientNode* currentClient = HeadClient;
        while (currentClient) {
            cout << "_______________________________" << endl;
            currentClient->client->printClient();
            if(currentClient->bike){
                cout << "  Renting : " << currentClient->bike << " (ID:" << currentClient->bike << ")\n";
            } else {
                cout << "  Does not rent any bike.\n";
            }
            currentClient = currentClient->next;
        }
    } else {
        cout << "/!\\ No clients in this shop /!\\" << endl;
    }
    cout << "_______________________________" << endl;

    // Liste des vélos
    cout << "List of bikes:" << endl;
    if (HeadBike) {
        bikeNode* currentBike = HeadBike;
        while (currentBike) {
            cout << "_______________________________" << endl;
            currentBike->bike->printBike();
            currentBike = currentBike->next;
        }
    } else {
        cout << "/!\\ No bikes in this shop /!\\" << endl;
    }
    cout << "_______________________________" << endl;
}

const string& BikeRentalShop::getId() const {
    return id;
}

bool BikeRentalShop::insertEmployee(Employee* employee) {
    // Vérifier si l'employé est valide
    if (!employee) {
        cout << "Error: Invalid employee." << endl;
        return false;
    }

    // Si la liste d'employés est vide, ajoutez l'employé comme premier élément
    if (!HeadEmployee) {
        HeadEmployee = new employeeNode;
        HeadEmployee->employee = employee;
        HeadEmployee->next = NULL;
        return true;
    }

    // Parcourir la liste pour trouver le dernier employé
    employeeNode* currentEmployee = HeadEmployee;
    while (currentEmployee->next != NULL) {
        currentEmployee = currentEmployee->next;
    }

    // Ajouter le nouvel employé à la fin de la liste
    currentEmployee->next = new employeeNode;
    currentEmployee->next->employee = employee;
    currentEmployee->next->next = NULL;
    return true;
}

bool BikeRentalShop::insertClient(Client* client) {
    // Vérifier si le client est valide
    if (!client) {
        cout << "Error: Invalid client." << endl;
        return false;
    }
    client->setRentalShopId(id);
    // Si la liste de clients est vide, ajoutez le client comme premier élément
    if (!HeadClient) {
        HeadClient = new clientNode;
        HeadClient->client = client;
        HeadClient->bike = NULL;
        HeadClient->next = NULL;
        return true;
    }

    // Parcourir la liste pour trouver le dernier client
    clientNode* currentClient = HeadClient;
    while (currentClient->next != NULL) {
        currentClient = currentClient->next;
    }

    // Ajouter le nouveau client à la fin de la liste
    currentClient->next = new clientNode;
    currentClient->next->client = client;
    currentClient->next->bike = NULL;
    currentClient->next->next = NULL;
    return true;
}

bool BikeRentalShop::insertBike(Bike* bike) {
    // Vérifier si le vélo est valide
    if (!bike) {
        cout << "Error: Invalid bike." << endl;
        return false;
    }

    // Si la liste de vélos est vide, ajoutez le vélo comme premier élément
    if (!HeadBike) {
        HeadBike = new bikeNode;
        HeadBike->bike = bike;
        HeadBike->user = NULL;
        HeadBike->next = NULL;
        return true;
    }

    // Parcourir la liste pour trouver le dernier vélo
    bikeNode* currentBike = HeadBike;
    while (currentBike->next != NULL) {
        currentBike = currentBike->next;
    }

    // Ajouter le nouveau vélo à la fin de la liste
    currentBike->next = new bikeNode;
    currentBike->next->bike = bike;
    currentBike->next->user = NULL;
    currentBike->next->next = NULL;
    return true;
}
