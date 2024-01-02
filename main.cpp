//
// Created by
//

#include "include/Board.h"
#include "include/Players.h"

#include <iostream>

int main() {
    Board scoreboard;

    std::cout << scoreboard;

    Players players(1);

    std::cout << players;

    std::cout<< "\nRisultato movimento: " << players.Move(scoreboard, 0);

    std::cout << "\nPosizione: " << players.getPlayers().at(0).getPosition();

    std::cout << "\nR" << scoreboard.getBoard().at(players.getPlayers().at(0).getPosition());


    return 0;
}
