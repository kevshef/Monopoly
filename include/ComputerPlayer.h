//
// Created by Kevin Shefkiu on 05/01/24.
//

#ifndef MONOPOLY_COMPUTERPLAYER_H
#define MONOPOLY_COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : Player {

public:

    ComputerPlayer(int playerNumber);

    int getPlayerType() const override { return 1; };

    void pay(Player& recipient, int amount);

    virtual bool buy(int amount) override;

    bool buildHouse(int amount) override;

    bool buildHotel(int amount) override;





};


#endif //MONOPOLY_COMPUTERPLAYER_H
