//
// Created by Kevin Shefkiu on 05/01/24.
//

#include "../include/Game.h"

Game::Game(std::string gamer, Board &board) {

    if(gamer == "human")
        players.push_back(std::make_shared<HumanPlayer>(HumanPlayer(1, board)));

    for(int i = players.size() ; i < 4; i++) {

        players.push_back(std::make_shared<ComputerPlayer>(ComputerPlayer(i + 1)));

    }

    std::ofstream file("../data/load.txt", std::ios::trunc);
    file.close();

}

// Function to simulate a player's move on the board
int Game::move(Board& board, int playerIndex) {

    int mossa = players[playerIndex]->throwDice();

    updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha lanciato i dadi ed ottenuto un valore di " +
                   std::to_string(mossa));

    int new_position = mossa + players[playerIndex]->getPosition();

    //Passa per il via
    if (new_position > 27) {
        new_position -= 27;
        players[playerIndex]->updateBalance();

        updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                       " è passato per il via e ha ritirato 20 fiorini");
    }

    players[playerIndex]->setPosition(new_position);

    updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                   " è arrivato alla casella " + board.getCoordinates(new_position) );

    const auto& currentPlayer = players[playerIndex];
    if (auto humanPlayer = std::dynamic_pointer_cast<HumanPlayer>(currentPlayer)) {
        if (humanPlayer->show()) {

            //● visualizzare il tabellone
            std::cout << "\nTabellone:\n" << board;

            //● visualizzare lista terreni/case/alberghi posseduti da ogni giocatore
            std::cout << "\nLista terreni/case/alberghi posseduti da ogni giocatore:\n";
            for (int i = 0; i < players.size(); ++i) {
                std::cout << "Giocatore " << players[i]->getNumber() << ": ";
                for (int j = 0; j < board.getBoard().size(); ++j) {
                    if (board.getBoard()[j].getOwnerNumber() == players[i]->getNumber()) {
                        std::cout << board.getCoordinates(j) << " ";
                    }
                }
                std::cout << "\n";
            }

            //● visualizzare l’ammontare di fiorini posseduto da tutti i giocatori
            std::cout << "\nSaldo giocatori:\n";
            for (int i = 0; i < players.size(); ++i) {
                std::cout << "Giocatore " << players[i]->getNumber() << ": " << players[i]->getBalance() << "\n";
            }
        }
    }

    if (board.getBoard()[new_position].getType() == static_cast<BoxType>(0)) {
        // intentionally left blank because angular position
        return 0;
    } else if (board.getBoard()[new_position].isFree()) {

        //Casella libera acquistabile
        if (players[playerIndex]->buy(board.getBoard()[new_position], board.getBoard()[new_position].getPrice())) {
            updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha acquistato il terreno " + board.getCoordinates(new_position) + " per: " + std::to_string(board.getBoard()[new_position].getPrice()));
        }

        return 0;

    } else if (!board.getBoard()[new_position].isFree()) {

        if (board.getBoard()[new_position].getOwnerNumber() != players[playerIndex]->getNumber()) {
            //@todo checkare se getownernumber e getnumber funzionano correttamente
            int temp_price;

            if (board.getBoard()[new_position].getIdentifying() == '*') {

                players[playerIndex]->pay(players[board.getBoard()[new_position].getOwnerNumber() - 1],board.getBoard()[new_position].getDailyHousePrice());
                temp_price = board.getBoard()[new_position].getDailyHousePrice();

            } else {

                players[playerIndex]->pay(players[board.getBoard()[new_position].getOwnerNumber() - 1],board.getBoard()[new_position].getDailyHotelPrice());
                temp_price = board.getBoard()[new_position].getDailyHotelPrice();

            }

            updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha pagato "
                           + std::to_string(temp_price) + " a giocatore " +
                           std::to_string(board.getBoard()[new_position].getOwnerNumber())
                           + " per pernottamento nella casella " + board.getCoordinates(new_position));

            if(players[playerIndex]->isBankrupt()){

                updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                               " è stato eliminato");
            }


        } else if(board.getBoard()[new_position].getIdentifying() != '^') {

            if(board.getBoard()[new_position].getIdentifying() == '*') {

                players[playerIndex]->buildHotel(board.getBoard()[new_position]);


                updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                               " ha migliorato una casa in albergo sul terreno " +
                               board.getCoordinates(new_position));

            } else {
                players[playerIndex]->buildHouse(board.getBoard()[new_position]);

                updateTextFile(
                        "Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                        " ha costruito una casa sul terreno " + board.getCoordinates(new_position));
            }
        }
    }
    return 0;
};

// Function to update a text file with a given message
void Game::updateTextFile(const std::string& message) {
    std::ofstream file("../data/Load.txt", std::ios::app);
    if (file.is_open()) {
        file << message << "\n";
        file.close();
    } else {
        std::cerr << "Impossibile aprire il file per la scrittura. Verifica il percorso e i permessi." << std::endl;
    }
}

// Function to determine the starting order of players based on dice rolls
bool Game::start() {
    std::vector<std::pair<int, int>> playerValues; // {playerIndex, diceThrow}

    for (int i = 0; i < 4; ++i) {
        int diceThrow = players[i]->throwDice();
        playerValues.push_back(std::make_pair(i, diceThrow));
    }

    std::sort(playerValues.begin(), playerValues.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second > b.second;
    });

    for (int i = 1; i < playerValues.size(); ++i) {
        if (playerValues[i].second == playerValues[i - 1].second) {
            // Reroll for tied players
            int playerIndex = playerValues[i].first;
            int newDiceThrow = players[playerIndex]->throwDice();

            // Update the dice throw value and re-sort
            playerValues[i].second = newDiceThrow;
            std::sort(playerValues.begin(), playerValues.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
                return a.second > b.second;
            });

            i = 0;
        }
    }

    // Rearrange players vector based on sorted order
    std::vector<std::shared_ptr<Player>> sortedPlayers;
    for (const auto &pv: playerValues) {
        sortedPlayers.push_back(players[pv.first]);
    }

    setPlayers(sortedPlayers);
    return true;
}

/**
 * @brief Checks if the game has ended by determining the number of bankrupt players.
 *
 * @return True if the game has ended, false otherwise.
 */
bool Game::end() const {
    int bankruptCount = 0;

    for (int i = 0; i < 4; ++i) {
        if (players[i]->isBankrupt()) {
            bankruptCount++;
            if (bankruptCount >= 3)
                return true;
        }
    }

    return false;
}

int Game::richestPlayer() const {
    int maxBalance = players[0]->getBalance();
    int richestPlayerId = 0;

    for (size_t i = 1; i < players.size(); ++i) {
        if (players[i]->getBalance() > maxBalance) {
            maxBalance = players[i]->getBalance();
            richestPlayerId = i;
        }
    }

    return richestPlayerId;
}

/**
 * @brief Overloaded stream insertion operator to allow printing Game objects to an ostream.
 *
 * @param os The output stream to which the Game information will be printed.
 * @param obj The Game object to be printed.
 *
 * @return The modified output stream.
 *
 * @details Prints information about each player in the Game object.
 */
std::ostream& operator<<(std::ostream& os, const Game& obj) {
    for (int i = 0; i < 4; ++i) {
        const auto& currentPlayer = obj.getPlayers()[i];
        if (auto humanPlayer = std::dynamic_pointer_cast<HumanPlayer>(currentPlayer)) {
            os << *humanPlayer;
        } else if (auto computerPlayer = std::dynamic_pointer_cast<ComputerPlayer>(currentPlayer)) {
            os << *computerPlayer;
        }
    }
    return os;
}