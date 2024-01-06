//
// Created by Kevin Shefkiu on 05/01/24.
//

#ifndef MONOPOLY_HUMANPLAYER_H
#define MONOPOLY_HUMANPLAYER_H

#include "Player.h"
#include "Board.h"
#include <iostream>


class HumanPlayer : public Player {

private:
    Board board;
public:

    HumanPlayer(int playerNumber, Board &Board);

    int getPlayerType() const override { return 1; };

    bool buy(Box &box, int amount) override;

    bool buildHouse(Box &box) override;

    bool buildHotel(Box &box) override;

    bool show() const;

};

std::ostream& operator<<(std::ostream &os, const HumanPlayer &obj);

#endif //MONOPOLY_HUMANPLAYER_H
