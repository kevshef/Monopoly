/**
 * Filename: BankAccount.h
 * Author:
 * Created: 05/01/2024
 **/

#ifndef MONOPOLY_BANKACCOUNT_H
#define MONOPOLY_BANKACCOUNT_H

#include <ostream>

class BankAccount {

private:

    int balance;

public:

    BankAccount();

    int getBalance() const;

    void updateBalance(int);

    bool isBankrupt() const;

};

std::ostream& operator<<(std::ostream&, const BankAccount&);

#endif //MONOPOLY_BANKACCOUNT_H