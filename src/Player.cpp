/**
 * Filename: Player.cpp
 * Author:
 * Created: 05/01/2024
 **/

#include "../include/Player.h"

/**
 * @brief Getter function to retrieve the identifying number of the player.
 *
 * @return The identifying number of the player.
 */
int Player::getNumber() const {
    return identifyingNumber;
}

/**
 * @brief Getter function to retrieve the current position of the player on the board.
 *
 * @return The current position of the player.
 */
int Player::getPosition() const {
    return position;
}

/**
 * @brief Getter function to retrieve the balance of the player's bank account.
 *
 * @return The balance of the player's bank account.
 */
int Player::getBalance() const {
    return bankAccount.getBalance();
}

/**
 * @brief Simulates throwing two six-sided dice and returns the sum.
 *
 * @return The sum of the two dice rolls.
 */
int Player::throwDice() {
    return (((rand() % 6) + 1) + ((rand() % 6) + 1));
}


/**
 * @brief Performs a payment transaction from the player to a recipient player.
 *
 * @param recipient The player to receive the payment.
 * @param amount The amount to be paid.
 *
 */
void Player::pay(std::shared_ptr<Player> &recipient, int amount) {

    if (!recipient->isBankrupt()) {
        bankAccount.updateBalance(-amount);
        recipient->bankAccount.updateBalance(amount);
    }
}

/**
 * @brief Sets the player's bank account balance to a specific amount.
 *
 * @details Used for initializing the player's balance at the start of the game.
 */
void Player::updateBalance() {
    bankAccount.updateBalance(20);
}

/**
 * @brief Checks if the player is bankrupt (bank account balance < 0).
 *
 * @return True if the player is bankrupt, false otherwise.
 */
bool Player::isBankrupt() const {
    return bankAccount.isBankrupt();
}

/**
 * @brief Setter function to update the player's position on the board.
 *
 * @param newPosition The new position to set for the player.
 */
void Player::setPosition(int newPosition) {
    position = newPosition;
}
