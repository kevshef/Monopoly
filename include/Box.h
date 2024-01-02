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

    std::string identifying_building;

    BoxType type;

    PropertyType property_type;

    int owner_number = -1;

    bool free = false;

    int price;

    int house_price;

    int hotel_price;

    int daily_house_price;

    int daily_hotel_price;

    bool isStart = false;

public:

    Box(int position, int property_type);

    std::string getIdentifying() const { return identifying_building; }

    void setIdentifying(char c) { identifying_building = c; }

    BoxType getType() const { return type; }

    PropertyType getPropertyType() const { return property_type; }

    bool getStart() const { return isStart; }

    bool isFree() const { return free; }

    int getPrice() const { return price; }

    int getHousePrice() const { return house_price; }

    int getHotelPrice() const { return hotel_price; }

    int getDailyHousePrice() const { return daily_house_price; }

    int getDailyHotelPrice() const { return daily_hotel_price; }

    void setNotFree(int n);

    int getOwnerNumber() const { return owner_number; }

};

std::ostream& operator<<(std::ostream& os, Box& obj);

#endif //MONOPOLY_BOX_H
