//
// Created by Alvise Garberino on 27/12/23.
//

#include "../include/Player.h"

Player::Player(int t, int n) {

    srand(static_cast<unsigned int>(std::time(nullptr)));

    type = static_cast<PlayerType>(t);

    identifying_number = n;

}

/**
 *
 * @return int
 *
 * Metodo che restituisce il numero del giocatore
 */
int Player::getNumber() {
    return identifying_number;
}

/**
 *
 * @return bool
 *
 * Metodo che restituisce 'vero' se il saldo del giocatore è maggiore di zero
 */
bool Player::isInGame() {
    return !bankaccount.isBankrupt();
}

/**
 *
 * @return int
 *
 * Metodo restituisce la somme di due numeri generati randomicamente tra 1 e 6, per simulare il lancio di due dadi.
 */
int Player::ThrowDice() {
    return (((rand() % 6) + 1) + ((rand() % 6) + 1));
}