/**

#ifndef MONOPOLY_LATERALBOX_H
#define MONOPOLY_LATERALBOX_H

#include "../include/Box.h"



class LateralBox : public Box {

public:

    LateralBox(int n);

    BoxType type;

    bool free;

    int price;

    int house_price;

    int hotel_price;

    int daily_house_price;

    int daily_hotel_price;

    char getIdentifyingType();

    virtual char getIdentifying() { return identifying_building; }

    virtual void setIdentifying(char c) { identifying_building = c; }

    BoxType getBoxType() { return type; }

};

#endif //MONOPOLY_LATERALBOX_H
**/