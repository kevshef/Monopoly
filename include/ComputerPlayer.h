//
// Created by Alvise Garberino on 27/12/23.
//

#ifndef MONOPOLY_COMPUTERPLAYER_H
#define MONOPOLY_COMPUTERPLAYER_H

#include "../include/Player.h"

class ComputerPlayer : public Player {

public:

    ComputerPlayer() { srand(static_cast<unsigned int>(std::time(nullptr))); }

    virtual char getNumber() { return identifying_number; }

    virtual void setNumber(int n) { identifying_number = n; }

    virtual bool isInGame() { return !bankaccount.isBankrupt(); }

    virtual int ThrowDice() { return (((rand() % 6) + 1) + ((rand() % 6) + 1)); }

    bool buy() { return rand() % 4 == 0; /*25% di probabilità di acquisto*/ };

};

#endif //MONOPOLY_COMPUTERPLAYER_H
