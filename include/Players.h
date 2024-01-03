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
#include <fstream>

class Players {

private:

    std::vector<Player> players;

public:

    Players(int k);

    std::vector<Player>& getPlayers() { return players; }

    void setPlayers(std::vector<Player> p) { players = p; }

    int Move(Board& board, int i);

    void AggiornaFileTesto(std::string s);

    void Start();

    bool End();

};

std::ostream& operator<<(std::ostream& os, Players& obj);

#endif //MONOPOLY_PLAYERS_H
