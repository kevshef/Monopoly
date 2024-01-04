#ifndef MONOPOLY_BOARD_H
#define MONOPOLY_BOARD_H

#include "Box.h" // Include necessary header for Box class
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Class representing the game board
class Board {

private:

    std::vector<Box> board; // Vector to store the boxes on the board

public:

    // Constructor: Initializes the game board
    Board();

    // Getter function to retrieve the vector of Box objects representing the board
    std::vector<Box>& getBoard();

    // Setter function to update the vector of Box objects representing the board
    void setBoard(const std::vector<Box>& boxes);

};

// Overloaded stream insertion operator to allow printing Board objects to an ostream
std::ostream& operator<<(std::ostream& os, Board& obj);

#endif //MONOPOLY_BOARD_H