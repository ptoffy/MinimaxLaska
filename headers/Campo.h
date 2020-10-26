#ifndef Campo_h
#define Campo_h

#include <stdio.h>
#include "Cella.h"

/**
 Il campo da gioco, contiene le dimensioni e una matrice di celle.
 */
typedef struct Campo {
    int righe, colonne; /**< Il numero di righe e coloonne del campo. */
    Cella* celle; /**< Matrice di celle. */
} Campo;

/**
 Crea il campo.
 @param righe Il numero di righe che deve avere il campo.
 @param colonne Il numero di colonne che deve avere il campo.
 @return Un campo pronto con celle a null.
 */
Campo* creaCampo(int righe, int colonne);

/**
 Stampa a schermo il campo con le varie pedine.
 @param campo Il campo da stampare.
 */
void stampaCampo(Campo* campo);

/**
 Stampa la scacchiera.
 */
void stampaScacchiera(void);

/**
 Ritorna la cella di un campo che ha le coordinate indicate.
 @param campo Il campo in cui cercare la cella.
 @param x La coordinata x della cella.
 @param y La coordinata y della cella.
 @return La cella se esiste, NULL se no.
 */
Cella* ottieniCella(Campo *campo, int x, int y);

/**
 Inizializza il campo e assegna pedine nella posizione iniziale.
 @param campo Il campo da inizializzare.
 */
void inizializzaCampo(Campo* campo);

/**
 Crea una pedina assegnando memoria e attributi.
 @param cella La cella dove inizializzare una pedina.
 @param colore Il colore del quale dev'essere la pedina inizializzata.
 */
void inizializzaPedina(Cella* cella, int colore);

#endif /* Campo_h */
