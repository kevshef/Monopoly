//
// Created by
//

#ifndef MONOPOLY_LATERALBOX_H
#define MONOPOLY_LATERALBOX_H

#include "../include/Box.h"

class LateralBox : public Box {

public:

    LateralBox(int n);

    int price;

    int house_price;

    int hotel_price;

    int daily_house_price;

    int daily_hotel_price;

};


#endif //MONOPOLY_LATERALBOX_H
