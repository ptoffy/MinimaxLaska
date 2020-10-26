#include <stdio.h>
#include <stdlib.h>
#include "headers/Cella.h"
#include "headers/Pedina.h"
#include "headers/Campo.h"

void spostamentoPedina(Campo *campo);
int controllaInput(int x, int y);

int main(int argc, const char * argv[]) {
    Campo *campo = creaCampo(7, 7);
    inizializzaCampo(campo);
    stampaCampo(campo);
}

void spostamentoPedina(Campo *campo) {
    int x, y;
    scanf("", &x);
    scanf("", &y);
    /*
     * Quando va tutto a buon fine, muovi la pedina
     * Pedina *pedina = ottieniPedina(ottieniCella(campo, x, y));
     */
}

int controllaInput(int x, int y) {
    /* Gli input sono validi?
     * Se giusto, return 0;
     * Se sbagliato, return 1;
     */
}
