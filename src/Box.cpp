//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/Box.h"

Box::Box(int position, int property_type) {

    if(position == 0) {
        type = BoxType::angular;
        isStart = true;
    } else if(position == 7 || position == 20 || position == 27)
        type = BoxType::angular;
    else
        setProperty(property_type);
}

void Box::setProperty(int n) {
    free = true;
    type = BoxType::lateral;
    switch (n) {
        case 0:
            property_type = PropertyType::economic;
            identifying_building = "|E|";
            price = 6;
            house_price = 3;
            hotel_price = 3;
            daily_house_price = 2;
            daily_hotel_price = 4;
            break;
        case 1:
            property_type = PropertyType::standard;
            identifying_building = "|S|";
            price = 10;
            house_price = 5;
            hotel_price = 5;
            daily_house_price = 4;
            daily_hotel_price = 8;
            break;
        case 2:
            property_type = PropertyType::luxury;
            identifying_building = "|L|";
            price = 20;
            house_price = 10;
            hotel_price = 10;
            daily_house_price = 7;
            daily_hotel_price = 14;
            break;
    }
}


std::ostream& operator<<(std::ostream& os, Box& obj) {

    if( static_cast<int>(obj.getType()) == 0 && obj.getStart())
        os << "|P|";
    else if(static_cast<int>(obj.getType()) == 0)
        os << "| |";
    else {
            os << obj.getIdentifying();
    }

    return os;
}