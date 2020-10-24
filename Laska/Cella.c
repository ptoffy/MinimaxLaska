#include "Cella.h"
#include "Pedina.h"

void stampaContenutoCella(struct Cella *cella) {
    if (cella->pedina != NULL) {
        printf("%d, (%d)", cella->pedina->altezza, cella->pedina->colore);
    } else {
        printf("0 ");
    }
}

void toNull(struct Cella* cella) {
    cella->pedina = NULL;
}

struct Pedina *pedina(struct Cella *cella) {
    return cella->pedina;
}
