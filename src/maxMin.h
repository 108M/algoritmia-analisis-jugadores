//maxmin
#include <stdbool.h>

typedef float tipoElementoCola;

typedef struct MaxMin{
    tipoElementoCola FP[2];
	tipoElementoCola TP[2];
    tipoElementoCola Patada[2];
	tipoElementoCola Cuerpo[2];
	tipoElementoCola Control[2];
	tipoElementoCola Guardia[2];
	tipoElementoCola Velocidad[2];
	tipoElementoCola Estamina[2];
	tipoElementoCola Valor[2];
}MaxMin;

typedef MaxMin *tipoMaxMin;

void nuevoMm(tipoMaxMin* );
bool esNulo(tipoMaxMin);
void iniciarMm(tipoMaxMin *, tipoElementoCola t[9]);
void compararMmYt(tipoMaxMin *, tipoElementoCola t[9]);
void mostrarMm(tipoMaxMin );
tipoElementoCola devuelveMinimo(int , tipoMaxMin);
tipoElementoCola devuelveMaximo(int , tipoMaxMin);

//cambiar maxmin
