//
// Created by Kevin Shefkiu on 26/12/23.
//

#include "../include/ScoreBoard.h"
#include "../include/AngularBox.h"
#include "../include/LateralBox.h"

#include <ostream>
#include <cstdlib>
#include <ctime>

ScoreBoard::ScoreBoard() {
    srand(static_cast<unsigned int>(std::time(nullptr)));

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

std::ostream& operator<<(std::ostream& os, ScoreBoard& obj) {
    for (const auto& box : obj.getScoreBoard()) {
        os << "Identifying: " << box->getIdentifying() << " ";

        // Se l'oggetto è di tipo LateralBox, visualizza anche il BoxType
        if (auto lateralBox = dynamic_cast<LateralBox*>(box.get())) {
            os << "BoxType: " << static_cast<int>(lateralBox->getBoxType()) << " ";
        }

        os << std::endl;
    }

    return os;
}