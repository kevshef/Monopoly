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

        turno++;

    } while(!gioco.end() && turno < 5000);

    int id = gioco.requestPlayer();
    std::cout << "Il vincitore è il giocatore " << gioco.getPlayers()[id]->getNumber() << " con un saldo di: " << gioco.getPlayers()[id]->getBalance();

    return 0;
}
