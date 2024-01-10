//
// Created by Kevin Shefkiu on 05/01/24.
//

#include "../include/ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(int playerNumber) {

    position = 0;
    identifyingNumber = playerNumber;
    srand(static_cast<unsigned int>(std::time(nullptr)));

}

bool ComputerPlayer::buy(Box &box, int amount) {

    if (bankAccount.getBalance() > amount) {

        if (rand() % 4 == 0) {

            if (bankAccount.getBalance() >= amount) {
                bankAccount.updateBalance(-amount);

                if (box.isFree()) {
                    box.setNotFree(getNumber());
                }

                return true;
            }
        }
    }

    return false;

}

bool ComputerPlayer::buildHouse(Box &box) {

    if (buy(box, box.getHousePrice())) {

        box.setIdentifying();

        return true;

    }

    return false;

}

bool ComputerPlayer::buildHotel (Box &box) {

    if (buy(box, box.getHotelPrice())) {

        box.setIdentifying();

        return true;

    }

    return false;

}

std::ostream& operator<<(std::ostream &os, const ComputerPlayer &obj) {
    return os << "Giocatore " << obj.getNumber() << " (computer) saldo: " << obj.getBalance() << " fiorini\n";
}