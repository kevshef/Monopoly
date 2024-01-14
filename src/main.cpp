/**
 * Filename: main.cpp
 * Author: Zarantonello Michele
 * Created: 05/01/2024
 **/

#include "../include/Board.h"
#include "../include/Game.h"

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

    Game gioco(temp, board);

    std::cout << gioco;

    int numeroTurni = 1;

    gioco.play(board, numeroTurni);

    return 0;
}
