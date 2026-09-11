#include <stdio.h>

typedef float tipoElementoJG;

 typedef struct Jugador{
    tipoElementoJG FP;
    tipoElementoJG TP;
    tipoElementoJG patada;
    tipoElementoJG cuerpo;
    tipoElementoJG control;
    tipoElementoJG guardia;
    tipoElementoJG velocidad;
    tipoElementoJG estamina;
    tipoElementoJG valor;
    char clase [10];
    char supertecnica [100]; 
}jugador;

jugador crearJugador();

tipoElementoJG getFP(jugador );
void setFP(jugador* , tipoElementoJG );

tipoElementoJG getTP(jugador );
void setTP(jugador* , tipoElementoJG );

tipoElementoJG getPatada(jugador );
void setPatada(jugador* , tipoElementoJG );

tipoElementoJG getCuerpo(jugador );
void setCuerpo(jugador* , tipoElementoJG );

tipoElementoJG getControl(jugador );
void setControl(jugador* , tipoElementoJG );

tipoElementoJG getGuardia(jugador );
void setGuardia(jugador* , tipoElementoJG );

tipoElementoJG getVelocidad(jugador );
void setVelocidad(jugador* , tipoElementoJG);

tipoElementoJG getEstamina(jugador );
void setEstamina(jugador* , tipoElementoJG);

tipoElementoJG getValor(jugador );
void setValor(jugador* , tipoElementoJG );

char *getClase(jugador );
void setClase(jugador* , char* );

char *getSupertecnica(jugador );
void setSupertecnica(jugador* , char* );
