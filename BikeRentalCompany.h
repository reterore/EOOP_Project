//
// Created by lucas on 25/03/2024.
//

#ifndef EOOP_PROJECT_BIKERENTALCOMPANY_H
#define EOOP_PROJECT_BIKERENTALCOMPANY_H

#include "BikeRentalShop.h"
#include "cstring"

class BikeRentalCompany {
private:
    BikeRentalShop* head;
    int shopNb;
public:
    BikeRentalCompany();
    ~BikeRentalCompany();
    BikeRentalShop* getHead();
    void print();
    bool insertShop(BikeRentalShop* bikeRentalShop);
    bool removeShop(BikeRentalShop* bikeRentalShop);
    bool removeShop(const char* shopId);

};


#endif //EOOP_PROJECT_BIKERENTALCOMPANY_H
