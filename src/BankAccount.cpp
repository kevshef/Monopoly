/**
 * Filename: BankAccount.cpp
 * Author: Zarantonello Michele
 * Created: 05/01/2024
 **/

#include "../include/BankAccount.h"

/**
 * @brief Default constructor for the BankAccount class.
 *
 * @details Initializes the bank account with a default balance of 100.
 */
BankAccount::BankAccount() : balance(100) {}

/**
 * @brief Getter function to retrieve the current balance of the bank account.
 *
 * @return The current balance of the bank account.
 */
int BankAccount::getBalance() const {
    return balance;
}

/**
 * @brief Setter function to update the balance of the bank account by a specified amount.
 *
 * @param amount The amount to be added to the current balance.
 */
void BankAccount::updateBalance(int amount) {
    balance += amount;
}

/**
 * @brief Function to check if the bank account is bankrupt (balance < 0).
 *
 * @return True if the bank account is bankrupt, false otherwise.
 */
bool BankAccount::isBankrupt() const {
    return balance < 0;
}

/**
 * @brief Overloaded stream insertion operator to allow printing BankAccount objects to an ostream.
 *
 * @param os The output stream to which the BankAccount information will be printed.
 * @param account The BankAccount object to be printed.
 *
 * @return The modified output stream.
 *
 * @details Prints the balance information of the BankAccount object to the output stream.
 *          Note: Ensure that the BankAccount class has a function getBalance().
 */
std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
    os << "Saldo: " << account.getBalance();  // Assicurati che la classe BankAccount abbia una funzione getBalance()
    return os;
}