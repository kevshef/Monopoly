//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/Board.h"


Board::Board() {

    srand(static_cast<unsigned int>(std::time(nullptr)));

    int economic_count = 0;
    int standard_count = 0;
    int luxury_count = 0;

    for(int i = 0; i < 28; i++) {

        bool isEnd = true;

        do {
            int temp = rand()%3;

            if (i == 0 || i == 7 || i == 20 || i == 27) {
                board.push_back(Box(i, 0));
                isEnd = false;
            } else if(temp == 0 && economic_count < 8) {
                economic_count++;
                board.push_back(Box(i, temp));
                isEnd = false;
            } else if (temp == 1 && standard_count < 10) {
                standard_count++;
                board.push_back(Box(i, temp));
                isEnd = false;
            } else if(temp == 2 && luxury_count < 6) {
                luxury_count++;
                board.push_back(Box(i, temp));
                isEnd = false;
            }
            
        } while(isEnd);


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
        if(i == 27)
            os<<"\n";

    }

    return os;

}
