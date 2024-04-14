#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class BikeRentalShop; // Déclaration anticipée de la classe BikeRentalShop

class Employee {
private:
    string name;
    string employeeId;
    string rentalShopId; // Utilisation d'un objet string pour rentalShopId
public:
    Employee(const string& n, const string& id);
    ~Employee();

    void printEmployee() const;
    const string& getName() const {return name;}
    const string& getEmployeeID() const {return employeeId;}
    const string& getRentalShopId() const {return rentalShopId;} // Getter pour le magasin de location
    void setRentalShopId(const string& id);
};

#endif // EMPLOYEE_H
