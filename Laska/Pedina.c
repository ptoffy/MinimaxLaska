#include "Pedina.h"

void setAltezza(Pedina *pedina, int altezza) {
    pedina->altezza = altezza;
}

void aumentaAltezza(Pedina *pedina) {
    pedina->altezza += 1;
}

void diminuisciAltezza(Pedina *pedina) {
    pedina->altezza -= 1;
}
