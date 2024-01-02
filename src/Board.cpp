//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/Board.h"


Board::Board() {

    srand(static_cast<unsigned int>(std::time(nullptr)));

    bool isEnd = true;

    int counts[] = {8, 10, 6};

    for (int i = 0; i < 28; i++) {
        bool isEnd = true;

        do {
            int temp = rand() % 3;

            if (i == 0 || i == 7 || i == 20 || i ==  27) {
                board.push_back(Box(i, 4));
                isEnd = false;
            } else if(counts[temp] > 0) {
                counts[temp]--;
                board.push_back(Box(i, temp));
                isEnd = false;
            }
        } while (isEnd);
    }
}



/**
 *
 * @param os
 * @param obj
 * @return os
 *
 * Metodo che deve ancora essere sistemato, ha problemi su print tipo quando si costriusicono case.
 */
std::ostream& operator<<(std::ostream& os, Board& obj) {

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
    }

   }

    os << "\n";

    return os;

}
