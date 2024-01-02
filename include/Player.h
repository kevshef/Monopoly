//
// Created by
//

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H

#include "../include/BankAccount.h"
#include <ctime>
#include <cstdlib>

enum class PlayerType {
    real = 0, computer
};

class Player {

private:

    int identifying_number; // Numero del giocatore

    PlayerType type;

    BankAccount bankaccount;

public:

    Player(int t, int n);

    int getNumber();

    bool isInGame();

    int ThrowDice();

};

#endif //MONOPOLY_PLAYER_H
