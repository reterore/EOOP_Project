//
// Created by lucas on 25/03/2024.
//

#ifndef EOOP_PROJECT_BIKERENTALCOMPANY_H
#define EOOP_PROJECT_BIKERENTALCOMPANY_H

#include "BikeRentalShop.h"
#include "cstring"

class BikeRentalCompany {
private:
    struct shopNode{
        BikeRentalShop* shop;
        shopNode* next;
    };
    int numberOfShops;
    shopNode* head;
public:
    BikeRentalCompany();
    ~BikeRentalCompany();
    void print();
    bool insertShop(BikeRentalShop* bikeRentalShop);
    bool removeShop(BikeRentalShop* bikeRentalShop);
    bool removeShop(const string& shopId);
};

#endif //EOOP_PROJECT_BIKERENTALCOMPANY_H
