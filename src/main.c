
#include "main.h"


//ESTUDIAR PARA QUE K ES MEJOR
//estudiamos para que k funciona mejor nuestro algoritmo
int calculaKMejor(tipoCola cn, int numJgs){
    int kTheBest;
    float mejorPorcentaje = 0.0;
    int cont, cantidad;
    float porcentaje;
    
    //"reseteamos" aux_cola
    tipoCola aux_cola = cn;
    
    for(int k=1;k<numJgs+1;k++){
        cont = 0;
        cantidad = 0;
        
        while (!esNulaCola(aux_cola)){
            jugador jg_aux = frente(aux_cola);
            avanzaSigCola(&aux_cola);
            cont = cont + precisionk(cn, k, jg_aux); //precision devolvera 1 si hemos acertado la clase y 0 sino
            cantidad = cantidad + 1;  //contamos cuantos jugadores hay en el dataset
        }
        
        porcentaje = ((float) cont/ cantidad) * 100;
        printf("El porcentaje de acierto para k=%d es %f \n",k, porcentaje); 
        
        if(porcentaje > mejorPorcentaje){
            mejorPorcentaje = porcentaje;
            kTheBest = k;
        }
        
        //reseteamos aux_cola
        aux_cola = cn;
	}
	printf("\nEl mejor porcentaje %f se obtiene para k=%d\n", mejorPorcentaje, kTheBest);
    return kTheBest;
}

//APLICAMOS WILSON UNA VEZ SABEMOS QUE K FUNCIONA MEJOR
tipoCola calculaColaWilson(int kTheBest, tipoCola cn, int *cont){
    //para k mejor opcion
	int k = kTheBest;
    
    //nueva cola obtenida al aplicar wilson
	tipoCola c_wilson;
	nuevaCola(&c_wilson);
    
    //reseteamos 
    tipoCola aux_cola = cn;
    
	while (!esNulaCola(aux_cola)){
        jugador jg_aux = frente(aux_cola);
        avanzaSigCola(&aux_cola);
        algoritmo_wilson(&c_wilson, precisionk(cn, k, jg_aux), jg_aux);
    }
    
    //calculo cuantos jugadores hay 
    int numJgsWilson = 0;
    aux_cola = c_wilson;
    while(!esNulaCola(aux_cola)){
        numJgsWilson++;
        avanzaSigCola(&aux_cola);
    }
    
    printf("El número de jugadores en la cola una vez aplicado wilson es: %d\n", numJgsWilson);
    *cont = numJgsWilson;
    
    return c_wilson;
}

//CALSIFICAMOS EL JUGADOR PASADO 
void clasificarJugador(tipoCola cn, int k, tipoMaxMin mm){
    jugador jugador1 = crearJugador();
    tipoCola cola1;
    nuevaCola(&cola1);
    encolarJugador(&cola1,jugador1); // nuestro jugador creado sera el ultimo de todos
    cola1 = normalizar(cola1,mm);
    
    vecino vecinosk[k];
    jugador1 = frente(cola1);
    kdistanciamijugador(cn,jugador1,k,vecinosk);
    
    char *clases[4] = {"GK\0", "DF\0", "MF\0", "FW\0"};
    int contador_clase[4];
    memset(contador_clase, 0, sizeof(contador_clase));
    
    //contamos de que clase es cada vecino
    for(int i=0;i<k;i++){
        if(strcmp(vecinosk[i].clase, clases[0]) == 0)
            contador_clase[0]++;
        else if(strcmp(vecinosk[i].clase, clases[1]) == 0)
            contador_clase[1]++;
        else if(strcmp(vecinosk[i].clase, clases[2]) == 0)
            contador_clase[2]++;
        else
            contador_clase[3]++;
    }
    
    //calculamos la calse mayoritaria
    int posMayoritaria = 0;
    for(int i=1;i<4;i++){
        if(contador_clase[i] > contador_clase[posMayoritaria])
            posMayoritaria = i;
    }
    
    printf("La clase predicha es: %s\n", clases[posMayoritaria]);
}
