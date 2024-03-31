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
    Employee* next;
    BikeRentalShop* rentalShop; // Pointeur vers le magasin associé

public:
    Employee(const string& n, const string& id);
    ~Employee();

    void printEmployee() const;

    const string& getName() const;
    const string& getEmployeeID() const;
    Employee*& getNextEmployee();
    void setRentalShop(BikeRentalShop* shop); // Setter pour le pointeur vers le magasin
    BikeRentalShop* getRentalShop() const; // Getter pour le pointeur vers le magasin
};

#endif // EMPLOYEE_H
