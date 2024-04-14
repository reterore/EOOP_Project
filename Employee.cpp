#include "Employee.h"

Employee::Employee(const string& n, const string& id) : name(n), employeeId(id), rentalShopId("") {}

Employee::~Employee() {
    cout << "Employee " << getName() << " (ID:" << employeeId << ") destroyed!\n";
}

void Employee::printEmployee() const {
    cout << "- (ID:" << employeeId << ") | name: " << name << endl;
}


void Employee::setRentalShopId(const string& id) {
    rentalShopId = id;
}