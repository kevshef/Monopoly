//
// Created by Kevin Shefkiu on 05/01/24.
//

#include "../include/HumanPlayer.h"

/**
 *
 * @param playerNumber
 * @param board
 *
 * @brief Constructor to initialize the board
 */

HumanPlayer::HumanPlayer(int playerNumber, Board &board) {

    this->board = board;
    position = 0;
    identifyingNumber = playerNumber;
    srand(static_cast<unsigned int>(std::time(nullptr)));

}
/**
 *
 * @param box
 * @param amount
 * @return true if Player decides to buy the land, false if not.
 */
bool HumanPlayer::buy(Box &box, int amount) {

    char answer = ' ';
    std::cout << "\n\tGiocatore " << getNumber()
              << " digitare S o N se si vuole procedere o meno con l'acquisto di " << board.getCoordinates(position)
              << " per " << amount
              << " fiorini." << "\n";
    do {
        std::cout << "\n\tRisposta : ";
        std::cin >> answer;

    } while (tolower(answer) != 's' && tolower(answer) != 'n');

    if (tolower(answer) == 's') {
        if (bankAccount.getBalance() >= amount) {
            bankAccount.updateBalance(-amount);
            box.setNotFree(getNumber());
            return true;
        }
    }

    return false;

}
/**
 *
 * @param box
 * @return true if the player decides to build a house, false if not
 */
bool HumanPlayer::buildHouse(Box &box) {

    if (bankAccount.getBalance() > box.getHousePrice()) {

        char answer = ' ';
        std::cout << "\n\tGiocatore " << getNumber()
                  << " digitare S o N se si vuole procedere o meno con la costruzione di una casa sul terreno di "
                  << board.getCoordinates(position)
                  << " per "
                  << box.getHousePrice() << " fiorini." << "\n";
        do {
            std::cout << "\n\tRisposta : ";
            std::cin >> answer;

        } while (tolower(answer) != 's' && tolower(answer) != 'n');

        if (tolower(answer) == 's') {
            if (bankAccount.getBalance() >= box.getHousePrice()) {
                bankAccount.updateBalance(-box.getHousePrice());
                box.setIdentifying();
                return true;
            }
        }
    }

    return false;

}
/**
 *
 * @param box
 * @return true if player decides to build a hotel, false if not
 */
bool HumanPlayer::buildHotel (Box &box) {

    if (bankAccount.getBalance() > box.getHotelPrice()) {

        char answer = ' ';
        std::cout << "\n\tGiocatore " << getNumber()
                  << " digitare S o N se si vuole procedere o meno per il miglioramento di una casa in albergo sul terreno"
                  << board.getCoordinates(position) << " per "
                  << box.getHotelPrice() << " fiorini." << "\n";
        do {
            std::cout << "\n\tRisposta : ";
            std::cin >> answer;

        } while (tolower(answer) != 's' && tolower(answer) != 'n');

        if (tolower(answer) == 's') {
            if (bankAccount.getBalance() >= box.getHotelPrice()) {
                bankAccount.updateBalance(-box.getHotelPrice());
                box.setIdentifying();
                return true;
            }
        }
    }

    return false;

}
/**
 *
 * @param players
 * @param board
 * @brief function to manage the show option displayed when playing with a human player.
 */
void HumanPlayer::show(std::vector<std::shared_ptr<Player>> players, Board& board) {

    std::string risposta;
    std::cout << "\nGiocatore " << this->getNumber() << ": Inserire 'show' o 'no' al fine di visualizzare o meno: "
              << "\n\t- il tabellone"
              << "\n\t- lista terreni/case/alberghi posseduti da ogni giocatore"
              << "\n\t- l’ammontare di fiorini posseduto da tutti i giocatori";

    do {
        std::cout << "\n\tRisposta : ";
        std::cin >> risposta;
        if(risposta != "show" && risposta != "no")
            std::cout<< "\nInvalid response: should be 'show' or 'no'.";
    } while (risposta != "show" && risposta != "no");

    if (risposta == "show") {

        // visualizzare il tabellone
        std::cout << "\nTabellone:\n" << board;

        // visualizzare lista terreni/case/alberghi posseduti da ogni giocatore
        std::cout << "\nLista terreni/case/alberghi posseduti da ogni giocatore:\n";
        for (int i = 0; i < players.size(); ++i) {
            std::cout << "Giocatore " << players[i]->getNumber() << ": ";
            for (int j = 0; j < board.getBoard().size(); ++j) {
                if (board.getBoard()[j].getOwnerNumber() == players[i]->getNumber()) {
                    std::cout << board.getCoordinates(j) << board.getBoard()[j].getIdentifying() << " ";
                }
            }
            std::cout << "\n";
        }

        // visualizzare l’ammontare di fiorini posseduto da tutti i giocatori
        std::cout << "\nSaldo giocatori:\n";
        for (int i = 0; i < players.size(); ++i) {
            std::cout << "Giocatore " << players[i]->getNumber() << ": " << players[i]->getBalance() << "\n";
        }
    }
}
/**
 *
 * @param os
 * @param obj
 * @return os
 * @brief overload of operator <<
 */
std::ostream& operator<<(std::ostream &os, const HumanPlayer &obj) {
    return os << "Giocatore " << obj.getNumber() << " (real) saldo: " << obj.getBalance() << " fiorini\n";
}
