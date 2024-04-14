#ifndef EOOP_PROJECT_BIKERENTALSHOP_H
#define EOOP_PROJECT_BIKERENTALSHOP_H

#include "Client.h"
#include "Employee.h"
#include "Bike.h"

class BikeRentalShop {
private:
    string id;
    struct clientNode{
        Client* client;
        Bike* bike;
        clientNode* next;
    };
    clientNode* HeadClient;
    struct employeeNode{
        Employee* employee;
        employeeNode* next;
    };
    employeeNode* HeadEmployee;
    struct bikeNode{
        Bike* bike;
        Client* user;
        bikeNode* next;
    };
    bikeNode* HeadBike;

public:
    BikeRentalShop(const string& shopId);
    ~BikeRentalShop();
    void print() const;
    const string& getId() const { return id;}
    bool insertClient(Client* client);
    bool insertEmployee(Employee* employee);
    bool insertBike(Bike* bike);
    template<typename T>
    bool insert(T* data);
    bool rent(Client* client, Bike* bike);
    bool stopRental(Client* client);
    bool removeClient(Client* client);
    bool removeEmployee(Employee* employee);
    bool removeBike(Bike* bike);
};

#endif // EOOP_PROJECT_BIKERENTALSHOP_H
