#ifndef Cella_h
#define Cella_h

#include <stdio.h>
#include "Pedina.h"

/**
 La cella singola del campo da gioco.
 */
typedef struct Cella {
    int x, y; /**< Le coordinate x e y della cella rispetto al campo. */
    Pedina *pedina; /**< Puntatore alla pedina attuale che c'è sulla cella. */
} Cella;

/**
 Stampa il contenuto di una cella.
 @param cella Il puntatore alla cella il cui contenuto è da stampare.
 */
void stampaContenutoCella(Cella *cella);

/**
 Imposta il puntatore pedina della cella a null.
 @param cella La cella il cui puntatore pedina viene impostato a null.
 */
void setPedinaToNull(Cella *cella);

/**
 Ritorna la pedina della cella indicata.
 @param cella La cella indicata.
 @return La pedina della cella.
 */
Pedina* ottieniPedina(Cella *cella);

#endif /* Cella_h */
