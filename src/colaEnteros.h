#include <stdbool.h>
#include "jugador.h"

 
typedef struct celdaC{
 	jugador jg; 
 	struct celdaC *sig;
 } celdaCola; 
 
typedef struct tipoC{
	celdaCola* ini;
	celdaCola* fin;
}tipoCola;

void nuevaCola(tipoCola *);

void encolar(tipoCola *, float jugador [8], char cl [2], char* super);

void encolarJugador(tipoCola *, jugador );

void desencolar(tipoCola *);

jugador frente(tipoCola);

jugador ultimo(tipoCola);

bool esNulaCola(tipoCola);

void avanzaSigCola(tipoCola *c);
