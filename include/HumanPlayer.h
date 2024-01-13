/**
 * Filename: HumanPlayer.h
 * Author: Zarantonello Michele
 * Created: 05/01/2024
 **/

#ifndef MONOPOLY_HUMANPLAYER_H
#define MONOPOLY_HUMANPLAYER_H

#include "Player.h"
#include "Board.h"
#include <iostream>

class HumanPlayer : public Player {

private:

    Board board;

public:

    HumanPlayer(int, Board&);

    bool buy(Box&, int) override;

    bool buildHouse(Box&) override;

    bool buildHotel(Box&) override;

    void show(std::vector<std::shared_ptr<Player>>, Board&);

};

std::ostream& operator<<(std::ostream &, const HumanPlayer &);

#endif //MONOPOLY_HUMANPLAYER_H
