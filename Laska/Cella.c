#include <stdio.h>
#include "Cella.h"
#include "Pedina.h"

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET  "\x1b[0m"

void stampaContenutoCella(struct Cella *cella) {
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

void toNull(struct Cella* cella) {
    cella->pedina = NULL;
}

struct Pedina *pedina(struct Cella *cella) {
    return cella->pedina;
}
