#include <stdlib.h>
#include "Campo.h"
#include "Cella.h"

struct Campo {
    int righe, colonne;
    struct Cella* celle;
};

struct Campo* creaCampo(int righe, int colonne) {
    int i, f;
    struct Campo *campo = malloc(sizeof(struct Campo));
    campo->righe = righe;
    campo->colonne = colonne;
    campo->celle = malloc(sizeof(struct Cella) * righe * colonne);
    for (i = 0; i < righe; i++) {
        for (f = 0; f < colonne; f++) {
            campo->celle[i*colonne + f].colore = 0;
            campo->celle[i*colonne + f].x = f;
            campo->celle[i*colonne + f].y = i;
            toNull(&campo->celle[i*colonne + f]);
        }
    }
    return campo;
}

void inizializzaCampo(struct Campo* campo) {
    int i, f;
    for (i = 0; i < campo->righe / 2; i++) {
        for (f = 0; f < campo->colonne; f++) {
            struct Pedina* pedina = malloc(sizeof(struct Pedina));
            campo->celle[i*campo->colonne + f].pedina = pedina;
            pedina->altezza = 1;
            pedina->colore = rosso;
            pedina->tipo = soldier;
        }
    }
    
    for (i = campo->righe; i > campo->righe / 2; i--) {
        for (f = campo->colonne; f >= 0; f--) {
            struct Pedina* pedina = malloc(sizeof(struct Pedina));
            campo->celle[i*campo->colonne + f].pedina = pedina;
            pedina->altezza = 1;
            pedina->colore = giallo;
            pedina->tipo = soldier;
        }
    }
}

void stampaCampo(struct Campo* campo) {
    int i, f;
    for (i = 0; i < campo->righe; i++) {
        printf("%d   ", i + 1);
        for (f = 0; f < campo->colonne; f++) {
            stampaContenutoCella(&campo->celle[i*campo->colonne + f]);
        }
        printf("\n");
    }
    printf("\n    ");
    for (f = 0; f < campo->colonne; f++) {
        printf("%d ", f + 1);
    }
    printf("\n\n");
    
}

void stampaScacchiera() {
    int foo = 0;
    int i, f;
    int MAX_X = 36;
    int MAX_Y = 36;
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
                /* Se la colonna è un margine */
                if (f % 5 == 0) {
                    printf("|");
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
