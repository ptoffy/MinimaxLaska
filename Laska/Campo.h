#ifndef Campo_h
#define Campo_h

#include <stdio.h>
#include "Cella.h"

struct Campo;

struct Campo* creaCampo(int righe, int colonne);
void stampaCampo(struct Campo* campo);
void stampaScacchiera(void);
void inizializzaCampo(struct Campo* campo);
void inizializzaPedina(struct Cella* cella, int colore);

#endif /* Campo_h */
