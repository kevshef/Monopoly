//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/ScoreBoard.h"


ScoreBoard::ScoreBoard() {

    for(int i = 0; i < 32; i++) {
        board.push_back(i);
    }

}

std::ostream& operator<<(std::ostream& os, ScoreBoard& obj) {
    std::vector<Box> temp = obj.getBoard();
    for(int i = 0; i < 32 ; i++) {
       if(i%8 == 0) {
           os << "\n";
           os << "A";
       }
       if(i < 8)
           os << i;
       os << temp[i] << " ";
    }

    return os;

}