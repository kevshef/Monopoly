//
// Created by Kevin Shefkiu on 26/12/23.
//

#ifndef MONOPOLY_BOX_H
#define MONOPOLY_BOX_H

#include <iostream>

enum class PropertyType {
    economic = 0, standard, luxury
};

enum class BoxType {
    angular = 0, lateral
};

class Box {

private:

    void setProperty(int n);

    char identifying_building;

    BoxType type;

    PropertyType property_type;

    bool free;

    int price;

    int house_price;

    int hotel_price;

    int daily_house_price;

    int daily_hotel_price;

    bool isStart = false;

public:

    Box(int position, int property_type);

    char getIdentifying() const { return identifying_building; }

    void setIdentifying(char c) { identifying_building = c; }

    BoxType getType() const { return type; }

    PropertyType getPropertyType() const { return property_type; }

    bool getStart() const { return isStart; }

};

std::ostream& operator<<(std::ostream& os, Box& obj);

#endif //MONOPOLY_BOX_H
