//
// Created by Alvise Garberino on 02/01/24.
//

#include "../include/Players.h"
#include <algorithm> // std::sort

Players::Players(int k) {

    srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i <k; ++i) {
        players.push_back(Player(0, i + 1));
    }

    for (int i = k; i < 4; ++i) {
        players.push_back(Player(1, i + 1));
    }

    std::ofstream file("../data/Load.txt", std::ios::trunc);
    file.close();

}

void Players::Start() {
    int lanciodadi[4];

    // Roll the dice for each player and check for duplicates
    do {
        for (int i = 0; i < 4; ++i) {
            lanciodadi[i] = players[i].ThrowDice();
        }
    } while (lanciodadi[0] == lanciodadi[2] || lanciodadi[0] == lanciodadi[3] || lanciodadi[1] == lanciodadi[2] || lanciodadi[1] == lanciodadi[3]);

    // Sort players based on lanciodadi values
    std::vector<std::pair<int, int>> playerValues; // {playerIndex, lanciodadi}
    for (int i = 0; i < 4; ++i) {
        playerValues.push_back(std::make_pair(i, lanciodadi[i]));
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
}

std::ostream& operator<<(std::ostream& os, Players& obj) {

    std::vector<Player> temp = obj.getPlayers();

    for (int i = 0; i < 4; ++i)
        os << temp[i];

    return os;
}

/**
 *
 * @return int
 *
 * Metodo che restituisce un INTERO solo nel caso di giocatore di tipo real
 * - Giocatore real
 *      - > 0 se la proprietà è libera e la si vuole acquistare o se la si può migliorare con casa/hotel
 *      - < 0 se la proprietà è occupata e viene detratta direttamente la somma da pagare
 */
int Players::Move(Board &board, int i) {
    std::vector<Box> temp_board = board.getBoard();

    int mossa = players[i].ThrowDice();

    AggiornaFileTesto(
            "Giocatore " + std::to_string(players[i].getNumber()) + " ha lanciato i dadi ed ottenuto un valore di " +
            std::to_string(mossa));

    int new_position = mossa + players[i].getPosition();

    if (new_position > 27)
        new_position -= 27;

    players[i].setPosition(new_position);

    AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) + " è arrivato alla casella " +
                      std::to_string(new_position));


    if (temp_board[new_position].getStart()) {
        players[i].setBalance();
        AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) +
                          " è passato per il via e ha ritirato 20 fiorini");
    } else if (temp_board[new_position].getType() == static_cast<BoxType>(0)) { // È angolare ma non start
        return 0;
    } else if (temp_board[new_position].isFree()) {
        if (players[i].getPlayerType() == 0) {
            return temp_board[new_position].getPrice();
        } else if (rand() % 4 == 0) {
            players[i].Buy(temp_board[new_position].getPrice());
            temp_board[new_position].setNotFree(i);
            AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) + " ha acquistato il terreno " +
                              std::to_string(new_position));
            board.setBoard(temp_board);
        }
    } else if (!temp_board[new_position].isFree()) {
        if (temp_board[new_position].getOwnerNumber() != players[i].getNumber()) {

            int temp_price;

            if (temp_board[new_position].getIdentifying() == "^") {
                players[i].Pay(players[temp_board[new_position].getOwnerNumber()],
                               temp_board[new_position].getDailyHotelPrice());
                temp_price = temp_board[new_position].getDailyHotelPrice();
                AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) + "ha migliorato una casa in albergo sul terreno" +
                                  std::to_string(temp_price) + " a giocatore " +
                                  std::to_string(temp_board[new_position].getOwnerNumber() + 1) +
                                  " per pernottamento nella casella " +
                                  std::to_string(new_position));
            } else {
                players[i].Pay(players[temp_board[new_position].getOwnerNumber()],
                               temp_board[new_position].getDailyHousePrice());
                temp_price = temp_board[new_position].getDailyHousePrice();
                AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) + " ha pagato " +
                                  std::to_string(temp_price) + " a giocatore " +
                                  std::to_string(temp_board[new_position].getOwnerNumber() + 1) +
                                  " per pernottamento nella casella " +
                                  std::to_string(new_position));
            }



            if (players[i].isBankrupt())
                AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) + " è stato eliminato");

        } else if (temp_board[new_position].getIdentifying() != "^") {
            if (players[i].getPlayerType() == 0) {
                if (temp_board[new_position].getIdentifying() == "*")
                    return (-1) * temp_board[new_position].getHotelPrice();
                else
                    return (-1) * temp_board[new_position].getHousePrice();
            } else if (rand() % 4 == 0) {

                if (temp_board[new_position].getIdentifying() == "*") {
                    players[i].Buy(temp_board[new_position].getHotelPrice());
                    temp_board[new_position].setIdentifying();
                    AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) +
                                      " ha migliorato una casa in albergo sul terreno" +
                                      std::to_string(new_position));
                } else {
                    players[i].Buy(temp_board[new_position].getHousePrice());
                    temp_board[new_position].setIdentifying();
                    AggiornaFileTesto(
                            "Giocatore " + std::to_string(players[i].getNumber()) + " ha costruito una casa sul terreno " +
                            std::to_string(new_position));
                }
                board.setBoard(temp_board);
            }
        }
    }
    return 0;
}

void Players::AggiornaFileTesto(std::string s) {
    std::ofstream file("../data/Load.txt", std::ios::app);

    // Controlla se il file è aperto correttamente
    if (file.is_open()) {
        // Scrive il messaggio nel file
        file << s << "\n";

        // Chiude il file
        file.close();
    } else {
        std::cerr << "Impossibile aprire il file per la scrittura. Verifica il percorso e i permessi." << std::endl;
    }
}

bool Players::End() {
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