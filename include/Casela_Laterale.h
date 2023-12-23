//
// Created by Alvise Garberino on 23/12/23.
//

#ifndef MONOPOLY_CASELA_LATERALE_H
#define MONOPOLY_CASELA_LATERALE_H

#include "../include/Casella.h"

#include <string>

enum class Typology {
    economic = 0, standard, luxury
};

class Casella_Laterale : public Casella {

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

#endif //MONOPOLY_CASELA_LATERALE_H
