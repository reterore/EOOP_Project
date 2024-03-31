//
// Created by lucas on 25/03/2024.
//

#include "BikeRentalShop.h"
#include "cstring"

BikeRentalShop::BikeRentalShop(const char* shopId) : clientList(NULL), employeeList(NULL), bikeList(NULL), next(NULL) {
    id = new char[strlen(shopId) + 1];
    strcpy(id, shopId);
}

BikeRentalShop::~BikeRentalShop() {
}

void BikeRentalShop::print() const {
    cout << "_______________________________" << endl;
    cout << "Bike Rental Shop of: " << id << endl;
    Employee* currentEmployee = employeeList;
    cout << "_______________________________" << endl;
    cout << "list of employees:" << endl;
    if (employeeList != NULL){
        while (currentEmployee != NULL){
            currentEmployee->printEmployee();
            currentEmployee = currentEmployee->getNextEmployee();
        }
    }else{
        cout << "/!\\No employees in this shop/!\\" << endl;
    }
    cout << "_______________________________" << endl;
    cout << "list of client:" << endl;
    Client* currentClient = clientList;
    if (clientList != NULL){
        while (currentClient != NULL){
            currentClient->printClient();
            currentClient = currentClient->getNextClient();
        }
    }else{
        cout << "/!\\No clients in this shop/!\\" << endl;
    }
    cout << "_______________________________" << endl;
    cout << "list of Bike:" << endl;
    Bike* currentBike = bikeList;
    if(bikeList != NULL){
        while (currentBike != NULL){
            cout << "_______________________________" << endl;
            currentBike->printBike();
            currentBike = currentBike->getNextBike();
        }
    }else{
        cout << "/!\\No bikes in this shop/!\\" << endl;
    }
    cout << "_______________________________" << endl;
}

char* BikeRentalShop::getId(){
    return id;
}


BikeRentalShop *&BikeRentalShop::getNextShop() {
    return next;
}

bool BikeRentalShop::insertEmployee(Employee* employee) {
    // Vérifier si l'employé passé en paramètre est valide
    if (!employee) {
        cout << "Error: Invalid employee." << endl;
        return false;
    }

    // Vérifier si l'employé appartient déjà à un magasin
    if (employee->getRentalShop() != NULL) {
        cout << "Error: Employee is already associated with a rental shop." << endl;
        return false;
    }

    // Si la liste d'employés est vide, ajoutez l'employé en tant que premier élément
    if (!employeeList) {
        employeeList = employee;
        employee->setRentalShop(this); // Définir le magasin de l'employé sur ce magasin
        return true;
    }

    // Parcourir la liste pour trouver le dernier employé
    Employee* current = employeeList;
    while (current->getNextEmployee() != NULL) {
        current = current->getNextEmployee();
    }

    // Ajouter le nouvel employé à la fin de la liste
    current->getNextEmployee() = employee;
    employee->setRentalShop(this); // Définir le magasin de l'employé sur ce magasin
    return true;
}

bool BikeRentalShop::insertClient(Client* client) {
    // Vérifier si le client est valide
    if (!client) {
        cout << "Error: Invalid client." << endl;
        return false;
    }

    // Vérifier si le client appartient déjà à un magasin
    if (client->getRentalShop() != NULL) {
        cout << "Error: Client is already associated with a rental shop." << endl;
        return false;
    }

    // Si la liste de clients est vide, ajouter le client comme premier élément
    if (!clientList) {
        clientList = client;
        client->setRentalShop(this); // Définir le magasin du client sur ce magasin
        return true;
    }

    // Parcourir la liste pour trouver le dernier client
    Client* current = clientList;
    while (current->getNextClient() != NULL) {
        current = current->getNextClient();
    }

    // Ajouter le nouveau client à la fin de la liste
    current->getNextClient() = client;
    client->setRentalShop(this); // Définir le magasin du client sur ce magasin
    return true;
}

bool BikeRentalShop::insertBike(Bike *bike) {
    // Vérifier si le vélo passé en paramètre est valide
    if (!bike) {
        cout << "Error: Invalid bike." << endl;
        return false;
    }

    if (bike->getRentalShop() != NULL) {
        cout << "Error: Bike is already associated with a rental shop." << endl;
        return false;
    }

    // Si la liste de vélos est vide, ajoutez le vélo en tant que premier élément
    if (!bikeList) {
        bikeList = bike;
        bike->setRentalShop(this); // Définir le magasin du vélo sur ce magasin
        bike->getNextBike() = NULL; // Assurez-vous que le nouveau vélo pointe vers NULL
        return true;
    }

    // Parcourir la liste pour trouver le dernier vélo
    Bike* current = bikeList;
    while (current->getNextBike() != NULL) {
        current = current->getNextBike();
    }

    // Ajouter le nouveau vélo à la fin de la liste
    current->getNextBike() = bike;
    bike->setRentalShop(this); // Définir le magasin du vélo sur ce magasin
    bike->getNextBike() = NULL; // Assurez-vous que le nouveau vélo pointe vers NULL
    return true;
}

bool BikeRentalShop::rent(Client* client, Bike* bike) {
    // Check if client or bike is null
    if (!client || !bike) {
        std::cout << "Error: Invalid client or bike." << std::endl;
        return false;
    }

    // Check if the client is already renting a bike
    if (client->getBike() != NULL) {
        std::cout << "Client already has a bike rented." << std::endl;
        return false;
    }

    // Check if the client is registered in the rental shop
    bool clientExists = false;
    Client* currentClient = clientList;
    while (currentClient != NULL) {
        if (currentClient == client) {
            clientExists = true;
            break;
        }
        currentClient = currentClient->getNextClient();
    }
    if (!clientExists) {
        std::cout << "Client not found in the rental shop." << std::endl;
        return false;
    }

    // Check if the bike is in the rental shop and available
    bool bikeInShop = false;
    bool bikeAvailable = false;
    Bike* currentBike = bikeList;
    while (currentBike != NULL) {
        if (currentBike == bike) {
            bikeInShop = true;
            if (!currentBike->getRentalInfo()) {
                bikeAvailable = true;
                break;
            }
        }
        currentBike = currentBike->getNextBike();
    }
    if (!bikeInShop) {
        std::cout << "Bike not found in the rental shop." << std::endl;
        return false;
    }
    if (!bikeAvailable) {
        std::cout << "Bike is not available for rent." << std::endl;
        return false;
    }

    // Marquer le vélo comme loué
    bike->changeUser(client);
    client->changeBike(bike);
    std::cout << "Bike rented successfully." << std::endl;
    return true;
}

bool BikeRentalShop::removeClient(Client* clientToRemove) {
    if (clientToRemove == NULL) {
        cerr << "Error: Invalid client!" << endl;
        return false;
    }

    if (clientList == NULL) {
        cerr << "Error: No clients in the shop!" << endl;
        return false;
    }

    Client* current = clientList;
    Client* previous = NULL;

    // Recherche du client à supprimer
    while (current != NULL && current != clientToRemove) {
        previous = current;
        current = current->getNextClient();
    }

    // Si le client n'a pas été trouvé
    if (current == NULL) {
        cerr << "Error: Client not found in the shop!" << endl;
        return false;
    }

    // Couper la connexion entre le client et le vélo s'il est associé à un vélo
    if (current->getBike() != NULL) {
        current->getBike()->changeUser(NULL);
    }

    // Si le client à supprimer est le premier de la liste
    if (previous == NULL) {
        clientList = clientList->getNextClient();
    } else {
        previous->getNextClient() = current->getNextClient();
    }

    // Définir next sur NULL pour éviter les références invalides
    current->getNextClient() = NULL;
    current->setRentalShop(NULL);

    cout << "Client removed successfully!" << endl;
    return true;
}

bool BikeRentalShop::removeEmployee(Employee* employeeToRemove) {
    if (employeeToRemove == NULL) {
        cerr << "Error: Invalid employee!" << endl;
        return false;
    }

    if (employeeList == NULL) {
        cerr << "Error: No employees in the shop!" << endl;
        return false;
    }

    Employee* current = employeeList;
    Employee* previous = NULL;

    // Recherche de l'employé à supprimer
    while (current != NULL && current != employeeToRemove) {
        previous = current;
        current = current->getNextEmployee();
    }

    // Si l'employé n'a pas été trouvé
    if (current == NULL) {
        cerr << "Error: Employee not found in the shop!" << endl;
        return false;
    }

    // Si l'employé à supprimer est le premier de la liste
    if (previous == NULL) {
        employeeList = employeeList->getNextEmployee();
    } else {
        previous->getNextEmployee() = current->getNextEmployee();
    }

    // Définir next sur NULL pour éviter les références invalides
    current->getNextEmployee() = NULL;
    current->setRentalShop(NULL);

    cout << "Employee removed successfully!" << endl;
    return true;
}

bool BikeRentalShop::removeBike(Bike* bikeToRemove) {
    if (bikeToRemove == NULL) {
        cerr << "Error: Invalid bike!" << endl;
        return false;
    }

    if (bikeList == NULL) {
        cerr << "Error: No bikes in the shop!" << endl;
        return false;
    }

    Bike *current = bikeList;
    Bike *previous = NULL;

    // Recherche du vélo à supprimer
    while (current != NULL && current != bikeToRemove) {
        previous = current;
        current = current->getNextBike();
    }

    // Si le vélo n'a pas été trouvé
    if (current == NULL) {
        cerr << "Error: Bike not found in the shop!" << endl;
        return false;
    }

    // Couper la connexion entre le vélo et le client s'il est associé à un client
    if (current->getUser() != NULL) {
        current->getUser()->changeBike(NULL);
    }

    // Si le vélo à supprimer est le premier de la liste
    if (previous == NULL) {
        bikeList = bikeList->getNextBike();
    } else {
        previous->getNextBike() = current->getNextBike();
    }

    // Remettre la variable rentalShop à NULL
    bikeToRemove->setRentalShop(NULL);

    cout << "Bike removed successfully!" << endl;
    return true;
}

