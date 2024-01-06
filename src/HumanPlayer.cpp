//
// Created by Kevin Shefkiu on 05/01/24.
//

#include "../include/HumanPlayer.h"


HumanPlayer::HumanPlayer(int playerNumber, Board &board) {

    this->board = board;
    position = 0;
    identifyingNumber = playerNumber;
    srand(static_cast<unsigned int>(std::time(nullptr)));

}



bool HumanPlayer::buy(Box &box, int amount) {

    char answer = ' ';
    std::cout << "\n\tGiocatore " << getNumber()
              << " digitare S o N se si vuole procedere o meno con l'acquisto di " << board.getCoordinates(position)
              << " per " << amount
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
    std::cout << "\n\tGiocatore " << getNumber()
              << " digitare S o N se si vuole procedere o meno con la costruzione di una casa sul terreno di "
              << board.getCoordinates(position)
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
    std::cout << "\n\tGiocatore " << getNumber()
              << " digitare S o N se si vuole procedere o meno per il miglioramento di una casa in albergo sul terreno"
              << board.getCoordinates(position) << " per "
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

bool HumanPlayer::show() const {
    std::string risposta;
    std::cout << "Giocatore " << this->getNumber() << ": Inserire show al fine di visualizzare: "
              << "\n\t- il tabellone"
              << "\n\t- lista terreni/case/alberghi posseduti da ogni giocatore"
              << "\n\t- l’ammontare di fiorini posseduto da tutti i giocatori\nRisposta: ";
    std::cin >> risposta;
    return risposta == "show";
}

std::ostream& operator<<(std::ostream &os, const HumanPlayer &obj) {
    return os << "Giocatore " << obj.getNumber() << " (real) saldo: " << obj.getBalance() << "\n";
}
