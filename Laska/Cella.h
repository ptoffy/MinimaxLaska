#ifndef Cella_h
#define Cella_h

#include <stdio.h>
#include "Pedina.h"

enum Colore {
    rosso = 0,
    giallo = 1
};

struct Cella {
    int x, y;
    int colore;
    struct Pedina *pedina;
};

void stampaContenutoCella(struct Cella *cella);
void toNull(struct Cella *cella);
struct Pedina *pedina(struct Cella *cella);

#endif /* Cella_h */
