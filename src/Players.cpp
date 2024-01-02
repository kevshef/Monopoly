//
// Created by Alvise Garberino on 02/01/24.
//

#include "../include/Players.h"

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

std::ostream& operator<<(std::ostream& os, Players& obj) {

    std::vector<Player> temp = obj.getPlayers();

    for (int i = 0; i < 4; ++i)
        os << temp[i];

    return os;
}

/**
 *
 * @return string
 *
 * Metodo che restituisce una stringa in base a queste categorie:
 * - Entrambi i giocatori:
 *      - -20 quando passa dal via
 *      - = 0 se la casella è di tipo angolare e quindi non vi è nulla da acquistare/pagare
 * - Giocatore real
 *      - > 0 se la proprietà è libera e la si vuole acquistare
 *      - < 0 se la proprietà è occupata e viene detratta direttamente la somma da pagare
 * - Giocatore computer
 *      - -5 se la proprietà era libera ed è stata acquistata
 *      - = 0 se:
 *          - la prorpità non è stata acquistata
 *          -
 */
int Players::Move(Board &board, int i) {
    std::vector<Box> temp_board = board.getBoard();

    int mossa = players[i].ThrowDice();

    AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) + " ha lanciato i dadi ed ottenuto un valore di " + std::to_string(mossa));

    int new_position = mossa + players[i].getPosition();

    if (new_position > 27)
        new_position -= 27;

    players[i].setPosition(new_position);

    AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) + " è arrivato alla casella " + std::to_string(new_position));


    if (temp_board[new_position].getStart()) {
        players[i].setBalance();
        AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) + " è passato per il via e ha ritirato 20 fiorini");
        return -20;
    }
    else if (temp_board[new_position].getType() == static_cast<BoxType>(0)) { // È angolare ma non start
        return 0;
    }
    else if (temp_board[new_position].isFree()) {
        if (players[i].getPlayerType() == 0) {
            return temp_board[new_position].getPrice();
        } else if (rand()%4 == 0) {
            players[i].Buy(temp_board[new_position].getPrice());
            temp_board[new_position].setNotFree(i);
            AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) + " ha acquistato il terreno " + std::to_string(new_position));
            board.setBoard(temp_board);
            return -5;
        }
    }
    else if (!temp_board[new_position].isFree()) {
        if (temp_board[new_position].getOwnerNumber() != players[i].getNumber()) {

            int temp_price;

            if (temp_board[new_position].getIdentifying() == "^") {
                players[i].Pay(players[temp_board[new_position].getOwnerNumber()],
                                temp_board[new_position].getDailyHotelPrice());
                temp_price = temp_board[new_position].getDailyHotelPrice();
            }
            else {
                players[i].Pay(players[temp_board[new_position].getOwnerNumber()],
                                temp_board[new_position].getDailyHousePrice());
                temp_price = temp_board[new_position].getDailyHousePrice();
            }

            AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) + " ha pagato " +
                              std::to_string(temp_price) + " a giocatore " +
                              std::to_string(temp_board[new_position].getOwnerNumber()) + " per pernottamento nella casella " +
                              std::to_string(new_position));

            if (players[i].isBankrupt())
                AggiornaFileTesto("Giocatore " + std::to_string(players[i].getNumber()) + " è stato eliminato");

            return -10;
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