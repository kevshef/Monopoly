/**
 * Filename: Player.h
 * Author: Shefkiu Kevin
 * Co-Author: Garberino Alvise
 * Created: 05/01/2024
 **/

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H

#include "BankAccount.h" // Include necessary header for BankAccount class
#include "Box.h"
#include <iostream>
#include <memory>
#include <ctime>
#include <cstdlib>

class Player {

protected:

    // Unique identifier for the player
    int identifyingNumber;

    // Current position of the player on the board
    int position;

    // Player's bank account
    BankAccount bankAccount;

public:

    int getPosition() const;

    int getBalance() const;

    int throwDice();

    void pay(std::shared_ptr<Player>&, int);

    virtual bool buy(Box&, int) = 0;

    virtual bool buildHouse(Box&) = 0;

    virtual bool buildHotel(Box&) = 0;

    void updateBalance();

    bool isBankrupt() const;

    void setPosition(int);

    int getNumber() const;

};

#endif //MONOPOLY_PLAYER_H