//
// Created by Kevin Shefkiu on 05/01/24.
//

#ifndef MONOPOLY_COMPUTERPLAYER_H
#define MONOPOLY_COMPUTERPLAYER_H

#include "Player.h"
#include <iostream>

class ComputerPlayer : public Player {

public:

    ComputerPlayer(int playerNumber);

    int getPlayerType() const override { return 1; };

    bool buy(Box &box, int amount) override;

    bool buildHouse(Box &box) override;

    bool buildHotel(Box &box) override;

};

std::ostream& operator<<(std::ostream &os, const ComputerPlayer &obj);
#endif //MONOPOLY_COMPUTERPLAYER_H
