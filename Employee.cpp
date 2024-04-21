#include "Employee.h"
#include "cstring"

Employee::Employee(const char* n, const char* id) : rentalShopId("") {
    if (!n) {
        // Default Name
        this->name = new char[strlen("DefaultEmployeeName") + 1];
        strcpy(this->name, "DefaultEmployeeName");
    } else {
        this->name = new char[strlen(n) + 1];
        strcpy(this->name, n);
    }
    if (!id) {
        // Default Id
        this->employeeId = new char[strlen("DefaultEmployeeId") + 1];
        strcpy(this->employeeId, "DefaultEmployeeId");
    } else {
        this->employeeId = new char[strlen(id) + 1];
        strcpy(this->employeeId, id);
    }
}


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
