#include "BikeRentalCompany.h"

int Test = 0;

void print_test();

int main() {

    print_test(); // Test 1 : creation of the company and its displat while empty

    BikeRentalCompany Main;
    Main.print();

    print_test(); // Test 2 : creation of a rentalshop with a valid name and with a NULL name and their displays

    Main.insertShop("Warsaw");

    Main.insertShop(NULL);

    Main.insertShop("Paris");

    Main.removeShop("Paris");

    Main.insertClient("Warsaw", "Lucas", "01");
    Main.insertEmployee("Warsaw", "Emrick", "01");
    Main.insertBike("Warsaw", "BMX", "01", 10);

    Main.rent("Warsaw", "01", "01");
   Main.clear();
    Main.print();



    print_test(); // Try different renting case

    return 0;
}

void print_test(){ // this function is just to have a separation for the different parts of the testing in the terminal window
    Test++;
    cout << endl;
    cout << "---------------TEST" << Test << "---------------" << endl;
    cout << endl;
}