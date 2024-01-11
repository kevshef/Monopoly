#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H

#include "BankAccount.h" // Include necessary header for BankAccount class
#include "Box.h"
#include <iostream>
#include <memory>
#include <ctime>
#include <cstdlib>

// Class representing a player in the game
class Player {

protected:

    int identifyingNumber; // Unique identifier for the player

    int position; // Current position of the player on the board

    BankAccount bankAccount; // Player's bank account

public:

    virtual int getPlayerType() const = 0;

    int getPosition() const;

    int getBalance() const;

    int throwDice();

    void pay(std::shared_ptr<Player> &recipient, int amount);

    virtual bool buy(Box &box, int amount) = 0;

    virtual bool buildHouse(Box &box) = 0;

    virtual bool buildHotel(Box &box) = 0;

    void updateBalance();

    bool isBankrupt() const;

    void setPosition(int newPosition);

    int getNumber() const;
};

#endif //MONOPOLY_PLAYER_H