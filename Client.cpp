#include "Client.h"
#include <iostream>
#include "cstring"

Client::Client(const char* name, const char* id) : rentalShopId("") {
    if (!name) {
        // Default Name
        this->name = new char[strlen("DefaultClientName") + 1];
        strcpy(this->name, "DefaultClientName");
    } else {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    if (!id) {
        // Default Id
        this->clientID = new char[strlen("DefaultClientId") + 1];
        strcpy(this->clientID, "DefaultClientId");
    } else {
        this->clientID = new char[strlen(id) + 1];
        strcpy(this->clientID, id);
    }
}

Client::~Client() {
    cout << "Client " << name << " (ID:" << clientID << ") destroyed!\n";
    // Libérer la mémoire allouée pour le nom du client
    delete[] name;
    // Libérer la mémoire allouée pour l'ID du client
    delete[] clientID;
}



void Client::printClient() const {
    cout << "- (ID:" << clientID << ") | name: " << name  << " at : " << rentalShopId << endl;
}

