#include <math.h>


typedef struct Vecino{
    float distancia;
    char clase[10];
     
}vecino;

tipoCola normalizar (tipoCola c, tipoMaxMin mm);

int precision (tipoCola cn, jugador jg);
int precisionk(tipoCola ,int , jugador );
void algoritmo_wilson(tipoCola *c_wilson,int verdadero,jugador jg);
void kdistanciamijugador (tipoCola cn,jugador jg, int k, vecino *vec);



