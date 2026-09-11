#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "colaEnteros.h"
#include "maxMin.h"
#include "normalizar.h"

int main() {
    
    //LEER PARA OBTENER LOS JUGADORES
    char nombre [50], leer_texto,caracter_anterior,clase [10],tecnica[100];
    int numeros,contador_num,caracteres_tecnica,aux,elem;
    
    jugador jugador1;
    tipoMaxMin mm;
    nuevoMm(&mm);
    float datos_jugador[9];
    float distancia = 0.0;
    FILE *f;
    
    caracteres_tecnica = 0 ;
    contador_num = -1;
    int j = 1;
    //cola para meter los datos
    tipoCola c;
    nuevaCola(&c);
    
    tipoCola cn; //cola normalizada 
    //nuevaCola(&cn);
    
    printf( "Introduzca el nombre del fichero a leer: \n");
    scanf (" %s", nombre);
    f=fopen(nombre,"r");
    
    printf("Leyendo jugadores...\n");
    
    while (!feof(f))
    {
		
        if (fscanf (f,"%d",&numeros) == 1 && leer_texto == ','){
            aux = numeros;
            contador_num = contador_num + 1;
            datos_jugador[contador_num] = aux ;
           //una vez leidos los 8 numeros y no haya caracter encolamos el jugador
            if ( contador_num == 8){
                if (j == 1) { //iniciamos max min con un contador de j
                    //iniciar maxmin con los primeros valores
                    iniciarMm(&mm, datos_jugador);
                    
                    j = 2; //como ya hemos inciado maxmin cambiamos el contador
                    contador_num = -1; // reseteamos las posiciones de la tabla
               }else{
                    //comparamoos los valores para los maxmin
                    compararMmYt(&mm, datos_jugador);
                    contador_num = -1;
               }
               
               
               leer_texto = fgetc(f); //leer la coma despues del ultimo numero
               leer_texto = fgetc(f); // leer el espacio despues de la coma
               
			   while ( leer_texto != ','){ // las tecnicas estan separadas por comas
				   tecnica[caracteres_tecnica] = leer_texto;
				   leer_texto = fgetc(f);
				   caracteres_tecnica = caracteres_tecnica + 1;
                } // cuando leeemos la ultima tecnica encolamos al jugador con los datos y la tecnica
                
                tecnica[caracteres_tecnica] = '\0'; //indicamos que la cadena termina
			   caracteres_tecnica = 0; // reseteamos contador de caracteres_tecnica para la siguiente
               encolar(&c,datos_jugador,clase, tecnica);
               
               contador_num = -1;
            }
            
        }else{ // leemos la clase del jugador del dataset
            caracter_anterior = leer_texto;
            leer_texto=fgetc(f);
            
            if (caracter_anterior == 'G' && leer_texto == 'K') {
                //printf("leo GK");
                strcpy(clase, "GK\0");
            }
            else if(caracter_anterior == 'D' && leer_texto == 'F') {
                //printf("leo DF");
                strcpy(clase, "DF\0");
            }
            else if (caracter_anterior == 'M' && leer_texto == 'F') {
                //printf("leo MF");
                strcpy(clase, "MF\0");
            }
            else if(caracter_anterior == 'F' && leer_texto == 'W') {
                //printf("leo FW");
                strcpy(clase, "FW\0");
				}
			}
        }
        
    
    //normalizamos la cola
    cn = normalizar(c,mm);
    
    
    //PARA K=1
	tipoCola aux_cola; // se crea cola_aux para no modificar la cola original 
	aux_cola = cn;
    
    //variables para el acuraccy
	int cont = 0, cantidad = 0;
    float porcentaje; 
    
    while (!esNulaCola(aux_cola)){
        jugador jg_aux = frente(aux_cola); // jugador_Aux sirve para poder leer los jugadores de la cola auxiliar
        avanzaSigCola(&aux_cola);
        cont = cont + precision(cn,jg_aux); //precision devolvera 1 si hemos acertado la clase y 0 sino
        cantidad = cantidad + 1;  //contamos cuantos jugadores hay en el dataset
    }
    //porcentaje de acierto para k=1
    porcentaje = ((float) cont/ cantidad) * 100;
    printf("El porcentaje de acierto es %f para K=1\n\n", porcentaje);
    
    
    //ESTUDIAR PARA QUE K ES MEJOR
    //estudiamos para que k funciona mejor nuestro algoritmo
    int kTheBest;
    float mejorPorcentaje = 0.0;
    int numJgs = cantidad;
    
    //"reseteamos" aux_cola
    aux_cola = cn;
    
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
    
    
    //APLICAMOS WILSON UNA VEZ SABEMOS QUE K FUNCIONA MEJOR
    //para k mejor opcion
	int k = 10;
    
    //nueva cola obtenida al aplicar wilson
	tipoCola c_wilson;
	nuevaCola(&c_wilson);
    
    //reseteamos 
    aux_cola = cn;
    
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
    
    /*
    //METEMOS NUESTRO JUGADOR EN LA ULTIMA POSICION DE LA COLA
    jugador1 = crearJugador();
    
    tipoCola cola1;
    nuevaCola(&cola1);

    encolarJugador(&cola1,jugador1); // nuestro jugador creado sera el ultimo de todos
    
    cola1 = normalizar(cola1,mm);
    vecino vecinosk[k];
    int contador_clase[4];
    jugador1 = frente(cola1);
    kdistanciamijugador(cn,jugador1,k,vecinosk);
    
    
    
    for (int a = 0; a < 4; a++){
        contador_clase[a] = 0;
        }	
    for (int z = 0; z < k; z++){
        
        if (vecinosk[z].clase[0] == 'G' && vecinosk[z].clase[1] == 'K'){
            contador_clase[0] = contador_clase [0] + 1;
        }
        else if (vecinosk[z].clase[0] == 'D' && vecinosk[z].clase[1] == 'F'){
            contador_clase[1] = contador_clase[1] + 1;
        }
        else if (vecinosk[z].clase[0] == 'M' && vecinosk[z].clase[1] == 'F'){
            contador_clase [2] = contador_clase [2] + 1;
        }
        else if (vecinosk[z].clase[0] == 'F' && vecinosk[z].clase[1] == 'W'){
            contador_clase[3]= contador_clase[3] + 1;
        }
    
    }
    
    
    if (contador_clase[0] > contador_clase[1] && contador_clase[0] > contador_clase[2] && contador_clase[0] > contador_clase[3]){
            printf("La clase predicha es GK\n");
        }
    if (contador_clase[1] > contador_clase[0] && contador_clase[1] > contador_clase[2] && contador_clase[1] > contador_clase[3]){
            printf("La clase predicha es DF \n");
        }	
    if (contador_clase[2] > contador_clase[1] && contador_clase[2] > contador_clase[0] && contador_clase[2] > contador_clase[3]){
            printf("La clase predicha es MF\n");
        }	
    if (contador_clase[3] > contador_clase[1] && contador_clase[3] > contador_clase[2] && contador_clase[3] > contador_clase[0]){
            printf("La clase predicha es FW\n");
        }
			*/	
	
    return 0;
}
