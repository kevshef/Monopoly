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

    virtual char getNumber() { return identifying_number; }

    bool isInGame() { return bankaccount.isBankrupt(); }

};

#endif //MONOPOLY_PLAYER_H
