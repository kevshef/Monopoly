//
// Created by Kevin Shefkiu on 26/12/23.
//

#ifndef MONOPOLY_SCOREBOARD_H
#define MONOPOLY_SCOREBOARD_H

#include "../include/Box.h"
#include "../include/AngularBox.h"
#include "../include/LateralBox.h"
#include <vector>

enum class Row{
    A = 0, B, C, D, E, F, G, H
};

class ScoreBoard {

private:

    std::vector<Box> scoreboard;

public:
    
    ScoreBoard();

    void setScoreBoard(std::vector<Box> newScoreBoard) { scoreboard = newScoreBoard; }

    std::vector<Box> getScoreBoard() { return scoreboard; }

    void operator=(ScoreBoard& obj) { scoreboard.setScoreBoard(obj.getScoreBoard()); }

    bool isStartBox(AngularBox& obj);

    bool AddHouse(LateralBox& obj);

    bool AddHotel(LateralBox& obj);

};


#endif //MONOPOLY_SCOREBOARD_H
