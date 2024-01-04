//
// Created by Alvise Garberino on 27/12/23.
//

#ifndef MONOPOLY_BANKACCOUNT_H
#define MONOPOLY_BANKACCOUNT_H

class BankAccount {

private:

    int balance;
    int ciao ;
public:

    BankAccount();

    int getBalance();

    void setBalance(int n);

    bool isBankrupt();

};

#endif //MONOPOLY_BANKACCOUNT_H
