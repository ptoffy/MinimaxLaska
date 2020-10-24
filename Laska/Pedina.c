#include "Pedina.h"

void setAltezza(struct Pedina *pedina, int altezza) {
    pedina->altezza = altezza;
}

void aumentaAltezza(struct Pedina *pedina) {
    pedina->altezza += 1;
}

void diminuisciAltezza(struct Pedina *pedina) {
    pedina->altezza -= 1;
}

void azzera() {
    
}
