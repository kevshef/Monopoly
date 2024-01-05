//
// Created by Kevin Shefkiu on 05/01/24.
//

#ifndef MONOPOLY_HUMANPLAYER_H
#define MONOPOLY_HUMANPLAYER_H

#include "Player.h"
#include <iostream>

class HumanPlayer : public Player {

public:

    HumanPlayer(int playerNumber);

    int getPlayerType() const override { return 1; };

    bool buy(Box &box, int amount) override;

    bool buildHouse(Box &box) override;

    bool buildHotel(Box &box) override;

};

std::ostream& operator<<(std::ostream &os, HumanPlayer &obj);

#endif //MONOPOLY_HUMANPLAYER_H
