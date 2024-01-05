//
// Created by Kevin Shefkiu on 05/01/24.
//

#include "../include/HumanPlayer.h"


HumanPlayer::HumanPlayer(int playerNumber) {

    position = 0;
    identifyingNumber = playerNumber;
    srand(static_cast<unsigned int>(std::time(nullptr)));

}



bool HumanPlayer::buy(Box &box, int amount) {

    char answer = ' ';
    std::cout << "\n\tGiocatore " << getNumber() + 1
              << " digitare S o N se si vuole procedere o meno con l'acquisto di " << box << " per " << amount
              << " fiorini." << "\n";
    do {
        std::cout << "\n\tRisposta : ";
        std::cin >> answer;

    } while (answer != 'S' && answer != 'N');

    if (answer == 'S') {
        if (bankAccount.getBalance() >= amount) {
            bankAccount.updateBalance(-amount);
            box.setNotFree(getNumber());
            return true;
        }
    }

    return false;

}

bool HumanPlayer::buildHouse(Box &box) {

    char answer = ' ';
    std::cout << "\n\tGiocatore " << getNumber() + 1
              << " digitare S o N se si vuole procedere o meno con la costruzione di una casa sul terreno di " << box
              << " per "
              << box.getHousePrice() << " fiorini." << "\n";
    do {
        std::cout << "\n\tRisposta : ";
        std::cin >> answer;

    } while (answer != 'S' && answer != 'N');

    if (answer == 'S') {
        if (bankAccount.getBalance() >= box.getHousePrice()) {
            bankAccount.updateBalance(-box.getHousePrice());
            box.setIdentifying();
            return true;
        }
    }

    return false;

}

bool HumanPlayer::buildHotel (Box &box) {

    char answer = ' ';
    std::cout << "\n\tGiocatore " << getNumber() + 1
              << " digitare S o N se si vuole procedere o meno per il miglioramento di una casa in albergo sul terreno"
              << box << " per "
              << box.getHotelPrice() << " fiorini." << "\n";
    do {
        std::cout << "\n\tRisposta : ";
        std::cin >> answer;

    } while (answer != 'S' && answer != 'N');

    if (answer == 'S') {
        if (bankAccount.getBalance() >= box.getHotelPrice()) {
            bankAccount.updateBalance(-box.getHotelPrice());
            box.setIdentifying();
            return true;
        }
    }

    return false;

}

std::ostream& operator<<(std::ostream &os, HumanPlayer &obj) {

    return os << "Giocatore " << obj.getNumber() << " (real) saldo: " << obj.getBalance() << "\n";


};
