//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/Box.h"

Box::Box(int position) {

    if(position == 0) {
        type = BoxType::angular;
        isStart = true;
    }
    else if(position == 7 || position == 14 || position == 21)
        type = BoxType::angular;
    else
        type = BoxType::lateral;
}



std::ostream& operator<<(std::ostream& os, Box& obj) {

    if( static_cast<int>(obj.getType()) == 0 && obj.getStart())
        os << "|P|'";
    else if(static_cast<int>(obj.getType()) == 0)
        os << "| |";
    else
        os << "E";

    return os;
}