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
 * - Giocatore real
 *      - > 0 se la proprietà è libera e la si vuole acquistare
 *      - < 0 se la proprietà è occupata e viene detratta direttamente la somma da pagare
 *      - = 0 se la casella è di tipo angolare e quindi non vi è nulla da acquistare/pagare
 * - Giocatore computer
 *      - -5 se la proprietà era libera ed è stata acquistata
 *      - = 0 se:
 *          - la prorpità non è stata acquistata
 *          - era una casella di tipo angolare
 *          -
 */
int Players::Move(Board &board, int i) {
    std::vector<Box> temp_board = board.getBoard();

    Player temp_player = players.at(i);

    int mossa = temp_player.ThrowDice();

    AggiornaFileTesto("Giocatore " + std::to_string(temp_player.getNumber()) + " ha lanciato i dadi ed ottenuto un valore di " + std::to_string(mossa));

    int new_position = mossa + temp_player.getPosition();

    if (new_position > 27)
        new_position -= 27;

    temp_player.setPosition(new_position);

    AggiornaFileTesto("Giocatore " + std::to_string(temp_player.getNumber()) + " è arrivato alla casella " + std::to_string(new_position));

    if (temp_board.at(new_position).getStart()) {
        temp_player.setBalance();
        AggiornaFileTesto("Giocatore " + std::to_string(temp_player.getNumber()) + " è passato per il via e ha ritirato 20 fiorini");
        return 0;
    } else if (temp_board.at(new_position).getType() == static_cast<BoxType>(0)) { // È angolare ma non start
        return 0;
    }else if (temp_board.at(new_position).isFree()) {
        if (temp_player.getPlayerType() == 0)
            return temp_board.at(new_position).getPrice();
        else if (rand()%4 == 0) {
            temp_player.Buy(temp_board.at(new_position).getPrice());
            AggiornaFileTesto("Giocatore " + std::to_string(temp_player.getNumber()) + " ha acquistato il terreno " + std::to_string(new_position));
            return -5;
        }
    } else if (!temp_board.at(new_position).isFree()) {
        if (temp_board.at(new_position).getOwnerNumber() != temp_player.getNumber()) {

            int temp_price;

            if (temp_board.at(new_position).getIdentifying() == "^") {
                temp_player.Pay(players.at(temp_board.at(new_position).getOwnerNumber()),
                                temp_board.at(new_position).getDailyHotelPrice());
                temp_price = temp_board.at(new_position).getDailyHotelPrice();
            } else {
                temp_player.Pay(players.at(temp_board.at(new_position).getOwnerNumber()),
                                temp_board.at(new_position).getDailyHousePrice());
                temp_price = temp_board.at(new_position).getDailyHousePrice();
            }

            AggiornaFileTesto("Giocatore " + std::to_string(temp_player.getNumber()) + " ha pagato " +
                              std::to_string(temp_price) + " a giocatore " +
                              std::to_string(temp_board.at(new_position).getOwnerNumber()) + " per pernottamento nella casella " +
                              std::to_string(new_position));

            if (temp_player.isBankrupt())
                AggiornaFileTesto("Giocatore " + std::to_string(temp_player.getNumber()) + " è stato eliminato");

            return -temp_price;
        }
    }
}

void Players::AggiornaFileTesto(std::string s) {

}