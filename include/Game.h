/**
 * Filename: Game.h
 * Author: Garberino Alvise
 * Co-Author: Shefkiu Kevin
 * Created: 05/01/2024
 **/

#ifndef MONOPOLY_GAME_H
#define MONOPOLY_GAME_H

#include <fstream>
#include <memory>
#include <algorithm>
#include <cstring>
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Board.h"

class Game {

private:

    // Vector to store the players in the game
    std::vector<std::shared_ptr<Player>> players;

    void move(Board&, int);

    void updateTextFile(const std::string&);

    std::vector<std::shared_ptr<Player>> start(std::vector<std::shared_ptr<Player>>&);

    bool end() const;

    void richestPlayer();

public:


    Game(const char*, Board &);

    void setPlayers(const std::vector<std::shared_ptr<Player>> &newPlayers) { players = newPlayers; }

    std::vector<std::shared_ptr<Player>>& getPlayers() { return players; }

    const std::vector<std::shared_ptr<Player>>& getPlayers() const { return players; }

    void play(Board&, int);
};

std::ostream& operator<<(std::ostream&, const Game&);

#endif //MONOPOLY_GAME_Hx\