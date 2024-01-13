/**
 * Filename: Board.h
 * Author: Shefkiu Kevin
 * Created: 05/01/2024
 **/

#ifndef MONOPOLY_BOARD_H
#define MONOPOLY_BOARD_H

#include "Box.h" // Include necessary header for Box class
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class Board {

private:

    std::vector<Box> board;

    std::vector<std::string> coordinates  = {
        "A1",
        "A2",
        "A3",
        "A4",
        "A5",
        "A6",
        "A7",
        "A8",
        "B8",
        "C8",
        "D8",
        "E8",
        "F8",
        "G8",
        "H8",
        "H7",
        "H6",
        "H5",
        "H4",
        "H3",
        "H2",
        "H1",
        "G1",
        "F1",
        "E1",
        "D1",
        "C1",
        "B1"
    };

public:

    Board();

    std::vector<Box>& getBoard();

    std::string getCoordinates(int);

};

std::ostream& operator<<(std::ostream&, Board&);

#endif //MONOPOLY_BOARD_H