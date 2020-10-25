#include <stdio.h>
#include <stdlib.h>
#include "Cella.h"
#include "Pedina.h"
#include "Campo.h"

int main(int argc, const char * argv[]) {
    struct Campo *campo = creaCampo(7, 7);
    inizializzaCampo(campo);
    stampaCampo(campo);
}
