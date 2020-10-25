#include <stdio.h>
#include "Cella.h"
#include "Pedina.h"

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET  "\x1b[0m"

/**
 Se la pedina è null, stampa 0.
 Se la pedina è diversa da null, stampa un numero indicante l'altezza della pedina,
 del colore del possessore della pedina.
 */
void stampaContenutoCella(Cella *cella) {
    if (cella->pedina != NULL) {
        if (cella->pedina->colore == 0) {
            printf(ANSI_COLOR_RED);
            printf("%d ", cella->pedina->altezza);
            printf(ANSI_COLOR_RESET);
        } else {
            printf(ANSI_COLOR_YELLOW);
            printf("%d ", cella->pedina->altezza);
            printf(ANSI_COLOR_RESET);
        }
    } else {
        printf("0 ");
    }
}

void setPedinaToNull(Cella* cella) {
    cella->pedina = NULL;
}

struct Pedina *pedina(Cella *cella) {
    return cella->pedina;
}
