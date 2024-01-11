#ifndef MONOPOLY_BANKACCOUNT_H
#define MONOPOLY_BANKACCOUNT_H

#include <ostream>

// Class representing a simple bank account
class BankAccount {

private:

    // Private member variable to store the balance of the bank account
    int balance;

public:

    BankAccount();

    int getBalance() const;

    void updateBalance(int amount);

    bool isBankrupt() const;

};

// Overloaded stream insertion operator to allow printing BankAccount objects to an ostream
std::ostream& operator<<(std::ostream& os, const BankAccount& account);

#endif //MONOPOLY_BANKACCOUNT_H