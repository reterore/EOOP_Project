#include "Employee.h"

Employee::~Employee() {
    cout << "Employee " << getName() << " (ID:" << employeeId << ") destroyed!\n";
    // Libérer la mémoire allouée pour le nom de l'employé
    delete[] name;
    // Libérer la mémoire allouée pour l'ID de l'employé
    delete[] employeeId;
}



void Employee::printEmployee() const {
    cout << "- (ID:" << employeeId << ") | name: " << name << " at : " << rentalShopId << endl;
}
