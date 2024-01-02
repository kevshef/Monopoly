//
// Created by Alvise Garberino on 27/12/23.
//

#include "../include/Player.h"

Player::Player(int t, int n) {

    srand(static_cast<unsigned int>(std::time(nullptr)));

    type = static_cast<PlayerType>(t);

    identifying_number = n;

    position = 0;

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
 * @return int
 *
 * Metodo che restituisce il tipo del giocatore (0 == real, 1 == computer)
 */
int Player::getPlayerType() {
    return static_cast<int>(type);
}

int Player::getBalance() {
    return bankaccount.getBalance();
}

int Player::getPosition() {
    return position;
}

void Player::setBalance() {
    bankaccount.setBalance(20);
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

void Player::Pay(Player &obj, int n) {

    bankaccount.setBalance(-n);

    obj.bankaccount.setBalance(n);

}

bool Player::Buy(int n) {

    if (bankaccount.getBalance() >= n)
        bankaccount.setBalance(-n);
    else
        return false;

    return true;
}

std::ostream& operator<<(std::ostream& os, Player& obj) {

    os << "Giocatore " << obj.getNumber() << " (";
    if (obj.getPlayerType() == 0)
        os << "real)";
    else
        os << "computer)";
    os << " saldo: " << obj.getBalance() << "\n";

    return os;
}