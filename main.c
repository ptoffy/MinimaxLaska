/**
 * @file main.c
 * @author Paul Toffoloni
 * @date August 21, 2021
 * @mainpage Lasca
 * @section intro_sec Introduzione
 *
 * Il gioco è una variante della Dama, ideata dallo scacchista tedesco Emanuel Lasker nel 1911;
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


    switch (choice) {
        case 1: run_multiplayer(); break;
        case 2: run_single_player(); break;
        case 3: break;
        default: return 0;
    }
}
