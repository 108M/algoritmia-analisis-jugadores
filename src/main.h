#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "colaEnteros.h"
#include "maxMin.h"
#include <string.h>
#include "normalizar.h"

int calculaKMejor(tipoCola cn, int numJgs);

tipoCola calculaColaWilson(int kTheBest, tipoCola cn, int *cont);

void clasificarJugador(tipoCola cn, int k, tipoMaxMin mm);