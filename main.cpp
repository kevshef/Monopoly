#include "include/Board.h"
#include "include/Game.h"


#include <iostream>

int main() {

    Board board;

    std::cout << board;



    Game gioco("human", board);

    std::cout << gioco;

    gioco.start();

    int turno = 0;


    do {

        std::cout << "\n\n turno " << (turno + 1) << " : \n";

        for(int i = 0; i < 4; i++) {
            if(!gioco.getPlayers()[i]->isBankrupt()) {
                int moveResult = gioco.move(board, i);
            }

        }

        std::cout << board;
        turno++;

    } while(!gioco.end());

    return 0;
}
