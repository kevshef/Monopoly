Monopoly by Garberino Alvise, Shefkiu Kevin & Zarantonello Michele

## Descrizione
È una versione semplificata del gioco Monopoly, semplificata sia graficamente che concettualmente parlando. Alcune delle regole del gioco ufficiali del Monopoly sono state omesse come da specifiche.

## Requisiti di Sistema
Elenco dei requisiti hardware e software necessari per eseguire il progetto.

## Installazione
Istruzioni su come installare il progetto sul proprio sistema.

## Configurazione
Eventuali istruzioni o informazioni sulla configurazione del progetto dopo l'installazione.

## Utilizzo
Spiegazione su come utilizzare il progetto o l'applicazione.

## Struttura delle Cartelle
Descrizione delle principali cartelle all'interno del progetto e la loro funzione.
- Include 
    - BankAccount.h: abbiamo deciso di definire una classe a parte per la gestione del “conto corrente” dei giocatori, implementa semplici e brevi funzioni per la gestione della richiesta e della modifica del saldo. In aggiunta fornisce anche un valore boolean per in caso di saldo inferiore o uguale a zero. 
    - Player.h: @todo
    - HumanPlayer.h: @todo
    - ComputerPlayer.h: un giocatore che si auto gestisce, e che a differenza del giocatore umano gestisce l’acquisto incondizionato sia dei terreni che delle case e degli hotel con un 25% di probabilità.
    - Board.h: @todo
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

## Contribuire
Informazioni su come gli altri possono contribuire al progetto. Include eventuali linee guida per la creazione di pull request, norme di stile del codice, ecc.

## Contatti
Come contattare gli sviluppatori o la comunità del progetto.

## Note Aggiuntive
Eventuali note aggiuntive o avvertenze importanti.

