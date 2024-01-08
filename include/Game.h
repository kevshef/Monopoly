//
// Created by Kevin Shefkiu on 05/01/24.
//

#ifndef MONOPOLY_GAME_H
#define MONOPOLY_GAME_H

#include <fstream>
#include <memory>
#include <algorithm>
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Board.h"

// Class representing the set of players in the game
class Game {

private:

    std::vector<std::shared_ptr<Player>> players; // Vector to store the players in the game

public:

    // Constructor: Initializes the set of players based on the number of players
    Game(const char *gamer, Board &board);

    // Function to simulate a player's move on the board
    int move(Board& board, int playerIndex);

    // Function to update a text file with a given message
    void updateTextFile(const std::string& message);

    // Function to determine the starting order of players based on dice rolls
    bool start();

    void setPlayers(const std::vector<std::shared_ptr<Player>> &newPlayers) { players = newPlayers; }

    std::vector<std::shared_ptr<Player>>& getPlayers() { return players; }

    const std::vector<std::shared_ptr<Player>>& getPlayers() const { return players; }

    // Function to check if the game has ended (three or more players bankrupt)
    bool end() const;

    int richestPlayer() const;
};

// Overloaded stream insertion operator to allow printing Game objects to an ostream
std::ostream& operator<<(std::ostream& os, const Game& obj);

#endif //MONOPOLY_GAME_H