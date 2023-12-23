//
// Created by Alvise Garberino on 23/12/23.
//

#include "../include/Casella.h"
#include "../include/Casella_Laterale.h"

void Casella_Laterale::setType(int n) {
    if(n > 2 || n < 0)
        throw std::invalid_argument("Invalid Typology.");

    switch(n) {
        case 0:
            break;
        case 1;
            break;
        case 2:
            break;
    }
}
