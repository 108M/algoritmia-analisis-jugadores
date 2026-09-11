#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "colaEnteros.h"

void nuevaCola(tipoCola *c){
	
	c->ini = NULL;
	c->fin = NULL;
}

void errorCola(char s[]){
	printf("\n\n\nERROR en el modulo Colas: %s \n", s);
}

void encolar(tipoCola *c, float t [8], char cl [2], char* super){
	celdaCola *n;
	n = (celdaCola*)malloc(sizeof(celdaCola));
    
    //metemos datos del jugador
    setFP(&n->jg, t[0]); 
    setTP(&n->jg, t[1]);
    setPatada(&n->jg, t[2]);
    setCuerpo(&n->jg, t[3]);
    setControl(&n->jg, t[4]);
    setGuardia(&n->jg, t[5]),
    setVelocidad(&n->jg, t[6]);
    setEstamina(&n->jg, t[7]);
    setValor(&n->jg, t[8]);
    setClase(&n->jg, cl);
    setSupertecnica(&n->jg, super);

    // siguiente nulo
    n->sig = NULL;
    
	if(esNulaCola(*c)){
	
		c->ini = n;
	}
	else{
		c->fin->sig = n;
	}
	c->fin = n;
}

void encolarJugador(tipoCola *c, jugador jg){
    celdaCola *n;
	n = (celdaCola*)malloc(sizeof(celdaCola));
    n->jg = jg;
    n->sig = NULL;
    
    if(esNulaCola(*c)){
	
		c->ini = n;
		
	}
	else{
		c->fin->sig = n;
		
	}
	c->fin = n;
	
}

void desencolar(tipoCola *c){
	celdaCola *aux;
	
	if(esNulaCola(*c)){
		errorCola("No se puede desencolar en una cola vacia");
	}
	else{
		aux = c->ini;	
		c->ini = c->ini->sig;
		if(esNulaCola(*c)){
			c->fin = NULL;
		}
	}
	free(aux);
}

jugador frente (tipoCola c){
	if(esNulaCola(c)){
		errorCola("No hay primero en una cola vacia");
	}
	else{
		return (c.ini)->jg ;
	}
}

jugador ultimo (tipoCola c){
	if(esNulaCola(c)){
		errorCola("No hay primero en una cola vacia");
	}
	else{
		return (c.fin)->jg;
	}
}

bool esNulaCola(tipoCola c){
	return (c.ini == NULL);
}

void avanzaSigCola(tipoCola *c){
    if(!esNulaCola(*c))
        c->ini = c->ini->sig;
    else
        errorCola("La cola está vacia");
}



