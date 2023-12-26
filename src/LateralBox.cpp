//
// Created by
//

#include "../include/LateralBox.h"

LateralBox::LateralBox(int n) {
    free = true;
    switch (n) {
        case 0:
            identifying = "E";
            price = 6;
            house_price = 3;
            hotel_price = 3;
            daily_house_price = 2;
            daily_hotel_price = 4;
            break;
        case 1:
            identifying = "S";
            price = 10;
            house_price = 5;
            hotel_price = 5;
            daily_house_price = 4;
            daily_hotel_price = 8;
            break;
        case 2:
            identifying = "L";
            price = 20;
            house_price = 10;
            hotel_price = 10;
            daily_house_price = 7;
            daily_hotel_price = 14;
            break;
    }
}