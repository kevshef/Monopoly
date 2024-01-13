//
// Created by Kevin Shefkiu on 05/01/24.
//

#include "../include/Game.h"

Game::Game(const char *gamer, Board &board) {

    if (strcmp("human",gamer)==0 || strcmp("HUMAN",gamer)==0) {
        players.push_back(std::make_shared<HumanPlayer>(HumanPlayer(1, board)));
    }

    for(int i = players.size() ; i < 4; i++)
        players.push_back(std::make_shared<ComputerPlayer>(ComputerPlayer(i + 1)));

    std::ofstream file("../data/load.txt", std::ios::trunc);
    file.close();

    gamer = nullptr;
}

// Function to simulate a player's move on the board
void Game::move(Board& board, int playerIndex) {

    int mossa = players[playerIndex]->throwDice();

    updateTextFile("- Giocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha tirato i dadi ottenendo un valore di " +
                   std::to_string(mossa));

    std::cout << "\n\tGiocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha tirato i dadi ottenendo un valore di " +
                 std::to_string(mossa) + "\n";

    int new_position = mossa + players[playerIndex]->getPosition();

    //Passa per il via
    if (new_position > 27) {

        new_position -= 27;

        players[playerIndex]->updateBalance();

        updateTextFile("- Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                       " è passato dal via e ha ritirato 20 fiorini");

        std::cout << "\tGiocatore " + std::to_string(players[playerIndex]->getNumber()) +
                     " è passato dal via e ha ritirato 20 fiorini" + "\n";

    }

    players[playerIndex]->setPosition(new_position);

    updateTextFile("- Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                   " è arrivato alla casella " + board.getCoordinates(new_position));

    std::cout << "\tGiocatore " + std::to_string(players[playerIndex]->getNumber()) +
                 " è arrivato alla casella " + board.getCoordinates(new_position) + "\n";

    const auto& currentPlayer = players[playerIndex];
    if (auto humanPlayer = std::dynamic_pointer_cast<HumanPlayer>(currentPlayer)) {

        std::vector<int> playersPosition;
        std::vector<int> playerIdentifier;

        for(int i = 0; i < 4; i++) {
            playersPosition.push_back(getPlayers()[i]->getPosition());
            playerIdentifier.push_back(getPlayers()[i]->getNumber());
        }

        for(int i = 0; i < board.getBoard().size(); i++)
            board.getBoard()[i].setPlayersPosition(playersPosition, playerIdentifier);

        humanPlayer->show(players, board);
    }


    if (board.getBoard()[new_position].isFree()) {

        if (players[playerIndex]->buy(board.getBoard()[new_position], board.getBoard()[new_position].getPrice())) {

            updateTextFile(
                    "- Giocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha acquistato il terreno " +
                    board.getCoordinates(new_position));

            std::cout << "\tGiocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha acquistato il terreno " +
                         board.getCoordinates(new_position) + "\n";

        }

    } else if (!board.getBoard()[new_position].isFree() && board.getBoard()[new_position].getType() != static_cast<BoxType>(0)) {

        if (board.getBoard()[new_position].getOwnerNumber() != players[playerIndex]->getNumber()) {

            int temp_price = 0;

            if (board.getBoard()[new_position].getIdentifying() == '*') {

                for (int i = 0; i < players.size(); ++i) {
                    if (players[i]->getNumber() == board.getBoard()[new_position].getOwnerNumber())
                        players[playerIndex]->pay(players[i], board.getBoard()[new_position].getDailyHousePrice());
                }

                temp_price = board.getBoard()[new_position].getDailyHousePrice();

            } else {

                for (int i = 0; i < players.size(); ++i) {
                    if (players[i]->getNumber() == board.getBoard()[new_position].getOwnerNumber())
                        players[playerIndex]->pay(players[i], board.getBoard()[new_position].getDailyHotelPrice());
                }

                temp_price = board.getBoard()[new_position].getDailyHotelPrice();

            }

            updateTextFile("- Giocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha pagato "
                           + std::to_string(temp_price) + " fiorini a giocatore " +
                           std::to_string(board.getBoard()[new_position].getOwnerNumber())
                           + " per pernottamento nella casella " + board.getCoordinates(new_position));

            std::cout << "\tGiocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha pagato "
                         + std::to_string(temp_price) + " fiorini a giocatore " +
                         std::to_string(board.getBoard()[new_position].getOwnerNumber())
                         + " per pernottamento nella casella " + board.getCoordinates(new_position) + "\n";

        } else if(board.getBoard()[new_position].getIdentifying() != '^') {

            if(board.getBoard()[new_position].getIdentifying() == '*') {

                if (players[playerIndex]->buildHotel(board.getBoard()[new_position])) {

                    updateTextFile("- Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                                   " ha migliorato una casa in albergo sul terreno " +
                                   board.getCoordinates(new_position));

                    std::cout << "\tGiocatore " + std::to_string(players[playerIndex]->getNumber()) +
                                 " ha migliorato una casa in albergo sul terreno " +
                                 board.getCoordinates(new_position) + "\n";

                }
            } else if (players[playerIndex]->buildHouse(board.getBoard()[new_position])) {

                updateTextFile(
                        "- Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                        " ha costruito una casa sul terreno " + board.getCoordinates(new_position));

                std::cout << "\tGiocatore " + std::to_string(players[playerIndex]->getNumber()) +
                             " ha costruito una casa sul terreno " + board.getCoordinates(new_position) + "\n";
            }
        }
    }
    if(players[playerIndex]->isBankrupt()){

        updateTextFile("- Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                       " è stato eliminato");

        std::cout << "\tGiocatore " + std::to_string(players[playerIndex]->getNumber()) +
                     " è stato eliminato\n";

        for (int i = 0; i < board.getBoard().size(); ++i) {
            if (board.getBoard()[i].getOwnerNumber() == players[playerIndex]->getNumber())
                board.getBoard()[i].setFree();
        }
        std::cout << "\nIl giocatore " << players[playerIndex]->getNumber() << " non possiede più alcuna proprietà";
        updateTextFile("- Giocatore " + std::to_string(players[playerIndex]->getNumber()) + " non possiede più alcuna proprietà.");
    }

    std::cout << "\b\tGiocatore " << players[playerIndex]->getNumber() << " ha finito il turno\n";
    updateTextFile("- Giocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha finito il turno.");

};

// Function to update a text file with a given message
void Game::updateTextFile(const std::string& message) {

    std::ofstream file("../data/Load.txt", std::ios::app);

    if (file.is_open()) {

        file << message << "\n";

        file.close();

    } else
        std::cerr << "Impossibile aprire il file per la scrittura. Verifica il percorso e i permessi." << std::endl;

}

// Function to determine the starting order of players based on dice rolls
// Function to determine the starting order of players based on dice rolls
std::vector<std::shared_ptr<Player>> Game::start(std::vector<std::shared_ptr<Player>> &temp) {


    std::vector<std::shared_ptr<Player>> sortedPlayers;

    std::vector<std::pair<std::shared_ptr<Player>, int>> playerValues; // {playerIndex, diceThrow}

    //Inserisco in playerValues
    for (int i = 0; i < temp.size(); ++i) {
        playerValues.push_back(std::make_pair(temp[i], temp[i]->throwDice()));
    }
    //Svuoto temp
    temp.clear();

    //Ordino PlayerValues
    std::sort(playerValues.begin(), playerValues.end(), [](const std::pair<std::shared_ptr<Player>, int> &a, const std::pair<std::shared_ptr<Player>, int> &b) {
        return a.second > b.second;
    });
    //Rimetto in temp
    for (int i = 0; i < playerValues.size(); ++i)
        temp.push_back(playerValues[i].first);

    for (int i = 0; i < playerValues.size(); i++)
    {
        if(i != playerValues.size() - 1 && playerValues[i].second == playerValues[i+1].second) {
            sortedPlayers.push_back(playerValues[i].first);
            sortedPlayers.push_back(playerValues[i + 1].first);
            if(i != playerValues.size() - 2 && playerValues[i].second == playerValues[i+2].second){
                sortedPlayers.push_back(playerValues[i + 2].first);
                if(i!=playerValues.size() - 3 && playerValues[i].second == playerValues[i + 3].second)
                    sortedPlayers.push_back(playerValues[i + 3].first);
            }
            temp.erase(std::next(temp.begin(), i), std::next(temp.begin(), i+sortedPlayers.size()));
            sortedPlayers = start(sortedPlayers);
            for (int j = sortedPlayers.size() - 1; j > -1; j--)
                temp.insert(std::next(temp.begin(), i), sortedPlayers.at(j));
            sortedPlayers.clear();
        }
    }

    return temp;

}

/**
 * @brief Checks if the game has ended by determining the number of bankrupt players.
 *
 * @return True if the game has ended, false otherwise.
 */
bool Game::end() const {

    int bankruptCount = 0;

    for (int i = 0; i < 4; i++) {

        if (players[i]->isBankrupt()) {

            bankruptCount++;

            if (bankruptCount >= 3)
                return true;

        }
    }

    return false;

}

void Game::richestPlayer() {

    int maxBalance = players[0]->getBalance();

    std::string richestPlayerId;
    int richest = players[0]->getNumber();
    bool isOne = true;

    for (int i = 1; i < players.size(); i++) {
        if (players[i]->getBalance() > maxBalance) {
            richest = players[i]->getNumber();
        }
    }

    richestPlayerId += std::to_string(richest) + " ";

    for(int i = 0 ; i < players.size(); i++) {
        if(players[i]->getBalance() == maxBalance && players[i]->getNumber() != richest) {
            richestPlayerId += std::to_string(players[i]->getNumber()) + " ";
            isOne = false;
        }
    }


    if(isOne) {
        std::cout << "\nIl vincitore è il giocatore " << richestPlayerId << "con un saldo di: " << maxBalance << " fiorini\n";
        updateTextFile("- Giocatore " + richestPlayerId + " ha vinto la partita");
    } else {
        std::cout << "\nVittoria ex-quo di giocatori " << richestPlayerId << "con un saldo di: " << maxBalance << " fiorini\n";
        updateTextFile("- Vittoria ex-quo di giocatori " + richestPlayerId);
    }
}

void Game::play(Board &board, int numeroTurni) {

    int turno = 0;

    setPlayers(start(players));

    board.getBoard()[0].setPlayersPosition({0,0,0,0}, {1,2,3,4});

    std::cout << board << "\n";

    do {

        std::cout << "\n\n turno " << (turno + 1) << " : \n";

        updateTextFile("\n Turno " + std::to_string(turno) + "\n");

        for (int i = 0; i < 4; i++) {

            if (!getPlayers()[i]->isBankrupt())
                move(board, i);
        }

        turno++;

    } while (!end() && turno < numeroTurni);

    std::cout << board;

    for (int i = 0; i < getPlayers().size(); ++i) {
        std::cout << "Giocatore " << getPlayers()[i]->getNumber() << ": ";
        for (int j = 0; j < board.getBoard().size(); ++j) {
            if (board.getBoard()[j].getOwnerNumber() == getPlayers()[i]->getNumber()) {
                std::cout << board.getCoordinates(j) << board.getBoard()[j].getIdentifying() << " ";
            }
        }
        std::cout << "\n";
    }

    richestPlayer();
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

        if (auto humanPlayer = std::dynamic_pointer_cast<HumanPlayer>(currentPlayer))
            os << *humanPlayer;
        else if (auto computerPlayer = std::dynamic_pointer_cast<ComputerPlayer>(currentPlayer))
            os << *computerPlayer;

    }

    return os;

}