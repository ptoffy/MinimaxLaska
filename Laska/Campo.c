#include <stdlib.h>
#include "Campo.h"
#include "Cella.h"

/**
 Il campo da gioco, contiene le dimensioni e una matrice di celle.
 */
struct Campo {
    int righe, colonne;
    struct Cella* celle;
};

/**
 Crea il campo assegnando memoria e celle.
 @param righe Il numero di righe che deve avere il campo.
 @param colonne Il numero di colonne che deve avere il campo.
 @return Un campo pronto con celle a null.
 */
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

/**
 Crea una pedina assegnando memoria e attributi.
 @param cella La cella dove inizializzare una pedina.
 @param colore Il colore del quale dev'essere la pedina inizializzata.
 */
void inizializzaPedina(struct Cella* cella, int colore) {
    struct Pedina* pedina = malloc(sizeof(struct Pedina));
    cella->pedina = pedina;
    pedina->altezza = 1;
    pedina->colore = colore;
    pedina->tipo = soldier;
}

/**
 Inizializza il campo e assegna pedine nella posizione iniziale.
 @param campo Il campo da inizializzare.
 */
void inizializzaCampo(struct Campo* campo) {
    int i, f;
    /* Inizializza la parte del giocatore rosso */
    for (i = 0; i < campo->righe / 2; i++) {
        for (f = 0; f < campo->colonne; f++) {
            if (i % 2 == 0) {
                if (f % 2 == 0) {
                    inizializzaPedina(&campo->celle[i*campo->colonne + f], rosso);
                }
            } else {
                if (f % 2 != 0) {
                    inizializzaPedina(&campo->celle[i*campo->colonne + f], rosso);
                }
            }
        }
    }
    /* Inizializza la parte del giocatore giallo */
    for (i = campo->righe; i > campo->righe / 2; i--) {
        for (f = campo->colonne; f >= 0; f--) {
            if (i % 2 == 0) {
                if (f % 2 == 0) {
                    inizializzaPedina(&campo->celle[i*campo->colonne + f], giallo);
                }
            } else {
                if (f % 2 != 0) {
                    inizializzaPedina(&campo->celle[i*campo->colonne + f], giallo);
                }
            }
        }
    }
}

/**
 Stampa a schermo il campo con le varie pedine.
 @param campo Il campo da stampare.
 */
void stampaCampo(struct Campo* campo) {
    int i, f;
    for (i = 0; i < campo->righe; i++) {
        printf("%d   ", i + 1);
        for (f = 0; f < campo->colonne; f++) {
            if (i % 2 == 0) {
                if (f % 2 == 0) {
                    stampaContenutoCella(&campo->celle[i*campo->colonne + f]);
                    printf("  ");
                }
            } else if (f % 2 != 0) {
                printf("  ");
                stampaContenutoCella(&campo->celle[i*campo->colonne + f]);
            }
        }
        printf("\n");
    }
    printf("\n    ");
    for (f = 0; f < campo->colonne; f++) {
        printf("%d ", f + 1);
    }
    printf("\n\n");
    
}

/**
 Stampa la scacchiera.
 */
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
