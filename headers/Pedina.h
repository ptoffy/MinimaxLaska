#ifndef Pedina_h
#define Pedina_h

#include <stdio.h>

/**
 Il tipo che può essere una pedina di gioco.
 */
enum Tipo {
    soldier = 0, /**< Si muove solo in avanti, quando raggiunge l'ultima riga del campo, diventa officer. */
    officer = 1, /**< Si può muovere in tutte le direzioni, è segnata. */
    column = 2, /**< Una stack di una o più soldier o officer, può contenere diversi colori e viene controllato dal commander. */
    commander = 3 /**< Pedina superiore di una column, se è officer la column si può muovere in ogni direzione. */
};

/**
 Il colore che può avere una pedina.
 */
enum Colore {
    rosso = 0, /**< Colore rosso per la pedina del giocatore 1. */
    giallo = 1 /**< Colore rosso per la pedina del giocatore 2. */
};

/**
 La pedina di gioco.
 */
typedef struct Pedina {
    int colore;  /**< Il colore della pedina, indica il possessore di essa. */
    int altezza; /**< L'altezza della pedina, in caso di column o commander. */
    int tipo;    /**< Il tipo di pedina, indicato dall'enum Tipo. */
} Pedina;

void setAltezza(Pedina *pedina, int altezza);
void aumentaAltezza(Pedina *pedina);
void diminuisciAltezza(Pedina *pedina);

#endif /* Pedina_h */
