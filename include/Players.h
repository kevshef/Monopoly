//
// Created by Alvise Garberino on 02/01/24.
//

#ifndef MONOPOLY_PLAYERS_H
#define MONOPOLY_PLAYERS_H

#include "../include/Player.h"
#include "../include/Board.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

class Players {

private:

    std::vector<Player> players;

public:

    Players(int k);

    std::vector<Player> getPlayers() { return players; }

    int Move(Board& board, int i);

    void AggiornaFileTesto(std::string s);

};

std::ostream& operator<<(std::ostream& os, Players& obj);

#endif //MONOPOLY_PLAYERS_H
