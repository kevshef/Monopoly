/**
 * Filename: ComputerPlayer.h
 * Author:
 * Created: 05/01/2024
 **/

#ifndef MONOPOLY_COMPUTERPLAYER_H
#define MONOPOLY_COMPUTERPLAYER_H

#include "Player.h"
#include <iostream>

class ComputerPlayer : public Player {

public:

    ComputerPlayer(int);

    bool buy(Box&, int) override;

    bool buildHouse(Box&) override;

    bool buildHotel(Box&) override;

};

std::ostream& operator<<(std::ostream &, const ComputerPlayer &);

#endif //MONOPOLY_COMPUTERPLAYER_H
