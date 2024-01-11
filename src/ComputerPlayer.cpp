//
// Created by Kevin Shefkiu on 05/01/24.
//

#include "../include/ComputerPlayer.h"

/**
 *
 * @param playerNumber
 * @brief constructor
 */
ComputerPlayer::ComputerPlayer(int playerNumber) {

    position = 0;
    identifyingNumber = playerNumber;
    srand(static_cast<unsigned int>(std::time(nullptr)));

}
/**
 *
 * @param box
 * @param amount
 * @return true 25% probability of buying the land, false 75% of the times
 */
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

/**
 *
 * @param box
 * @return true 25% probability of building the house, false 75% of the times
 */
bool ComputerPlayer::buildHouse(Box &box) {

    if (buy(box, box.getHousePrice())) {
        box.setIdentifying();
        return true;
    }
    return false;

}

/**
 *
 * @param box
 * @return true 25% probability of building the hotel, false 75% of the times
 */
bool ComputerPlayer::buildHotel (Box &box) {

    if (buy(box, box.getHotelPrice())) {
        box.setIdentifying();
        return true;
    }
    return false;

}
/**
 *
 * @param os
 * @param obj
 * @return os
 * @brief overload of operator <<
 */
std::ostream& operator<<(std::ostream &os, const ComputerPlayer &obj) {
    return os << "Giocatore " << obj.getNumber() << " (computer) saldo: " << obj.getBalance() << " fiorini\n";
}