//
// Created by
//

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H

#include "../include/BankAccount.h"


class Player {

protected:

    int identifying_number; // Numero del giocatore

    BankAccount bankaccount;

public:

    virtual char getNumber() = 0;

    virtual void setNumber(int n) = 0;

    virtual bool isInGame() = 0;

    virtual int ThrowDice() = 0;

};

#endif //MONOPOLY_PLAYER_H
