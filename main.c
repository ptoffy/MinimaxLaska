/**
 * @file main.c
 * @author Paul Toffoloni
 * @date August 21, 2021
 * @mainpage Lasca
 * @section intro_sec Introduzione
 *
 * Il gioco è una variante della Dama, ideato dallo scacchista tedesco Emanuel Lasker nel 1911;
 * è noto anche come Laska o semplicemente come Lasker, o anche Laskers.
 * Si gioca con le stesse regole della Dama, ma su un campo di sole 49 caselle (7 per lato).
 * I pezzi catturati non vengono rimossi dal campo, ma trascinati e sormontati dal pezzo catturante.
 *
 * @section Struttura
 *
 * Il programma è strutturato in diversi Abstract Data Types (ADT).
 * Di seguito la lista:
 * - Board: Il campo da gioco, contenente una matrice fissa di Cell
 * - Cell: Una singola cella del campo da gioco, contenente eventualmente una Tower
 * - Piece: Un singolo pezzo di gioco
 * - Tower: Una torre, ovvero un array di Piece, ciò che viene usato in realtà giocando
 * - Move: Una singola mossa, contenente le Cell di origine e destinazione ed eventualmente una Cell da mangiare
 * - Moves: Una raccolta di Move che serve nel momento in cui dobbiamo calcolarci le possibili mosse
 *
 * Ogni struttura è a conoscenza esclusivamente dei suoi parametri e non conosce dati di altre strutture,
 * per accederci utilizza metodi come getter e setter, creati all'interno di ogni struttura.
 * Ogni funzione è il più possibile astratta con l'obiettivo del riuso del codice, di conseguenza la struttura
 * proposta è anche estremamente estendibile ed è molto semplice implementare nuove funzionalità senza dover ne
 * modificare ne conoscere per filo e per segno ogni riga del codice già scritto.
 *
 * All'interno della documentazione di Doxygen si possono trovare degli schemi che mostrano
 * la struttura del progetto a livello grafico in modo da facilitare la lettura.
 *
 * @section Funzionalità
 *
 * Il progetto funziona con le regole di Lasca normale, tuttavia non è ancora possibile svolgere più mangiate
 * in una mossa sola. Per implementare ciò servirebbe semplicemente aggiungere un ciclo o addirittura una ricorsione nella funzione
 * che si occupa di controllare la mossa e di svolgere la mangiata.
 *
 * Per giocare, il codice è estremamente user friendly e allo stesso tempo non permette all'utente di fare scelte sbagliate
 * che potrebbero andare a creare problemi nel codice, come per esempio immissione di coordinate sbagliate: sarà
 * il programma che proporrà all'utente quali mosse sono disponibili e gliene farà scegliere una. Ovviamente l'inserimento
 * della scelta da parte dell'utente è controllata e non permette l'inserimento errato di mosse.
 *
 * Il gioco finisce nel momento in cui non ci sono più mosse disponibili per colui che deve giocare il turno.
 *
 * Per il giocatore singolo, è stato implementato l'algoritmo Minimax in modo che la CPU possa fare delle scelte
 * con un certo criterio.
 *
 * @section Minimax
 *
 * 1. Crea un albero sulla base delle mosse disponibili, ogni livello di questo albero conterrà le mosse che un
 *       giocatore (sia CPU sia utente) può svolgere.
 * 2. Attraversa ricorsivamente l'albero creato, assegnando ad ogni mossa un valore, valutato sulla base del vantaggio
 *       che può portare alla CPU. Il valore è calcolato nella funzione `evaluate(Board *board)` e si basa sul numero di pezzi
 *       presenti sul campo da gioco dopo aver simulato una mossa, quindi indica se ci sono state delle mangiate o no
 *       e a favore di chi. Inoltre, tarato con meno importanza, c'è anche la quantità di pedine `Officer` presenti, quindi
 *       anche la possibilità di promuovere una pedina ha ruolo nella valutazione. Più il numero è alto, più e vantaggioso
 *       per il giocatore.
 * 3. Sceglie, per ogni livello, la mossa più conveniente comparando i valori delle varie mosse, a seconda del turno che
 *       si sta controllando si sceglierà il numero più alto (se il turno è lo stesso della CPU) oppure il numero più basso se
 *       il turno controllato è dell'utente.
 *
 * ![image](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6f/Minimax.svg/400px-Minimax.svg.png)
 *
 * Più la depth della AI è alta, quindi il numero di turni e di conseguenza il numero di mosse controllati, più l'AI
 * ci metterà a trovare un risultato. La complessità computazionale è **O(b^m)**, dove b è il numero di mosse possibili
 * per ogni turno ed m è il numero massimo di profondità (depth).
 */

#include <stdio.h>
#include "Multiplayer.h"
#include "SinglePlayer.h"

int main() {
    int choice;
    printf("Benvenuto!\n"
           "Che cosa vorresti fare?\n"
           "1) Multigiocatore\n"
           "2) Giocatore Singolo\n"
           "3) Esci\n");
    scanf("%d", &choice);

    fflush(stdin);

    switch (choice) {
        case 1: run_multiplayer(); break;
        case 2: run_single_player(); break;
        case 3: break;
        default: return 0;
    }
}
