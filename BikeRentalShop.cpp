#include "BikeRentalShop.h"
#include <iostream>
#include "cstring"

BikeRentalShop::BikeRentalShop(const char* shopId) : HeadClient(NULL), HeadEmployee(NULL), HeadBike(NULL) {
    if (!shopId) {
        // Default Id
        this->id = new char[strlen("DefaultShopId") + 1];
        strcpy(this->id, "DefaultShopId");
    } else {
        this->id = new char[strlen(shopId) + 1];
        strcpy(this->id, shopId);
    }
}


BikeRentalShop::~BikeRentalShop() {

    cout << "Bike shop of " << getId() << " destroyed!\n";
    // Libérer la mémoire allouée pour l'ID
    delete[] id;



    // Parcourir et libérer la mémoire pour la liste des employés
    employeeNode* currentEmployee = HeadEmployee;
    while (currentEmployee) {
        employeeNode* temp = currentEmployee;
        currentEmployee = currentEmployee->next;
        delete temp; // Supprimer le nœud
    }

    // Parcourir et libérer la mémoire pour la liste des clients
    clientNode* currentClient = HeadClient;
    while (currentClient) {
        clientNode* temp = currentClient;
        currentClient = currentClient->next;
        delete temp; // Supprimer le nœud
    }

    // Parcourir et libérer la mémoire pour la liste des vélos
    bikeNode* currentBike = HeadBike;
    while (currentBike) {
        bikeNode* temp = currentBike;
        currentBike = currentBike->next;
        delete temp; // Supprimer le nœud
    }
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
            if (currentClient->bike) {
                cout << "  Renting : " << currentClient->bike->getModel() << " (ID:" << currentClient->bike->getBikeId() << ")\n";
            } else {
                cout << "  Does not rent any bike\n";
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
            if (currentBike->user) {
                cout << "  Rented by " << currentBike->user->getName() << " (ID:" << currentBike->user->getClientID() << ")\n";
            } else {
                cout << "  Available for clients\n";
            }
            currentBike = currentBike->next;
        }
    } else {
        cout << "/!\\ No bikes in this shop /!\\" << endl;
    }
    cout << "_______________________________" << endl;
}

bool BikeRentalShop::insert(Employee* employee) {
    // Vérifier si l'employé est valide
    if (!employee) {
        cout << "Error: Invalid employee" << endl;
        return false;
    }
    if (strcmp(employee->getRentalShopId(), "") != 0) {
        cout << "Error: Employee " << employee->getName() << " (ID:"<< employee->getEmployeeID() <<") already affiliated in a rental shop (" << employee->getRentalShopId()<<")." << endl;
        return false;
    }
    employee->rentalShopId = id;
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

bool BikeRentalShop::insert(Client* client) {
    // Vérifier si le client est valide
    if (!client) {
        cout << "Error: Invalid client." << endl;
        return false;
    }

    if (strcmp(client->getRentalShopId(), "") != 0) {
        cout << "Error: Client " << client->getName() << " (ID:"<< client->getClientID() <<") already affiliated in a rental shop (" << client->getRentalShopId()<<")." << endl;
        return false;
    }

    client->rentalShopId = id;
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

bool BikeRentalShop::insert(Bike* bike) {
    // Vérifier si le vélo est valide
    if (!bike) {
        cout << "Error: Invalid bike." << endl;
        return false;
    }

    // Vérifier si le vélo est déjà affilié à une autre boutique
    if (strcmp(bike->getRentalShopId(), "") != 0) {
        cout << "Error: Bike " << bike->getModel() << " (ID: " << bike->getBikeId() << ") is already affiliated with another rental shop (" << bike->getRentalShopId() << ")." << endl;
        return false;
    }

    // Mettre à jour le shop affilié pour le vélo
    bike->rentalShopId = id;

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

bool BikeRentalShop::rent(Client* client, Bike* bike) {

    if (!client || !bike) {
        cout << "Error: Invalid client or bike." << endl;
        return false;
    }
    clientNode* myClientNode = HeadClient;
    bikeNode* myBikeNode = HeadBike;
    while (myClientNode && myClientNode->client != client){
        myClientNode = myClientNode->next;
    }
    if (!myClientNode){
        cout << "Error: Client not registered in this shop!\n";
        return false;
    }
    while (myBikeNode && myBikeNode->bike != bike){
        myBikeNode = myBikeNode->next;
    }
    if (!myBikeNode){
        cout << "Error: Bike not registered in this shop!\n";
        return false;
    }
    // Vérifier si le client est déjà en train de louer un vélo
    if (myClientNode->bike) {
        cout << "Error: This client is already renting a bike." << endl;
        return false;
    }
    if (myBikeNode->user) {
        cout << "Error: This bike is already rented." << endl;
        return false;
    }
    myBikeNode->user = client;
    myClientNode->bike = bike;
    cout << client->getName() <<" successfully rented the bike" << endl;
    return true; // Changement ici
}

bool BikeRentalShop::stopRental(Client* client) {
    if (!client) {
        cout << "Error: Invalid client." << endl;
        return false;
    }

    // Recherche du client dans la liste des clients
    clientNode* myClientNode = HeadClient;
    while (myClientNode && myClientNode->client != client) {
        myClientNode = myClientNode->next;
    }
    if (!myClientNode) {
        cout << "Error: Client not registered in this shop!" << endl;
        return false;
    }

    // Vérification si le client loue effectivement un vélo
    if (!myClientNode->bike) {
        cout << "Error: This client is not renting a bike." << endl;
        return false;
    }

    // Recherche du vélo correspondant au client
    Bike* rentedBike = myClientNode->bike;
    bikeNode* myBikeNode = HeadBike;
    while (myBikeNode && myBikeNode->bike != rentedBike) {
        myBikeNode = myBikeNode->next;
    }
    if (!myBikeNode) {
        cout << "Error: Bike not found." << endl;
        return false;
    }

    // Retrait du vélo et du client de la location
    myClientNode->bike = NULL;
    myBikeNode->user = NULL;
    cout << client->getName() << " successfully returned the bike." << endl;
    return true;
}

bool BikeRentalShop::stopRental(Bike* bike) {
    if (!bike) {
        cout << "Error: Invalid bike." << endl;
        return false;
    }

    // Recherche du vélo dans la liste des vélos
    bikeNode* myBikeNode = HeadBike;
    while (myBikeNode && myBikeNode->bike != bike) {
        myBikeNode = myBikeNode->next;
    }
    if (!myBikeNode) {
        cout << "Error: Bike not found." << endl;
        return false;
    }

    // Vérification si le vélo est loué
    if (!myBikeNode->user) {
        cout << "Error: This bike is not rented." << endl;
        return false;
    }

    // Retrait du vélo et du client de la location
    myBikeNode->user = NULL;
    myBikeNode->user = NULL;
    cout << "Bike successfully returned." << endl;
    return true;
}



bool BikeRentalShop::remove(Employee* employee) {
    // Vérifier si l'employé est valide
    if (!employee) {
        cout << "Error: Invalid employee" << endl;
        return false;
    }

    // Parcourir la liste pour trouver l'employé à supprimer
    employeeNode* prevEmployee = NULL;
    employeeNode* currentEmployee = HeadEmployee;
    while (currentEmployee != NULL) {
        if (currentEmployee->employee == employee) {
            // Retirer l'employé de la liste
            if (prevEmployee) {
                prevEmployee->next = currentEmployee->next;
            } else {
                HeadEmployee = currentEmployee->next;
            }
            employee->rentalShopId = "";
            return true;
        }
        prevEmployee = currentEmployee;
        currentEmployee = currentEmployee->next;
    }

    // L'employé n'a pas été trouvé dans la liste
    cout << "Error: Employee not found" << endl;
    return false;
}

bool BikeRentalShop::remove(Client* client) {
    // Vérifier si le client est valide
    if (!client) {
        cout << "Error: Invalid client." << endl;
        return false;
    }

    // Parcourir la liste pour trouver le client à supprimer
    clientNode* prevClient = NULL;
    clientNode* currentClient = HeadClient;
    while (currentClient != NULL) {
        if (currentClient->client == client) {
            // Retirer le client de la liste
            if (prevClient) {
                prevClient->next = currentClient->next;
            } else {
                HeadClient = currentClient->next;
            }
            // Retirer la connexion entre le client et le vélo s'il en louait un
            if (currentClient->bike) {
                currentClient->bike = NULL;
                bikeNode* currentBike = HeadBike;
                while (currentBike->user != currentClient->client){
                    currentBike = currentBike->next;
                }
                currentBike->user = NULL;
            }
            client->rentalShopId = "";
            return true;
        }
        prevClient = currentClient;
        currentClient = currentClient->next;
    }

    // Le client n'a pas été trouvé dans la liste
    cout << "Error: Client not found" << endl;
    return false;
}

bool BikeRentalShop::remove(Bike* bike) {
    // Vérifier si le vélo est valide
    if (!bike) {
        cout << "Error: Invalid bike." << endl;
        return false;
    }

    // Parcourir la liste pour trouver le vélo à supprimer
    bikeNode* prevBike = NULL;
    bikeNode* currentBike = HeadBike;
    while (currentBike != NULL) {
        if (currentBike->bike == bike) {
            // Retirer le vélo de la liste
            if (prevBike) {
                prevBike->next = currentBike->next;
            } else {
                HeadBike = currentBike->next;
            }
            // Retirer la connexion entre le vélo et le client s'il était loué
            if (currentBike->user) {
                currentBike->user = NULL;
                clientNode* currentClient = HeadClient;
                while (currentClient->bike != currentBike->bike){
                    currentClient = currentClient->next;
                }
                currentClient->bike = NULL;
            }
            bike->rentalShopId = "";
            return true;
        }
        prevBike = currentBike;
        currentBike = currentBike->next;
    }

    // Le vélo n'a pas été trouvé dans la liste
    cout << "Error: Bike not found" << endl;
    return false;
}

