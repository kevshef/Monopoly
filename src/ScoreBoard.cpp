//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/ScoreBoard.h"
#include "../include/AngularBox.h"
#include "../include/LateralBox.h"

ScoreBoard::ScoreBoard() {

    std::srand(std::time(0));

    for (int i = 0; i < 4; ++i) {

        AngularBox angularBox = new AngularBox(i == 0);
        scoreboard.push_back(angularBox);

        for (int k = 1; k < 8; ++k) {

            for (int j = 0; j < 8; ++j) {

                int randomCategory = std::rand() % 3;
                LateralBox lateralBox = new LateralBox(randomCategory);
                scoreboard.push_back(lateralBox);

            }
        }
    }
}

bool ScoreBoard::isStartBox(Box& obj) {
    if (obj.getIdentifying() == " ") {
        AngularBox angularBox = static_cast<AngularBox>(obj);
        return angularBox.start;
    }
    return false;
}

bool ScoreBoard::AddHouse(Box &obj) {
    if (obj.getIdentifying() == " ")
        return false;

    LateralBox lateralBox = static_cast<LateralBox>(obj);
    if (!lateralBox.free){
        lateralBox.setIdentifying(lateralBox.getIdentifying() + "*");
        return true;
    }

    return false;
}

bool ScoreBoard::AddHotel(Box &obj) {
    if (obj.getIdentifying() == " ")
        return false;

    LateralBox lateralBox = static_cast<LateralBox>(obj);
    if (!lateralBox.free && lateralBox.getIdentifying().find("*") != std::string::npos ){
        lateralBox.setIdentifying(lateralBox.getIdentifying() + "^");
        return true;
    }

    return false;
}
