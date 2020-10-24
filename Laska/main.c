#include <stdio.h>
#include <stdlib.h>
#include "Cella.h"
#include "Pedina.h"
#include "Campo.h"

const int VUOTO = 0;
const int PLAYER1 = 1;
const int PLAYER2 = 2;

int main(int argc, const char * argv[]) {
    struct Campo *campo = creaCampo(6, 6);
    stampaCampo(campo);
}
