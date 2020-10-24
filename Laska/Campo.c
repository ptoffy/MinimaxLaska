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

void stampaCampo(struct Campo* campo) {
    int i, f;
    for (i = 0; i < campo->righe; i++) {
        for (f = 0; f < campo->colonne; f++) {
            stampaContenutoCella(&campo->celle[i*campo->colonne + f]);
        }
        printf("\n");
    }
    printf("\n");
}
