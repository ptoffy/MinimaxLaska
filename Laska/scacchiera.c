#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int MAX_X = 36;
int MAX_Y = 36;

void esercizioSchacchieraAuto() {
    int foo = 0;
    int i, f;
    /* Ciclo colonne */
    for (i = 0; i < MAX_Y; i++) {
        /* Ciclo righe */
        for (f = 0; f < MAX_X; f++) {
            /* Se la riga è un divisore */
            if (i % 5 == 0) {
                if (f % (MAX_X - 1) == 0) {
                    printf("+");
                } else {
                    printf("-");
                }
            } else {
                if (f % 5 == 0) {
                    printf("|");
                } else if (foo == 0) {
                    if (foo == 0) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                } else {
                    if (foo == 0) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                }
            }
            if (f % 5 == 0) {
                foo = !foo;
            }
        }
        printf("\n");
        if (i % 5 == 0) {
            foo = !foo;
        }
    }
    printf("\n");
}
