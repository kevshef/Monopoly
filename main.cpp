#include "include/Board.h"
#include "include/Players.h"

#include <iostream>

int main() {
    Board scoreboard;
    std::cout << scoreboard;

    Players players(0);
    std::cout << players;

    players.start();

    int turn = 0;

    do {
        std::cout << "\n\nTurno " << (turn + 1) << ":";

        for (int i = 0; i < 4; ++i) {

            if (!players.getPlayers()[i].isBankrupt()) {
                int moveResult = players.move(scoreboard, i);
                std::cout << "\nRisultato movimento: " << moveResult;

                if (moveResult > 0) {
                    if (scoreboard.getBoard()[players.getPlayers()[i].getPosition()].getOwnerNumber() != i ) {

                        std::cout << "\n\tGiocatore " << (i + 1)
                                  << " digitare Y o N se si vuole procedere o meno con l'acquisto di "
                                  << scoreboard.getBoard().at(players.getPlayers().at(i).getPosition()) << " per "
                                  << moveResult << " fiorini.";

                        std::string risposta = "";
                        do {
                            std::cout << "\n\tRisposta: ";
                            std::cin >> risposta;
                        } while (risposta != "Y" && risposta != "N");

                        if (risposta == "Y") {
                            players.getPlayers()[i].buy(moveResult);
                            scoreboard.getBoard()[players.getPlayers()[i].getPosition()].setNotFree(i);
                            players.updateTextFile(
                                    "Giocatore " + std::to_string(players.getPlayers().at(i).getNumber()) +
                                    " ha acquistato il terreno " +
                                    std::to_string(players.getPlayers().at(i).getPosition()));
                        }

                    } else {

                        std::cout << "\n\tGiocatore " << (i + 1)
                                  << " digitare Y o N se si vuole procedere o meno con il miglioramento in di "
                                  << scoreboard.getBoard().at(players.getPlayers().at(i).getPosition());

                        if (scoreboard.getBoard()[players.getPlayers()[i].getPosition()].getIdentifying() == '*' )
                            std::cout << " con un hotel.";
                        else
                            std::cout << " con una casa.";

                        std::string risposta = "";

                        do {

                            std::cout << "\n\tRisposta: ";

                            std::cin >> risposta;

                        } while (risposta != "Y" && risposta != "N");

                        if (risposta == "Y") {

                            players.getPlayers()[i].buy(moveResult);

                            if (scoreboard.getBoard()[players.getPlayers()[i].getPosition()].getIdentifying() == '*' ) {

                                scoreboard.getBoard()[players.getPlayers()[i].getPosition()].setIdentifying();
                                players.updateTextFile(
                                        "Giocatore " + std::to_string(players.getPlayers()[i].getNumber()) +
                                        " ha migliorato una casa in albergo sul terreno" +
                                        std::to_string(players.getPlayers()[i].getPosition()));
                            } else {

                                scoreboard.getBoard()[players.getPlayers()[i].getPosition()].setIdentifying();

                                players.updateTextFile(
                                        "Giocatore " + std::to_string(players.getPlayers()[i].getNumber()) +
                                        " ha costruito una casa sul terreno " +
                                        std::to_string(players.getPlayers()[i].getPosition()));
                            }
                        }
                    }
                }
                if (moveResult == -20) {
                    std::cout << "\n\nCASSSSAAAAA\n\n";
                }
            }
        }

        std::cout << "\nTurno " << (turn + 1) << " terminato.\n";
        turn++;

    } while (!players.end());

    std::cout << "\n" << scoreboard;
    std::cout << "\n" << players;

    return 0;
}
