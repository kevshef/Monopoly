Monopoly by Garberino Alvise, Shefkiu Kevin & Zarantonello Michele

## Descrizione
È una versione semplificata del gioco Monopoly, semplificata sia graficamente che concettualmente parlando. Alcune delle regole del gioco ufficiali del Monopoly sono state omesse come da specifiche.

## Requisiti di Sistema
CMAKE VERSION 3.22.1, C++ STANDARD 11

## Installazione
Istruzioni su come installare il progetto sul proprio sistema.

## Configurazione
Eventuali istruzioni o informazioni sulla configurazione del progetto dopo l'installazione.

## Utilizzo
mkdir build --> cmake .. --> make --> ./Monopoly human --> per il giocatore umano invece --> ./Monopoly computer per il giocatore computer

## Struttura delle Cartelle
Descrizione delle principali cartelle all'interno del progetto e la loro funzione.
- Include 
    - BankAccount.h: abbiamo deciso di definire una classe a parte per la gestione del “conto corrente” dei giocatori, implementa semplici e brevi funzioni per la gestione della richiesta e della modifica del saldo. In aggiunta fornisce anche un valore boolean per in caso di saldo inferiore o uguale a zero. 
    - Player.h: la classe player viene derivata dalla classe computerplayer e human player. Contiene i metodi necessari alla gestione dei players
    - HumanPlayer.h: la classe human player contiene i metodi necessari per la gestione di un giocatore umano. Metodo importante è il metodo show che ogni volta che è il turno di un giocatore umano permette tramite linea di comando di mostrare lo stato corrente della partita
    - ComputerPlayer.h: un giocatore che si auto gestisce, e che a differenza del giocatore umano gestisce l’acquisto incondizionato sia dei terreni che delle case e degli hotel con un 25% di probabilità.
    - Board.h: nella classe board abbiamo deciso di implementare il tabellone come un array di Box. La parte piu complessa è la stampa che viene effettuata andando a divedere l'array in ordine per poter gestire i giocatori nel modo piu semplice possibile
    - Box.h: in questa classe è stato scelto di utilizzare un’enumerazione che definisce il tipo della proprietà ed un’enumerazione che definisce la tipologia di casella (angolare o laterale e quindi con le proprietà) 
    - Game.h: classe ce gestisce l’intera partita, l’interazione tra i vari giocatori e l’interazione tra i giocatori ed il tabellone
- Src
    - BanckAccount.cpp
    - Player.cpp
    - HumanPlayer.cpp
    - ComputerPlayer.cpp
    - Board.cpp
    - Box.cpp
    - Game.cpp


## Note Aggiuntive
Il progetto è pubblicato su github al seguente link https://github.com/kevshef/Monopoly.
Abbiamo deciso di pubblicarlo per poterlo tenere come progetto portfolio per un futuro.

