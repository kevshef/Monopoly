//
// Created by Alvise Garberino on 27/12/23.
//

#ifndef MONOPOLY_REALPLAYER_H
#define MONOPOLY_REALPLAYER_H

#include "../include/Player.h"

#include <cstdlib>
#include <ctime>

class RealPlayer : Player {

public:

    RealPlayer() { srand(static_cast<unsigned int>(std::time(nullptr))); }

    virtual char getNumber() { return identifying_number; }

    virtual void setNumber(int n) { identifying_number = n; }

    virtual bool isInGame() { return !bankaccount.isBankrupt(); }

    virtual int ThrowDice() { return (((rand() % 6) + 1) + ((rand() % 6) + 1)); }

};


#endif //MONOPOLY_REALPLAYER_H
