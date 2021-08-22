/**
 * @file main.c
 * @author Paul Toffoloni
 * @date August 21, 2021
 * @brief File containing the definition and usage for Lasca:
 * Starts the game.
 */

#include <stdio.h>
#include "Multiplayer.h"

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
        case 2: break;
        case 3: break;
    }

    return 0;
}
