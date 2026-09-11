#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"

int main(){
    jugador jg = crearJugador();
    
    //gets
    printf("Jugador FP es %f\n", getFP(jg));
    printf("Jugador clase es %s\n", getClase(jg));
    printf("Jugador sueprtecnica es %s\n", getSupertecnica(jg));
    exit(0);
}
