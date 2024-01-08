#ifndef MONOPOLY_BANKACCOUNT_H
#define MONOPOLY_BANKACCOUNT_H

#include <ostream>

// Class representing a simple bank account
class BankAccount {

private:

    // Private member variable to store the balance of the bank account
    int balance;

public:

    // Constructor: Initializes the bank account with a default balance of 0
    BankAccount();

    // Getter function to retrieve the current balance of the bank account
    int getBalance() const;

    // Setter function to set the balance of the bank account to a specified amount
    void updateBalance(int amount);

    // Function to check if the bank account is bankrupt (balance <= 0)
    bool isBankrupt() const;

};

// Overloaded stream insertion operator to allow printing BankAccount objects to an ostream
std::ostream& operator<<(std::ostream& os, const BankAccount& account);

#endif //MONOPOLY_BANKACCOUNT_H