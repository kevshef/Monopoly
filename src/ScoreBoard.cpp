//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/ScoreBoard.h"


ScoreBoard::ScoreBoard() {

    for(int i = 0; i < 28; i++) {
        int temp = std::rand()%3;
        board.push_back(Box(i, temp));
    }
}

std::ostream& operator<<(std::ostream& os, ScoreBoard& obj) {

    std::vector<Box> temp = obj.getBoard();
    char c = 'A';
    os << "\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\n";

    for( int i = 0; i < 28; i++ ) {

        if( i == 0 || (i > 7 && i % 2 == 0) && i < 21)
            os << c++ << "\t";

        if (i < 8 || i > 19) {
            os << temp[i] << "\t";

            if (i == 7)
                os << "\n";

        } else {

            os <<temp[i] << "\t\t\t\t\t\t\t" << temp[i + 1] << "\n";
            i++;

        }
        if(i == 27)
            os<<"\n";

    }

    return os;

}
