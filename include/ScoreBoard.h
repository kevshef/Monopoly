//
// Created by Kevin Shefkiu on 26/12/23.
//

#ifndef MONOPOLY_SCOREBOARD_H
#define MONOPOLY_SCOREBOARD_H

#include "../include/Box.h"
#include <vector>

enum class Row{
    A = 1, B, C, D, E, F, G, H
};

class ScoreBoard {
private:

    std::vector<std::vector<Box>> scoreboard;

public:


    ScoreBoard();

    void setScoreBoard(std::vector<std::vector<Box>> newScoreBoard) { scoreboard = newScoreBoard; }

    std::vector<std::vector<Box>> getScoreBoard() { return scoreboard; }

    void operator=(ScoreBoard& obj) { scoreboard = getScoreBoard(); }

    bool isStartBox(Box& obj);

    bool AddHouse(Box& obj);

    bool AddHotel(Box& obj);

};


#endif //MONOPOLY_SCOREBOARD_H
