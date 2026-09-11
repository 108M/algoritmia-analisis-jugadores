
#include <stdio.h>

#include "main.h"

int main(){
    //LEER PARA OBTENER LOS JUGADORES
    char nombre [50], leer_texto,caracter_anterior,clase [10],tecnica[100];
    int numeros,contador_num,caracteres_tecnica,aux,elem,opcion;
    
    int k, kTheBest = 10, kTheBestWilson = 4, numJgsWilson, numJgs;
    tipoCola c_wilson;

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
    
    //printf( "Introduzca el nombre del fichero a leer: \n");
    //scanf (" %s", nombre);
    f=fopen("IE1.csv","r");
    
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
	
    cn = normalizar(c,mm);

	do
    {
		printf("--------MENU-------- \n");
		printf("1 - Predecir la clase de un jugador introducido\n");
		printf("2 - Predecir la clase de un jugador introducido para una K indicada\n");
        printf("3 - Predecir la clase de un jugador introducido(Wilson)\n");
		printf("4 - Predecir la clase de un jugador introducido para una K indicada(Wilson)\n");
		printf("5 - Mostrar la K optima\n");
        printf("6 - Aplicar Algortimo Wilson y mostrar su K optima\n");
		printf("7 - Salir.\n");
		printf("Escoja una opcion: ");
		scanf(" %d",&opcion);
		switch(opcion){           
			case 1: 
				clasificarJugador(cn, kTheBest, mm);
				break;    
            case 2:
                printf("Introduzca la K deseada: \n");
                scanf("%d",&k);
				clasificarJugador(cn, k, mm);
				break;
            case 3:
                if(esNulaCola(c_wilson))
                    c_wilson = calculaColaWilson(kTheBest, cn, &numJgsWilson);
                clasificarJugador(c_wilson, kTheBestWilson, mm);
                break;
            case 4:
                if(esNulaCola(c_wilson))
                    c_wilson = calculaColaWilson(kTheBest, cn, &numJgsWilson);
                printf("Introduzca la K deseada: \n");
                scanf("%d",&k);
				clasificarJugador(c_wilson, k, mm);
                break;
			case 5:
                numJgs = 496;
                kTheBest = calculaKMejor(cn, numJgs); 
                printf("La mejor K es %d\n", kTheBest);
				break;
            case 6:
                if(esNulaCola(c_wilson))
                    c_wilson = calculaColaWilson(kTheBest, cn, &numJgsWilson);
                kTheBestWilson = calculaKMejor(c_wilson, numJgsWilson);
                printf("La mejor K es %d\n", kTheBestWilson);
                break;
		}
	}while(opcion<7);
}
