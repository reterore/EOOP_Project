#include "BikeRentalCompany.h"

int Test = 0;

void print_test();

int main() {

    print_test();

    BikeRentalCompany Main;
    Main.print();

    print_test();

    BikeRentalShop bikeRentalShop1("Warsaw");
    Main.insertShop(&bikeRentalShop1);
    Main.print();

    print_test();

    Employee employee1("victor", "1");
    bikeRentalShop1.insertEmployee(&employee1);
    Employee employee2("Roman", "2");
    bikeRentalShop1.insertEmployee(&employee2);
    Client client1("Emile", "1");
    bikeRentalShop1.insertClient(&client1);
    Client client2("Martin", "2");
    bikeRentalShop1.insertClient(&client2);
    Bike bike1("BMX", "1", 20);
    bikeRentalShop1.insertBike(&bike1);
    Bike bike2("BMX", "2", 20);
    bikeRentalShop1.insertBike(&bike2);
    Main.print();

    print_test();

    BikeRentalShop bikeRentalShop2("Paris");
    Main.insertShop(&bikeRentalShop2);
    Employee employee3("Julie", "3");
    bikeRentalShop2.insertEmployee(&employee3);
    Employee employee4("Lisa", "4");
    bikeRentalShop2.insertEmployee(&employee4);
    Client client3("Emilie", "3");
    bikeRentalShop2.insertClient(&client3);
    Client client4("Charlotte", "4");
    bikeRentalShop2.insertClient(&client4);
    Bike bike3("BMX", "3", 20);
    bikeRentalShop2.insertBike(&bike3);
    Bike bike4("BMX", "4", 20);
    bikeRentalShop2.insertBike(&bike4);
    Main.print();

    print_test();
    bikeRentalShop1.rent(&client1, &bike1);
    bikeRentalShop1.rent(NULL, &bike1);
    bikeRentalShop1.rent(&client1, NULL);
    bikeRentalShop1.rent(&client1, &bike1);
    bikeRentalShop1.rent(&client2, &bike1);
    bikeRentalShop1.rent(&client3, &bike1);
    bikeRentalShop1.rent(&client3, &bike1);

    print_test();
    Main.removeShop(&bikeRentalShop2);
    bikeRentalShop1.stopRental(&client1);
    Main.print();

    print_test();// ICI
    BikeRentalShop bikeRentalShopTest("Test");
    // Créer des employés
    Employee emp1("John", "E1");
    Employee emp2("Alice", "E2");
    bikeRentalShopTest.insertEmployee(&emp1);
    bikeRentalShopTest.insertEmployee(&emp2);
    Client clientTest("Bob", "C1");
    bikeRentalShopTest.insertClient(&clientTest);
    Bike bikeTest("Mountain Bike", "B1", 20);
    bikeRentalShopTest.insertBike(&bikeTest);
    bikeRentalShopTest.print();

    bikeRentalShopTest.removeEmployee(&emp1);
    bikeRentalShopTest.removeEmployee(&emp2);
    bikeRentalShopTest.removeClient(&clientTest);
    bikeRentalShopTest.removeBike(&bikeTest);
    bikeRentalShopTest.print();

    bikeRentalShopTest.insertEmployee(&employee1);
    bikeRentalShopTest.insertClient(&client1);
    bikeRentalShopTest.insertBike(&bike1);

    bikeRentalShopTest.print();
    bikeRentalShop1.print();

    print_test();

    bikeRentalShop1.insertEmployee(&employee1);

    cout << endl;
    cout << "End of code, destruction of the objects:\n";
    cout << endl;

    return 0;
}

void print_test(){
    Test++;
    cout << endl;
    cout << "-------------TEST" << Test << "-------------" << endl;
    cout << endl;
}