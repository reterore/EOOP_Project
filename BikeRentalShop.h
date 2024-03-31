#ifndef EOOP_PROJECT_BIKERENTALSHOP_H
#define EOOP_PROJECT_BIKERENTALSHOP_H

#include "Client.h"
#include "Employee.h"
#include "Bike.h"

class BikeRentalShop {
private:
    char* id; // Utiliser std::string serait plus sûr et pratique
    Client* clientList;
    Employee* employeeList;
    Bike* bikeList;
    BikeRentalShop* next;

public:
    BikeRentalShop(const char* shopId);
    ~BikeRentalShop();
    void print() const;
    char* getId();
    BikeRentalShop*& getNextShop();
    bool insertClient(Client* client);
    bool insertEmployee(Employee* employee);
    bool insertBike(Bike* bike);
    bool rent(Client* client, Bike* bike);
    bool removeClient(Client* client);
    bool removeEmployee(Employee* employee);
    bool removeBike(Bike* bike);
};

#endif // EOOP_PROJECT_BIKERENTALSHOP_H
