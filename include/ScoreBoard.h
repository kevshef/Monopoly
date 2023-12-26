//
// Created by Kevin Shefkiu on 26/12/23.
//

#ifndef MONOPOLY_SCOREBOARD_H
#define MONOPOLY_SCOREBOARD_H

#include "../include/Box.h"
#include <vector>

class ScoreBoard {

public:

    std::vector<Box> scoreboard;

    ScoreBoard();

    void setScoreBoard(std::vector<Box> newScoreBoard) { scoreboard = newScoreBoard; }

    std::vector<Box> getScoreBoard() { return scoreboard; }

    void operator=(ScoreBoard& obj) { scoreboard = obj.getScoreBoardVector(); }

    bool isStartBox(Box& obj);

};


#endif //MONOPOLY_SCOREBOARD_H
