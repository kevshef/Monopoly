//
// Created by
//

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H

#include "../include/BankAccount.h"
#include <ostream>
#include <ctime>
#include <cstdlib>

enum class PlayerType {
    real = 0, computer
};

class Player {

private:

    int identifying_number; // Numero del giocatore

    int position;

    PlayerType type;

    BankAccount bankaccount;

public:

    Player(int t, int n);

    int getNumber();

    int getPlayerType();

    int getPosition();

    int getBalance();

    bool isInGame();

    int ThrowDice();

    void Pay(Player &obj, int n);

    bool Buy(int n);

    void setBalance();

    bool isBankrupt() { return bankaccount.isBankrupt(); }

    void setPosition(int n) { position = n; }

};

std::ostream& operator<<(std::ostream& os, Player& obj);

#endif //MONOPOLY_PLAYER_H
