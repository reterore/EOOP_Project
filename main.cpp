#include "BikeRentalCompany.h"

int Test = 0;

void print_test();

int main() {

    print_test(); // Test 1 : creation of the company and its displat while empty

    BikeRentalCompany Main;
    Main.print();

    print_test(); // Test 2 : creation of a rentalshop with a valid name and with a NULL name and their displays

    BikeRentalShop bikeRentalShop1("Warsaw");
    Main.insertShop(&bikeRentalShop1);
    Main.print();

    BikeRentalShop bikeRentalShop2(NULL);
    Main.insertShop(&bikeRentalShop2);
    Main.print();

    print_test(); // creation of Employees, clients and bikes, with a valid name and id, and with a NULL name and a NULL id
                  // and insertion in the shops. Then we display the company.

    Employee employee1("victor", "1");
    bikeRentalShop1.insert(&employee1);
    Employee employee2(NULL, NULL);
    bikeRentalShop2.insert(&employee2);
    Client client1("Emile", "1");
    bikeRentalShop1.insert(&client1);
    Client client2(NULL, NULL);
    bikeRentalShop2.insert(&client2);
    Bike bike1("BMX", "1", 20);
    bikeRentalShop1.insert(&bike1);
    Bike bike2(NULL, NULL, 20);
    bikeRentalShop2.insert(&bike2);
    Main.print();

    print_test(); // Try different renting case

    bikeRentalShop1.rent(&client1, &bike1);
    bikeRentalShop1.rent(&client2, &bike1);
    bikeRentalShop1.rent(&client1, &bike2);
    bikeRentalShop1.rent(NULL, &bike1);
    bikeRentalShop1.rent(&client1, NULL);
    Main.print(); // see if the renting of bike1 by client1 appears correctly

    print_test(); // Stop renting for all case and remove elements from shops:

    bikeRentalShop1.stopRental(&client1);
    bikeRentalShop1.stopRental(&bike1);
    bikeRentalShop1.stopRental(&client2);
    bikeRentalShop1.stopRental(&bike2);
    bikeRentalShop1.remove(&employee1);
    bikeRentalShop2.remove(&client2);
    Main.print();

    print_test(); // Do a bunch of tests for the Company's methods (it is supposed to use all previous methods for inserting, removing, etc...)

    // try to insert with a NULL Id for the shop
    Main.insert(NULL, &employee1);
    Main.insert(NULL, &client1);
    Main.insert(NULL, &bike1);

    // try to insert with a non-existing Id for the shop
    Main.insert("New-York", &employee1);
    Main.insert("New-York", &client1);
    Main.insert("New-York", &bike1);

    // try to insert with an existing Id for the shop
    Main.insert("Warsaw", &employee1);
    Main.insert("Warsaw", &client1);
    Main.insert("Warsaw", &bike1);

    // try to rent a bike by giving a NULL shop Id
    Main.rent(NULL, &client1, &bike1);
    // rent the bike with a name on-existing in the company
    Main.rent("New-York", &client1, &bike1);
    // rent the bike with a name existing in the company
    Main.rent("New-York", &client1, &bike1);

    // try to stop a renting with a NULL id
    Main.stopRental(NULL, &client1);
    Main.stopRental(NULL, &bike1);

    // try to stop a renting with a non-existing Id
    Main.stopRental("New-York", &client1);
    Main.stopRental("New-York", &bike1);

    // try to stop a renting with an existing Id
    Main.stopRental("Warsaw", &client1);
    Main.stopRental("Warsaw", &bike1);

    // try to remove with a NULL Id for the shop
    Main.remove(NULL, &employee1);
    Main.remove(NULL, &client1);
    Main.remove(NULL, &bike1);

    // try to remove with a non-existing Id for the shop
    Main.remove("New-York", &employee1);
    Main.remove("New-York", &client1);
    Main.remove("New-York", &bike1);

    // try to remove with an existing Id for the shop
    Main.remove("Warsaw", &employee1);
    Main.remove("Warsaw", &client1);
    Main.remove("Warsaw", &bike1);

    return 0;
}

void print_test(){ // this function is just to have a separation for the different parts of the testing in the terminal window
    Test++;
    cout << endl;
    cout << "-------------TEST" << Test << "-------------" << endl;
    cout << endl;
}