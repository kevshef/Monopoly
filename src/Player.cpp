#include "../include/Player.h"

/**
 * @brief Constructor for the Player class.
 *
 * @param playerType The type of player (real or computer).
 * @param playerNumber The identifying number assigned to the player.
 *
 * @details Initializes a Player object with the specified type, identifying number,
 * and sets the initial position to 0. Seeds the random number generator with the current time.
 */

/**
 * @brief Getter function to retrieve the identifying number of the player.
 *
 * @return The identifying number of the player.
 */
int Player::getNumber() const {
    return identifyingNumber;
}

/**
 * @brief Getter function to retrieve the type of the player (0 for real, 1 for computer).
 *
 * @return The type of the player.
 */


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
 */
void Player::pay(Player& recipient, int amount) {
    bankAccount.updateBalance(-amount);
    recipient.bankAccount.updateBalance(amount);
}

/**
 * @brief Attempts to make a purchase with the specified amount from the player.
 *
 * @param amount The amount to be spent on the purchase.
 * @return True if the purchase is successful, false if the player doesn't have enough balance.
 */
bool Player::buy(int amount) {
    if (bankAccount.getBalance() >= amount) {
        bankAccount.updateBalance(-amount);
        return true;
    }
    return false;
}

/**
 * @brief Sets the player's bank account balance to a specific amount.
 *
 * @details Used for initializing the player's balance at the start of the game.
 */
void Player::updateBalance() {
    bankAccount.updateBalance(2);
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

/**
 * @brief Overloaded stream insertion operator to allow printing Player objects to an ostream.
 *
 * @param os The output stream to which the Player information will be printed.
 * @param obj The Player object to be printed.
 *
 * @return The modified output stream.
 *
 * @details Prints the player's identifying number, type, and balance to the output stream.
 */
std::ostream& operator<<(std::ostream& os, Player& obj) {
    os << "Giocatore " << obj.getNumber() << " (";
    if (obj.getPlayerType() == 0)
        os << "real)";
    else
        os << "computer)";
    os << " saldo: " << obj.getBalance() << "\n";

    return os;
}