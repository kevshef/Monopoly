//
// Created by Kevin Shefkiu on 26/12/23.
//

#ifndef MONOPOLY_BOARD_H
#define MONOPOLY_BOARD_H

#include "../include/Box.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class Board {

private:

    std::vector<Box> board;
    
public:

    Board();

    std::vector<Box> getBoard() const { return board; }

};

std::ostream& operator<<(std::ostream& os, Board& obj);

#endif //MONOPOLY_BOARD_H