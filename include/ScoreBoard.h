//
// Created by Kevin Shefkiu on 26/12/23.
//

#ifndef MONOPOLY_SCOREBOARD_H
#define MONOPOLY_SCOREBOARD_H

#include "../include/Box.h"
#include "../include/AngularBox.h"
#include "../include/LateralBox.h"
#include <vector>
#include <memory>  // Add this header for smart pointers std::shared_ptr & std::make_shared

enum class Row {
    A = 0, B, C, D, E, F, G, H
};

class ScoreBoard {

private:

    std::vector<std::shared_ptr<Box>> scoreboard;  // Use smart pointers

public:

    ScoreBoard();

    void setScoreBoard(std::vector<std::shared_ptr<Box>> newScoreBoard) { scoreboard = newScoreBoard; }

    std::vector<std::shared_ptr<Box>> getScoreBoard() { return scoreboard; }

    void operator=(ScoreBoard& obj) { scoreboard = obj.getScoreBoard(); }

    bool isStartBox(AngularBox& obj);

    bool AddHouse(LateralBox& obj);

    bool AddHotel(LateralBox& obj);

};

std::ostream& operator<<(std::ostream& os, ScoreBoard& obj);

#endif //MONOPOLY_SCOREBOARD_H