#include "Employee.h"
#include "BikeRentalShop.h" // Inclusion de la classe BikeRentalShop

Employee::Employee(const string& n, const string& id) : name(n), employeeID(id), next(NULL), rentalShop(NULL) {}

Employee::~Employee() {
}

void Employee::printEmployee() const {
    cout << "Employee Name: " << name << " | Employee ID: " << employeeID << endl;
}

const string& Employee::getName() const {
    return name;
}

const string& Employee::getEmployeeID() const {
    return employeeID;
}

Employee*& Employee::getNextEmployee() {
    return next;
}

void Employee::setRentalShop(BikeRentalShop* shop) {
    rentalShop = shop;
}

BikeRentalShop* Employee::getRentalShop() const {
    return rentalShop;
}
