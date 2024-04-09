#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class BikeRentalShop; // Déclaration anticipée de la classe BikeRentalShop

class Employee {
private:
    string name;
    string employeeID;
    string rentalShopId; // Utilisation d'un objet string pour rentalShopId
public:
    Employee(const string& n, const string& id);
    ~Employee();

    void printEmployee() const;
    const string& getName() const;
    const string& getEmployeeID() const;
    const string& getRentalShopId() const; // Getter pour le magasin de location
};

#endif // EMPLOYEE_H
