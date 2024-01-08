#include "include/Board.h"
#include "include/Game.h"
#include <cstring>


#include <iostream>

int main(int argc, char *argv[]) {

    const char *temp;

    if (argc != 2) {
        std::cout << "Incorrect number of line arguments: must be 'human' or 'computer' \n";
        exit(1);
    }
    if (argv[1] != nullptr && strcmp(argv[1], "computer") == 0 || strcmp(argv[1], "COMPUTER") == 0) {
        temp = static_cast<const char *>(argv[1]);
    } else if (argv[1] != nullptr && strcmp(argv[1], "human") == 0 || strcmp(argv[1], "HUMAN") == 0) {
        temp = static_cast<const char *>(argv[1]);
    } else {
        std::cout << "invalid command line argument: must be 'human' or 'computer' \n";
        exit(1);
    }

    Board board;

    std::cout << board;

    Game gioco(temp, board);

    std::cout << gioco;

    gioco.start();

    int turno = 0;

    do {

        std::cout << "\n\n turno " << (turno + 1) << " : \n";

        for (int i = 0; i < 4; i++) {
            if (!gioco.getPlayers()[i]->isBankrupt()) {
                gioco.move(board, i);
            }
        }

        turno++;

    } while (!gioco.end() && turno < 5000);

    int id = gioco.richestPlayer();

    std::cout << "\nIl vincitore è il giocatore " << gioco.getPlayers()[id]->getNumber() << " con un saldo di: "
              << gioco.getPlayers()[id]->getBalance() << " fiorini.\n";

    std::cout << board;

    for (int i = 0; i < gioco.getPlayers().size(); ++i) {
        std::cout << "Giocatore " << gioco.getPlayers()[i]->getNumber() << ": ";
        for (int j = 0; j < board.getBoard().size(); ++j) {
            if (board.getBoard()[j].getOwnerNumber() == gioco.getPlayers()[i]->getNumber()) {
                std::cout << board.getCoordinates(j) << board.getBoard()[j].getIdentifying() << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
