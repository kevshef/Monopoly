//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/ScoreBoard.h"
#include "../include/AngularBox.h"
#include "../include/LateralBox.h"

ScoreBoard::ScoreBoard() {

    std::srand(std::time(0));

    for (int i = 0; i < 4; ++i) {

        std::shared_ptr<Box> angularBox = std::make_shared<AngularBox>(i == 0);

        scoreboard.push_back(angularBox);

        for (int k = 1; k < 8; k++) {
            for (int j = 0; j < 8; j++) {

                int randomCategory = std::rand() % 3;

                std::shared_ptr<Box> lateralBox = std::make_shared<LateralBox>(randomCategory);

                scoreboard.push_back(lateralBox);
            }
        }
    }
}

bool ScoreBoard::isStartBox(AngularBox& obj) {
    return obj.start;
}

bool ScoreBoard::AddHouse(LateralBox &obj) {

    if (!obj.free){
        obj.setIdentifying('*');
        return true;
    }

    return false;
}

bool ScoreBoard::AddHotel(LateralBox &obj) {

    if (!obj.free && obj.getIdentifying() == '*'){
        obj.setIdentifying('^');
        return true;
    }

    return false;
}