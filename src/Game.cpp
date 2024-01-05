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

    //@todo
    updateTextFile("");

    int new_position = mossa + players[playerIndex]->getPosition();

    if (new_position > 27) {
        new_position -= 27;
        players[playerIndex]->updateBalance();

        //@todo
        updateTextFile("");
    }

    players[playerIndex]->setPosition(new_position);

    //@todo
    updateTextFile(" ");

    if (board.getBoard()[new_position].getType() == static_cast<BoxType>(0)) {
        // intentionally left blank because angular position
        return 0;
    } else if (board.getBoard()[new_position].isFree()) {

        if (players[playerIndex]->buy(board.getBoard()[new_position], board.getBoard()[new_position].getPrice())) {
            //@todo
            updateTextFile(" ");
        }

        return 0;

    } else if (!board.getBoard()[new_position].isFree()) {

        if (board.getBoard()[new_position].getOwnerNumber() != players[playerIndex]->getNumber()) {

            int temp_price;

            if (board.getBoard()[new_position].getIdentifying() == '*') {

                players[playerIndex]->pay(players[board.getBoard()[new_position].getOwnerNumber() - 1],
                                          board.getBoard()[new_position].getDailyHousePrice());
                temp_price = board.getBoard()[new_position].getDailyHousePrice();

            } else {

                players[playerIndex]->pay(players[board.getBoard()[new_position].getOwnerNumber() - 1],
                                          board.getBoard()[new_position].getDailyHotelPrice());
                temp_price = board.getBoard()[new_position].getDailyHotelPrice();

            }
            //@todo
            updateTextFile(" ");

            if(players[playerIndex]->isBankrupt()){
                //@todo
                updateTextFile("");
            }

        } else if(board.getBoard()[new_position].getIdentifying() != '^') {

            if(board.getBoard()[new_position].getIdentifying() == '*') {

                players[playerIndex]->buildHotel(board.getBoard()[new_position]);

                //@todo
                updateTextFile("");

            } else {
                players[playerIndex]->buildHouse(board.getBoard()[new_position]);
                //@todo
                updateTextFile(" ");
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