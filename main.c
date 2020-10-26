#include <stdio.h>
#include <stdlib.h>
#include "headers/Cella.h"
#include "headers/Pedina.h"
#include "headers/Campo.h"

int main(int argc, const char * argv[]) {
    struct Campo *campo = creaCampo(7, 7);
    inizializzaCampo(campo);
    stampaCampo(campo);
}
