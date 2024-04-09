#include "Employee.h"

Employee::Employee(const string& n, const string& id) : name(n), employeeID(id) {}

Employee::~Employee() {
    cout << "Employee " << getName() << " (ID:" << employeeID << ") destroyed!\n";
}

void Employee::printEmployee() const {
    cout << "- (ID:" << employeeID << ") | name: " << name << endl;
}

const string& Employee::getName() const {
    return name;
}

const string& Employee::getEmployeeID() const {
    return employeeID;
}

const string& Employee::getRentalShopId() const {
    return rentalShopId;
}
