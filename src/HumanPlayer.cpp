/**
 * Filename: Game.cpp
 * Author:
 * Created: 05/01/2024
 **/

#include "../include/HumanPlayer.h"

/**
 * @brief Constructor to initialize a human player with the specified player number and game board.
 *
 * @param playerNumber The unique identifier for the human player.
 * @param board Reference to the game board.
 *
 * @details Initializes a HumanPlayer object with the given player number and associates it with the provided game board.
 */
HumanPlayer::HumanPlayer(int playerNumber, Board &board) {

    this->board = board;
    position = 0;
    identifyingNumber = playerNumber;
    srand(static_cast<unsigned int>(std::time(nullptr)));

}

/**
 * @brief Allows the human player to decide whether to buy a land box.
 *
 * @param box The land box to consider for purchase.
 * @param amount The amount of money required to buy the land box.
 *
 * @return True if the human player decides to buy the land, false otherwise.
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
 * @brief Allows the human player to decide whether to build a house on a given box.
 *
 * @param box The land box on which the human player considers building a house.
 *
 * @return True if the human player decides to build a house, false otherwise.
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
 * @brief Allows the human player to decide whether to build a hotel on a given box.
 *
 * @param box The land box on which the human player considers building a hotel.
 *
 * @return True if the human player decides to build a hotel, false otherwise.
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
 * @brief Function to handle the "show" option displayed when playing with a human player.
 *
 * @param players Vector of shared pointers to players.
 * @param board Reference to the game board.
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

        std::cout << "\nTabellone:\n" << board;

        std::cout << "\nLista terreni/case/alberghi posseduti da ogni giocatore:\n";

        for (int i = 0; i < players.size(); ++i) {

            std::cout << "Giocatore " << players[i]->getNumber() << ": ";

            for (int j = 0; j < board.getBoard().size(); ++j) {

                if (board.getBoard()[j].getOwnerNumber() == players[i]->getNumber())
                    std::cout << board.getCoordinates(j) << board.getBoard()[j].getIdentifying() << " ";

            }
            std::cout << "\n";
        }

        std::cout << "\nSaldo giocatori:\n";

        for (int i = 0; i < players.size(); ++i)
            std::cout << "Giocatore " << players[i]->getNumber() << ": " << players[i]->getBalance() << "\n";

    }
}

/**
 * @brief Overload of the output stream insertion operator for HumanPlayer.
 *
 * @param os The output stream.
 * @param obj The HumanPlayer object to be output.
 *
 * @return The output stream after inserting information about the human player.
 */
std::ostream& operator<<(std::ostream &os, const HumanPlayer &obj) {
    return os << "Giocatore " << obj.getNumber() << " (real) saldo: " << obj.getBalance() << " fiorini\n";
}
