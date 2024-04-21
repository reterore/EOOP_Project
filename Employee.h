#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

using namespace std;

class BikeRentalShop; // Forward declaration of the BikeRentalShop class

class Employee {
private:
    char* name;
    char* employeeId;
    char* rentalShopId; // Using a char* object for rentalShopId

    friend class BikeRentalShop; // to access data from bikeRentalShop methods

public:
    // Constructor to initialize an Employee object with provided name and ID
    Employee(const char* n, const char* id);

    // Destructor to clean up resources associated with the Employee object
    ~Employee();

    // Method to print the details of the employee
    void printEmployee() const;

    // Getter methods to retrieve information about the employee
    const char* getName() const {return name;}
    const char* getEmployeeID() const {return employeeId;}
    const char* getRentalShopId() const {return rentalShopId;} // Getter for the rental shop

};

#endif // EMPLOYEE_H
