#include "../include/Players.h"
#include <algorithm> // std::sort

/**
 * @brief Constructor for the Players class.
 *
 * @param numberOfPlayers The number of players in the game.
 *
 * @details Initializes a Players object with a specified number of real and computer players.
 * The random number generator is seeded with the current time, and a file "Load.txt" is created.
 */
Players::Players(int numberOfPlayers) {
    srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create real players
    for (int i = 0; i < numberOfPlayers; ++i) {
        players.push_back(Player(PlayerType::REAL, i + 1));
    }

    // Fill remaining slots with computer players
    for (int i = numberOfPlayers; i < 4; ++i) {
        players.push_back(Player(PlayerType::COMPUTER, i + 1));
    }

    // Create an empty file "Load.txt"
    std::ofstream file("../data/Load.txt", std::ios::trunc);
    file.close();
}

/**
 * @brief Getter function to retrieve the vector of Player objects.
 *
 * @return The vector of Player objects.
 */
std::vector<Player>& Players::getPlayers() {
    return players;
}

/**
 * @brief Setter function to update the vector of Player objects.
 *
 * @param newPlayers The new vector of Player objects.
 */
void Players::setPlayers(const std::vector<Player>& newPlayers) {
    players = newPlayers;
}

/**
 * @brief Moves a player on the board based on dice throw and updates game state accordingly.
 *
 * @param board The game board.
 * @param i The index of the player in the vector.
 *
 * @return The result of the move, if applicable.
 *
 * @details Moves the player on the board, checks for various conditions such as property ownership,
 * payments, and purchases, and updates the game state.
 */
int Players::move(Board& board, int i) {
    std::vector<Box> temp_board = board.getBoard();

    int mossa = players[i].throwDice();

    updateTextFile(
            "Giocatore " + std::to_string(players[i].getNumber()) + " ha lanciato i dadi ed ottenuto un valore di " +
            std::to_string(mossa));

    int new_position = mossa + players[i].getPosition();

    if (new_position > 27) {
        new_position -= 27;
        players[i].updateBalance();
        updateTextFile("Giocatore " + std::to_string(players[i].getNumber()) +
                       " è passato per il via e ha ritirato 20 fiorini");
    }

    players[i].setPosition(new_position);

    updateTextFile("Giocatore " + std::to_string(players[i].getNumber()) + " è arrivato alla casella " +
                      std::to_string(new_position));



    if (temp_board[new_position].getType() == static_cast<BoxType>(0)) { // È angolare ma non start
        return 0;
    } else if (temp_board[new_position].isFree()) {
        if (players[i].getPlayerType() == 0) {
            return temp_board[new_position].getPrice();
        } else if (rand() % 4 == 0) {
            players[i].buy(temp_board[new_position].getPrice());
            temp_board[new_position].setNotFree(i);
            updateTextFile("Giocatore " + std::to_string(players[i].getNumber()) + " ha acquistato il terreno " +
                              std::to_string(new_position));
            board.setBoard(temp_board);
        }
    } else if (!temp_board[new_position].isFree()) {
        if (temp_board[new_position].getOwnerNumber() != players[i].getNumber()) {

            int temp_price;

            if (temp_board[new_position].getIdentifying() == '^') {
                players[i].pay(players[temp_board[new_position].getOwnerNumber()],
                               temp_board[new_position].getDailyHotelPrice());
                temp_price = temp_board[new_position].getDailyHotelPrice();
            } else {
                players[i].pay(players[temp_board[new_position].getOwnerNumber()],
                               temp_board[new_position].getDailyHousePrice());
                temp_price = temp_board[new_position].getDailyHousePrice();
            }

            updateTextFile("Giocatore " + std::to_string(players[i].getNumber()) + " ha pagato " +
                              std::to_string(temp_price) + " a giocatore " +
                              std::to_string(temp_board[new_position].getOwnerNumber() + 1) +
                              " per pernottamento nella casella " +
                              std::to_string(new_position));


            if (players[i].isBankrupt())
                updateTextFile("Giocatore " + std::to_string(players[i].getNumber()) + " è stato eliminato");

        } else if (temp_board[new_position].getIdentifying() != '^') {
            if (players[i].getPlayerType() == 0) {
                if (temp_board[new_position].getIdentifying() == '*')
                    return (-1) * temp_board[new_position].getHotelPrice();
                else
                    return (-1) * temp_board[new_position].getHousePrice();
            } else if (rand() % 4 == 0) {

                if (temp_board[new_position].getIdentifying() == '*') {
                    players[i].buy(temp_board[new_position].getHotelPrice());
                    temp_board[new_position].setIdentifying();
                    updateTextFile("Giocatore " + std::to_string(players[i].getNumber()) +
                                      " ha migliorato una casa in albergo sul terreno " +
                                      std::to_string(new_position));
                } else {
                    players[i].buy(temp_board[new_position].getHousePrice());
                    temp_board[new_position].setIdentifying();
                    updateTextFile(
                            "Giocatore " + std::to_string(players[i].getNumber()) + " ha costruito una casa sul terreno " +
                            std::to_string(new_position));
                }
                board.setBoard(temp_board);
            }
        }
    }
    return 0;
}

/**
 * @brief Helper function to update the game state text file with a given message.
 *
 * @param message The message to be added to the text file.
 */
void Players::updateTextFile(const std::string& message) {
    std::ofstream file("../data/Load.txt", std::ios::app);
    if (file.is_open()) {
        file << message << "\n";
        file.close();
    } else {
        std::cerr << "Impossibile aprire il file per la scrittura. Verifica il percorso e i permessi." << std::endl;
    }
}

/**
 * @brief Initiates the game by determining player order based on dice throws.
 *
 * @return True if the game can continue, false if an error occurs.
 */
bool Players::start() {
    int tempThrowDice[4];

    // Roll the dice for each player and check for duplicates
    do {
        for (int i = 0; i < 4; ++i) {
            tempThrowDice[i] = players[i].throwDice();
        }
    } while (tempThrowDice[0] == tempThrowDice[2] || tempThrowDice[0] == tempThrowDice[3] || tempThrowDice[1] == tempThrowDice[2] || tempThrowDice[1] == tempThrowDice[3]);

    // Sort players based on dice throw values
    std::vector<std::pair<int, int>> playerValues; // {playerIndex, diceThrow}
    for (int i = 0; i < 4; ++i) {
        playerValues.push_back(std::make_pair(i, tempThrowDice[i]));
    }

    std::sort(playerValues.begin(), playerValues.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second > b.second;
    });

    // Rearrange players vector based on sorted order
    std::vector<Player> sortedPlayers;
    for (const auto &pv : playerValues) {
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
bool Players::end() const {
    int bankruptCount = 0;

    for (int i = 0; i < 4; ++i) {
        if (players[i].isBankrupt()) {
            bankruptCount++;
            if (bankruptCount >= 3)
                return true;
        }
    }

    return false;
}

/**
 * @brief Overloaded stream insertion operator to allow printing Players objects to an ostream.
 *
 * @param os The output stream to which the Players information will be printed.
 * @param obj The Players object to be printed.
 *
 * @return The modified output stream.
 *
 * @details Prints information about each player in the Players object.
 */
std::ostream& operator<<(std::ostream& os, Players& obj) {
    std::vector<Player> temp = obj.getPlayers();

    for (int i = 0; i < 4; ++i)
        os << temp[i];

    return os;
}