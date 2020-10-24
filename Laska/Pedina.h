#ifndef Pedina_h
#define Pedina_h

#include <stdio.h>

struct Pedina {
    int colore;
    int altezza;
};

void setAltezza(struct Pedina *pedina, int altezza);
void aumentaAltezza(struct Pedina *pedina);
void diminuisciAltezza(struct Pedina *pedina);

#endif /* Pedina_h */
