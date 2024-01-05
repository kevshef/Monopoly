//
// Created by Kevin Shefkiu on 05/01/24.
//

#include "../include/Game.h"


Game::Game(std::string gamer) {

    if(gamer == "human")
        players.push_back(std::make_shared<HumanPlayer>(HumanPlayer(1)));

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

    if (new_position > 27) {
        new_position -= 27;
        players[playerIndex]->updateBalance();

        updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                       " è passato per il via e ha ritirato 20 fiorini");
    }

    players[playerIndex]->setPosition(new_position);

    updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                   " è arrivato alla casella " + board.getCoordinates(new_position) );

    Box new_position_box = board.getBoard()[new_position];

    if (new_position_box.getType() == static_cast<BoxType>(0)) {
        // intentionally left blank because angular position
        return 0;
    } else if (new_position_box.isFree()) {

        if (players[playerIndex]->buy(new_position_box, new_position_box.getPrice())) {

            updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha acquistato il terreno " + board.getCoordinates(new_position) );
        }

        return 0;

    } else if (!new_position_box.isFree()) {

        if (new_position_box.getOwnerNumber() != players[playerIndex]->getNumber()) {
//@todo checkare se getownernumber e getnumber funzionano correttamente
            int temp_price;

            if (new_position_box.getIdentifying() == '*') {

                players[playerIndex]->pay(players[new_position_box.getOwnerNumber() - 1],new_position_box.getDailyHousePrice());
                temp_price = new_position_box.getDailyHousePrice();

            } else {

                players[playerIndex]->pay(players[new_position_box.getOwnerNumber() - 1],new_position_box.getDailyHotelPrice());
                temp_price = new_position_box.getDailyHotelPrice();

            }

            updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) + " ha pagato "
                           + std::to_string(temp_price) + " a giocatore " +
                           std::to_string(new_position_box.getOwnerNumber() + 1)
                           + " per pernottamento nella casella " + board.getCoordinates(new_position));

            if(players[playerIndex]->isBankrupt()){

                updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                               " è stato eliminato");
            }


        } else if(new_position_box.getIdentifying() != '^') {

            if(new_position_box.getIdentifying() == '*') {

                players[playerIndex]->buildHotel(new_position_box);


                updateTextFile("Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                               " ha migliorato una casa in albergo sul terreno " +
                               board.getCoordinates(new_position));

            } else {
                players[playerIndex]->buildHouse(new_position_box);

                updateTextFile(
                        "Giocatore " + std::to_string(players[playerIndex]->getNumber()) +
                        " ha costruito una casa sul terreno " + board.getCoordinates(new_position));
            }
        }
    }
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
    int tempThrowDice[4];

    // Roll the dice for each player and check for duplicates
    do {
        for (int i = 0; i < 4; ++i) {
            tempThrowDice[i] = players[i]->throwDice();
        }
    } while (tempThrowDice[0] == tempThrowDice[2] || tempThrowDice[0] == tempThrowDice[3] ||
             tempThrowDice[1] == tempThrowDice[2] || tempThrowDice[1] == tempThrowDice[3]);

    // Sort players based on dice throw values
    std::vector<std::pair<int, int>> playerValues; // {playerIndex, diceThrow}
    for (int i = 0; i < 4; ++i) {
        playerValues.push_back(std::make_pair(i, tempThrowDice[i]));
    }

    std::sort(playerValues.begin(), playerValues.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second > b.second;
    });

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
std::ostream& operator<<(std::ostream& os, Game& obj) {

    for (int i = 0; i < 4; ++i)
        os << obj.getPlayers()[i];

    return os;


}