//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/ScoreBoard.h"

ScoreBoard::ScoreBoard() {

    std::srand(std::time(0));

    scoreboard.push_back(std::vector<Box*>());

    for (int i = 0; i < 4; ++i) {

        AngularBox angularBox = new AngularBox(i == 0);
        scoreboard.push_back(angularBox);

        for (int k = 1; k < 8; ++k) {

            for (int j = 0; j < 8; ++j) {

                int randomCategory = std::rand() % 3;
                LateralBox* lateralBox = new LateralBox(randomCategory);
                scoreboard.push_back(lateralBox);

            }
        }
    }

}