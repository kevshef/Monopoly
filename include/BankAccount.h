//
// Created by Alvise Garberino on 23/12/23.
//

#ifndef MONOPOLY_BANKACCOUNT_H
#define MONOPOLY_BANKACCOUNT_H


class BackAccount {

private:

    int balance = 100;

public:

    int getBalance() { return balance; }

    bool isBankrupting() { return balance > 0 ? false : true;  }

    bool setBalance(int n) { balance += n; return isBankrupting(); }

};


#endif //MONOPOLY_BANKACCOUNT_H
