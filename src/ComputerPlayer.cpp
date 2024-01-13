/**
 * Filename: ComputerPlayer.cpp
 * Author: Zarantonello Michele
 * Created: 05/01/2024
 **/

#include "../include/ComputerPlayer.h"

/**
 * @brief Constructor
 *
 * @param playerNumber Player ID
 *
 * @details Sets the position to the starting position and assigns the player ID.
 */
ComputerPlayer::ComputerPlayer(int playerNumber) {

    srand(static_cast<unsigned int>(std::time(nullptr)));

    position = 0;

    identifyingNumber = playerNumber;

}

/**
 * @brief Attempts to buy a land box.
 *
 * @param box The land box to consider for purchase.
 * @param amount The amount of money required to buy the land box.
 *
 * @return true if the computer player decides to buy the land (25% probability), false otherwise (75% probability).
 */
bool ComputerPlayer::buy(Box &box, int amount) {

    if (bankAccount.getBalance() >= amount) {

        if (rand() % 4 == 0) {

            bankAccount.updateBalance(-amount);

            box.setNotFree(getNumber());

            return true;

        }

    }

    return false;

}

/**
 * @brief Attempts to build a house on a given box.
 *
 * @param box The box on which the computer player wants to build a house.
 *
 * @return true if the computer player decides to build a house (25% probability), false otherwise (75% probability).
 */
bool ComputerPlayer::buildHouse(Box &box) {

    if (buy(box, box.getHousePrice())) {

        box.setIdentifying();

        return true;

    }

    return false;

}

/**
 * @brief Attempts to build a hotel on a given box.
 *
 * @param box The box on which the computer player wants to build a hotel.
 *
 * @return true if the computer player decides to build a hotel (25% probability), false otherwise (75% probability).
 */
bool ComputerPlayer::buildHotel (Box &box) {

    if (buy(box, box.getHotelPrice())) {

        box.setIdentifying();

        return true;

    }

    return false;

}

/**
 * @brief Overload of the output stream insertion operator.
 *
 * @param os The output stream.
 * @param obj The ComputerPlayer object to be output.
 *
 * @return The output stream after inserting information about the computer player.
 */
std::ostream& operator<<(std::ostream &os, const ComputerPlayer &obj) {
    return os << "Giocatore " << obj.getNumber() << " (computer) saldo: " << obj.getBalance() << " fiorini\n";
}