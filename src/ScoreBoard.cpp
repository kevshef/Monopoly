//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/ScoreBoard.h"
#include <cstdlib>
#include <ctime>

ScoreBoard::ScoreBoard() {
    srand(static_cast<unsigned int>(std::time(nullptr)));

    for(int i = 0; i < 28; i++) {
        int temp = rand()%3;
        board.push_back(Box(i, temp));
    }
}

std::ostream& operator<<(std::ostream& os, ScoreBoard& obj) {

    std::vector<Box> temp = obj.getBoard();
    char c = 'A';
    os << "\t1\t2\t3\t4\t5\t6\t7\t8\n";

    for( int i = 0; i < 28; i++ ) {

        if( i == 0 || (i > 7 && i % 2 == 0) && i < 21)
            os << c++ << "\t";

        if (i < 8 || i > 19) {
            os << temp[i] << " ";

            if (i == 7)
                os << "\n";

        } else {

            os <<temp[i] << "\t\t\t\t\t\t\t" << temp[i + 1] << "\n";
            i++;

        }

    }

    return os;

}
