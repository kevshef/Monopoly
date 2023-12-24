//
// Created by Alvise Garberino on 23/12/23.
//

#ifndef MONOPOLY_LATERALBOX_H
#define MONOPOLY_LATERALBOX_H

#include "../include/Box.h"

#include <string>

enum class Typology {
    economic = 0, standard, luxury
};

class LateralBox : public Casella {

public:

    Casella_Laterale(int n)

    Typology type;

    int price;

    std::string owner;

    bool house;

    bool hotel;

    int house_price;

    int hotel_price;

    int daily_house_price;

    int daily_hotel_price;

};

#endif //MONOPOLY_LATERALBOX_H
