//
// Created by Alvise Garberino on 27/12/23.
//

#include "../include/BankAccount.h"

BankAccount::BankAccount() {
    balance = 100;
}

/**
 *
 * @return balance
 *
 * Metodo che restituisce il saldo del giocatore
 */
int BankAccount::getBalance() {
    return balance;
}

/**
 *
 * @param n
 *
 * @return void method
 *
 * Metodo che modifica il saldo del giocatore, se il valore è negatovo sottrae altrimenti incrementa.
 */
void BankAccount::setBalance(int n) {
    balance += n;
}

/**
 *
 * @return bool
 *
 * Metodo che restituisce 'vero' se l'attuale saldo del giocatore è minore di zero.
 */
bool BankAccount::isBankrupt() {
    return balance < 0;
}
