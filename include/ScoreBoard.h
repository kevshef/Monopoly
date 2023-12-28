//
// Created by Kevin Shefkiu on 26/12/23.
//

#ifndef MONOPOLY_SCOREBOARD_H
#define MONOPOLY_SCOREBOARD_H

#include "../include/Box.h"
#include <iostream>
#include <vector>

class ScoreBoard {

private:

    std::vector<Box> board;
    
public:

    ScoreBoard();

    std::vector<Box> getBoard() const { return board; }

};

std::ostream& operator<<(std::ostream& os, ScoreBoard& obj);

#endif //MONOPOLY_SCOREBOARD_H