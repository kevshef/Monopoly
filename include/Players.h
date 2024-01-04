#ifndef MONOPOLY_PLAYERS_H
#define MONOPOLY_PLAYERS_H

#include "Player.h" // Include necessary header for Player class
#include "Board.h" // Include necessary header for Board class

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

// Class representing the set of players in the game
class Players {

private:

    std::vector<Player> players; // Vector to store the players in the game

public:

    // Constructor: Initializes the set of players based on the number of players
    Players(int numberOfPlayers);

    // Getter function to retrieve the vector of Player objects representing the players
    std::vector<Player>& getPlayers();

    // Setter function to update the vector of Player objects representing the players
    void setPlayers(const std::vector<Player>& newPlayers);

    // Function to simulate a player's move on the board
    int move(Board& board, int playerIndex);

    // Function to update a text file with a given message
    void updateTextFile(const std::string& message);

    // Function to determine the starting order of players based on dice rolls
    bool start();

    // Function to check if the game has ended (three or more players bankrupt)
    bool end() const;
};

// Overloaded stream insertion operator to allow printing Players objects to an ostream
std::ostream& operator<<(std::ostream& os, Players& obj);

#endif //MONOPOLY_PLAYERS_H