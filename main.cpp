//
// Created by
//

#include "include/Board.h"
#include "include/Players.h"


#include <iostream>

int main() {

    Board scoreboard;


    std::cout << board;

    Players players(0);

    std::cout << players;

    int turno = 0;

    do{
        std::cout<< "\n\nTurno " << (turno + 1) << ":";

        for (int i = 0; i < 4; ++i) {

            if (!players.getPlayers()[i].isBankrupt()) {

                int move_result = players.Move(scoreboard, i);

                std::cout << "\nRisultatto movimento: " << move_result;

                if (move_result > 0) {
                    std::cout << "\n\tGiocatore " << (i + 1)
                              << " digitare Y o N se si vuole procedere o meno con l'acquisto di "
                              << scoreboard.getBoard().at(players.getPlayers().at(i).getPosition()) << " per "
                              << move_result << " fiorini.";

                    std::string risposta = "";
                    do {
                        std::cout << "\n\tRisposta: ";
                        std::cin >> risposta;
                    } while (risposta != "Y" && risposta != "N");

                    if (risposta == "Y") {
                        players.getPlayers()[i].Buy(move_result);
                        scoreboard.getBoard()[players.getPlayers()[i].getPosition()].setNotFree(i);
                        players.AggiornaFileTesto(
                                "Giocatore " + std::to_string(players.getPlayers().at(i).getNumber()) +
                                " ha acquistato il terreno " +
                                std::to_string(players.getPlayers().at(i).getPosition()));
                    }

                }

                if (move_result == -10) {
                    std::cout << "\n\t\t CASSAAAAAA\n\n\n";
                }
            }

            //std::cout<< "\n\tPosizione: " << players.getPlayers().at(i).getPosition();

            //std::cout<< "\n\t" << scoreboard.getBoard().at(players.getPlayers().at(i).getPosition());
        }

        std::cout<< "\nTurno " << (turno + 1) << " terminato.\n";

        turno ++;


    }while(!players.End() && turno < 10000);


    std::cout << "\n" << players;


    return 0;
}
