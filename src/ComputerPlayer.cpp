//
// Created by Kevin Shefkiu on 05/01/24.
//

#include "../include/ComputerPlayer.h"
#include <iostream>

ComputerPlayer::ComputerPlayer(int playerNumber) {

    position = 0;
    identifyingNumber = playerNumber;
    srand(static_cast<unsigned int>(std::time(nullptr)));

}


void ComputerPlayer::pay(Player &recipient, int amount) {+

    bankAccount.updateBalance(-amount);
    recipient.bankAccount.updateBalance(amount);
}


bool ComputerPlayer::buy(int amount) {

    if(rand() % 4  == 0) {

        if (bankAccount.getBalance() >= amount) {
            bankAccount.updateBalance(-amount);
            return true;
        }
    }
    return false;

}

bool ComputerPlayer::buildHouse(int amount) {

    if(rand() % 4  == 0) {

        if (bankAccount.getBalance() >= amount) {
            bankAccount.updateBalance(-amount);
            return true;
        }
    }
    return false;

}

bool ComputerPlayer::buildHotel (int amount) {

    if(rand() % 4  == 0) {

        if (bankAccount.getBalance() >= amount) {
            bankAccount.updateBalance(-amount);
            return true;
        }
    }
    return false;

}
