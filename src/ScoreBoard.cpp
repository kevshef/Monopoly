//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/ScoreBoard.h"


ScoreBoard::ScoreBoard() {

    for(int i = 0; i < 28; i++) {
        board.push_back(i);
    }

}

std::ostream& operator<<(std::ostream& os, ScoreBoard& obj) {

    std::vector<Box> temp = obj.getBoard();
    char c = 'A';
    os << " 1\t2\t3\t4\t5\t6\t7\t8\n";
    for( int i = 0; i < 28; i++ ) {
        if( i == 0 || (i > 7 && i % 2 == 0))
            os << c++ << "\t";

        if (i < 8 || i > 19) {


            os << temp[i] << " ";
            if (i == 7) {
                os << "\n";
            }
        } else {
            os <<temp[i] << "\t\t\t\t\t\t\t" << temp[i + 1] << "\n";
            i++;
        }

    }

    return os;

}