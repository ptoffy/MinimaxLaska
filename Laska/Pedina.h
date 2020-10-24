#ifndef Pedina_h
#define Pedina_h

#include <stdio.h>

enum Tipo {
    soldier = 0,
    officer = 1,
    column = 2,
    commander = 3
};

struct Pedina {
    int colore;
    int altezza;
    int tipo;
};

void setAltezza(struct Pedina *pedina, int altezza);
void aumentaAltezza(struct Pedina *pedina);
void diminuisciAltezza(struct Pedina *pedina);

#endif /* Pedina_h */
