#include "BikeRentalCompany.h"

int main() {
    Employee employee1("steve", "1");
    Employee employee2("jules", "2");

    Client client1("Victor", "1");
    Client client2("Roman", "2");
    Client client3("Tyler", "3");

    Bike bike1("BMX", "01", 20);
    Bike bike2("BMX", "02", 20);

    BikeRentalShop bikeRentalShop1("Warsaw");
    BikeRentalShop bikeRentalShop2("Paris");
    BikeRentalShop bikeRentalShop3("Warsaw");


    bikeRentalShop1.insertEmployee(&employee1);
    bikeRentalShop1.insertEmployee(&employee2);

    bikeRentalShop1.insertClient(&client1);
    bikeRentalShop1.insertClient(&client2);

    bikeRentalShop1.insertBike(&bike1);
    bikeRentalShop1.insertBike(&bike2);

    bikeRentalShop1.rent(&client1, &bike1);
    bikeRentalShop1.rent(&client2, &bike2);

    cout << "-------------TEST1-------------" << endl;
    BikeRentalCompany Main;
    Main.print();
    cout << endl;

    cout << "-------------TEST2-------------" << endl;
    Main.insertShop(&bikeRentalShop1);
    Main.print();
    cout << endl;

    cout << "-------------TEST3-------------" << endl;
    Main.insertShop(&bikeRentalShop2);
    Main.print();
    cout << endl;

    cout << "-------------TEST4-------------" << endl;
    bikeRentalShop2.insertEmployee(&employee1);
    bikeRentalShop2.insertClient(&client1);
    bikeRentalShop2.insertBike(&bike1);
    cout << endl;
    bikeRentalShop1.removeEmployee(&employee1);
    bikeRentalShop1.removeClient(&client1);
    bikeRentalShop1.removeBike(&bike2);
    cout << endl;
    Main.print();

    cout << "-------------TEST5-------------" << endl;
    Main.removeShop("Paris");
    Main.insertShop(&bikeRentalShop3);
    Main.print();

    cout << "-------------TEST6-------------" << endl;
    Main.removeShop(&bikeRentalShop3);
    bikeRentalShop1.insertBike(&bike2);
    bikeRentalShop1.insertClient(&client1);
    bikeRentalShop1.insertEmployee(&employee1);
    Main.print();


    return 0;
}
