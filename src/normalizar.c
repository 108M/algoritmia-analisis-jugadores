#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "colaEnteros.h"
#include "maxMin.h"
#include <string.h>
#include "normalizar.h"


tipoCola normalizar (tipoCola c,tipoMaxMin mm ){
	tipoCola cn;
    nuevaCola(&cn);
    
    while(!esNulaCola(c)){
        //jugador
        jugador jg;
        jg = frente(c);
        desencolar(&c);
        
        //normalizar jugador
        setFP(&jg, (getFP(jg) - devuelveMinimo(0, mm))/(devuelveMaximo(0, mm)- devuelveMinimo(0, mm)));
        setTP(&jg, (getTP(jg) - devuelveMinimo(1, mm))/(devuelveMaximo(1, mm)- devuelveMinimo(1, mm)));
        setPatada(&jg, (getPatada(jg) - devuelveMinimo(2, mm))/(devuelveMaximo(2, mm)- devuelveMinimo(2, mm)));
        setCuerpo(&jg, (getCuerpo(jg) - devuelveMinimo(3, mm))/(devuelveMaximo(3, mm)- devuelveMinimo(3, mm)));
        setControl(&jg, (getControl(jg) - devuelveMinimo(4, mm))/(devuelveMaximo(4, mm)- devuelveMinimo(4, mm)));
        setGuardia(&jg, (getGuardia(jg) - devuelveMinimo(5, mm))/(devuelveMaximo(5, mm)- devuelveMinimo(5, mm)));
        setVelocidad(&jg, (getVelocidad(jg) - devuelveMinimo(6, mm))/(devuelveMaximo(6, mm)- devuelveMinimo(6, mm)));
        setEstamina(&jg, (getEstamina(jg) - devuelveMinimo(7, mm))/(devuelveMaximo(7, mm)- devuelveMinimo(7, mm)));
        setValor(&jg, (getValor(jg) - devuelveMinimo(8, mm))/(devuelveMaximo(8, mm)- devuelveMinimo(8, mm)));
        
        
        //encolo normalizado
        encolarJugador(&cn, jg);
    }
   return cn;
	
}

int precision (tipoCola cn, jugador jg){
	
	int verdadero = 0;
	float sum = 0.0;
	float distancia = 0.0;
	float minimo = 1000.0;
	float distancia_atributo[10];
    
	//tipoCola cn;
	//cn = aux_cola;
	
    while(!esNulaCola(cn)){
        jugador jgfrente = frente(cn);
        
        //para valores numericos
        distancia_atributo[0] = getFP(jgfrente) - getFP(jg);
        distancia_atributo[1] = getTP(jgfrente) - getTP(jg);
        distancia_atributo[2] = getPatada(jgfrente) - getPatada(jg);
        distancia_atributo[3] = getCuerpo(jgfrente) - getCuerpo(jg);
        distancia_atributo[4] = getControl(jgfrente) - getControl(jg);
        distancia_atributo[5] = getGuardia(jgfrente) - getGuardia(jg);
        distancia_atributo[6] = getVelocidad(jgfrente) - getVelocidad(jg);
        distancia_atributo[7] = getEstamina(jgfrente) - getEstamina(jg);
        distancia_atributo[8] = getValor(jgfrente) - getValor(jg);
        
        //para valores categóricos
        if (strcmp(getSupertecnica(jgfrente),getSupertecnica(jg)) == 0){
            distancia_atributo[9] = 0;
        }else{
            distancia_atributo[9] = 1;
        }
        
        //suma de distancias
        for (int i = 0; i <10; i++){
            sum = sum + pow(distancia_atributo[i],2.0);
        }

        distancia = sqrt(sum);
        sum = 0.0;
        
        //si la distancia es 0, quiere decir que se compara consigomismo, lo descartamos
        if (distancia != 0){
            if (minimo >= distancia){
                minimo = distancia;
                if (strcmp(getClase(jg), getClase(jgfrente)) == 0){
                    verdadero = 1;
                }else{
                    verdadero = 0;
                }
            }
        }
        
        avanzaSigCola(&cn);
    }
    
	return verdadero;
}

int precisionk(tipoCola cn, int k, jugador jg){
	
	int verdadero = 0;
	float sum = 0.0;
	float distancia = 0.0;
	float minimo = 1000.0;
	float distancia_atributo[10];
    
    //tabla para las k distancias
    vecino kvecinos[k];
    int posMayorDis = 0;
    bool tablallena = false;
    
    //inicializo tabla
    for(int i=0;i<k;i++){
        kvecinos[i].distancia = 1000;
    }
	
    while(!esNulaCola(cn)){
        jugador jgfrente = frente(cn);
        
        //para valores numericos
        distancia_atributo[0] = getFP(jgfrente) - getFP(jg);
        distancia_atributo[1] = getTP(jgfrente) - getTP(jg);
        distancia_atributo[2] = getPatada(jgfrente) - getPatada(jg);
        distancia_atributo[3] = getCuerpo(jgfrente) - getCuerpo(jg);
        distancia_atributo[4] = getControl(jgfrente) - getControl(jg);
        distancia_atributo[5] = getGuardia(jgfrente) - getGuardia(jg);
        distancia_atributo[6] = getVelocidad(jgfrente) - getVelocidad(jg);
        distancia_atributo[7] = getEstamina(jgfrente) - getEstamina(jg);
        distancia_atributo[8] = getValor(jgfrente) - getValor(jg);
        
        //para valores categóricos
        if (strcmp(getSupertecnica(jgfrente),getSupertecnica(jg)) == 0){
            distancia_atributo[9] = 0;
        }else{
            distancia_atributo[9] = 1;
        }
        
        //suma de distancias
        for (int i = 0; i <10; i++){
            sum = sum + pow(distancia_atributo[i],2.0);
        }

        distancia = sqrt(sum);
        sum = 0.0;
        
        //si la distancia es 0, quiere decir que se compara consigomismo, lo descartamos
        if (distancia != 0){
            //si la distancia es menor que la distancia mayor de los kvecinos, la camabiamos
            if (kvecinos[posMayorDis].distancia > distancia){
                //metemos en la tabla el valor y la cale
                kvecinos[posMayorDis].distancia = distancia;
                strcpy(kvecinos[posMayorDis].clase, getClase(jgfrente));
                
                if(tablallena){
                    //calcular la posicion de la distancia mayor
                    posMayorDis = 0;
                    if(k > 1){
                        for(int i = 1; i<k; i++){
                            if(kvecinos[i].distancia > kvecinos[posMayorDis].distancia)
                                posMayorDis = i;
                        }
                    }
                    
                    /*for(int i=0;i<k;i++){
                        printf("kvecinos[%d].distancia = %f\n", i, kvecinos[i].distancia);
                        printf("kvecinos[%d].clase = %s\n", i, kvecinos[i].clase);
                    }
                    printf("El de mayor distancia es:\n");
                    printf("kvecinos[%d].distancia = %f\n", posMayorDis, kvecinos[posMayorDis].distancia);
                    printf("kvecinos[%d].clase = %s\n", posMayorDis, kvecinos[posMayorDis].clase);*/

                } else{
                    posMayorDis++;
                    if(posMayorDis == k){
                        tablallena = true;
                        
                        //calcular la posicion de la distancia mayor
                        posMayorDis = 0;
                        if(k > 1){
                            for(int i = 1; i<k; i++){
                                if(kvecinos[i].distancia > kvecinos[posMayorDis].distancia)
                                    posMayorDis = i;
                            }
                        }
                    }
                }
            }
        }
        
        avanzaSigCola(&cn);
    }
    
    //clases
    int contClases[4];
    char *clases[4] = {"GK\0", "DF\0", "MF\0", "FW\0"};
    
    memset(contClases, 0, sizeof(clases)); //clases a cero
    
    //contamos de que clase es cada vecino
    for(int i=0;i<k;i++){
        //printf("kvecinos[%d].distancia = %f\n", i, kvecinos[i].distancia);
        //printf("kvecinos[%d].clase = %s\n", i, kvecinos[i].clase);
        if(strcmp(kvecinos[i].clase, clases[0]) == 0)
            contClases[0]++;
        else if(strcmp(kvecinos[i].clase, clases[1]) == 0)
            contClases[1]++;
        else if(strcmp(kvecinos[i].clase, clases[2]) == 0)
            contClases[2]++;
        else
            contClases[3]++;
    }
    
    //calculamos la calse mayoritaria
    int posMayoritaria = 0;
    //printf("contClases[%d] = %d\n", posMayoritaria, contClases[posMayoritaria]);
    for(int i=1;i<4;i++){
        //printf("contClases[%d] = %d\n", i, contClases[i]);
        if(contClases[i] > contClases[posMayoritaria])
            posMayoritaria = i;
    }
    
    //printf("La clase predicha es: %s\n", clases[posMayoritaria]);
    
    //si la clase mayoritaria coincide con la del jugador, se devuelve 1
    if(strcmp(clases[posMayoritaria], getClase(jg)) == 0){
        //printf("\ncontClases[%d] = %d\n\n", posMayoritaria, contClases[posMayoritaria]);
        verdadero = 1;
    } else{
        verdadero = 0;
    }
    
	return verdadero;
}

void algoritmo_wilson(tipoCola *c_wilson,int verdadero,jugador jg){
    if (verdadero == 1){
        encolarJugador(&(*c_wilson),jg);
    }
}
	
void kdistanciamijugador (tipoCola cn, jugador jg, int k, vecino *vec){
	
	int pos = 0; //pos va a guardar la posicion del mayor numero en los vecinos
	
	int rellenar = 0; // esto va a servir para rellenar K veces los vecinos
	float sum = 0.0;
	float distancia = 0.0;
	float minimo = 1000.0;
	float distancia_atributo [9];
	float max = 0.0; // va a ser la distancia mas grande de los k vecinos
	
	
	
	while(!esNulaCola(cn)){
		jugador jgfrente = frente(cn);
    
        
        distancia_atributo[0] = getFP(jgfrente) - getFP(jg);
        distancia_atributo[1] = getTP(jgfrente) - getTP(jg);
        distancia_atributo[2] = getPatada(jgfrente) - getPatada(jg);
        distancia_atributo[3] = getCuerpo(jgfrente) - getCuerpo(jg);
        distancia_atributo[4] = getControl(jgfrente) - getControl(jg);
        distancia_atributo[5] = getGuardia(jgfrente) - getGuardia(jg);
        distancia_atributo[6] = getVelocidad(jgfrente) - getVelocidad(jg);
        distancia_atributo[7] = getEstamina(jgfrente) - getEstamina(jg);
        distancia_atributo[8] = getValor(jgfrente) - getValor(jg);
		
		 if (strcmp(getSupertecnica(jgfrente),getSupertecnica(jg)) == 0){
			 distancia_atributo[9] = 0;
			 }else{
				  distancia_atributo[9] = 1;
				 }		 
		 for (int i = 0; i !=10; i++){
			 sum = sum + pow(distancia_atributo[i],2.0);
			 }
			 
		 distancia = sqrt(sum);
		
		 
		 sum = 0.0;
		 
		  if (rellenar < k){ // aqui vamos a rellenar los k primeros, estos no hace falta comparar cual es mas grande y asi porque es inutil y asi rellenamos hasta tener vecinos al completo
				 vec[rellenar].distancia = distancia;
				 
				 vec[rellenar].clase[0] = cn.ini->jg.clase[0];
				 vec[rellenar].clase[1] = cn.ini->jg.clase[1];
				
			 }
			 rellenar = rellenar + 1;
			 
		 if (distancia != 0 && rellenar > k ){ // cuando la ya este rellenado vecinos con los primeros K ejemplos entonces empezamos a comparar
			 
			 for (int w = 0; w < k; w++){ // aqui vamos a recorrer todos los vecinos mientras los comparamos con ellos mismos para encontar la posicion donde vamos a sustituir si hay una distancia menor
				 
				 if (max < vec[w].distancia ){
					 
					 max = vec[w].distancia;
					 
					 pos = w;
					 
					 
				 }
			 }
			 
			 
			for (int p = 0; p < k; p++){ // aqui vamos a recorrer todos los vecinos mientras los comparamos con ellos mismos para encontar la posicion donde vamos a sustituir si hay una distancia menor
					 
					 
				 }
			 if ( max > distancia){ // si la distancia calculada es menor que la DISTANCIA MAXIMA de los vecinos, la sustituimos
				 
				 vec[pos].distancia = distancia;
				 max = vec[pos].distancia = distancia;
				 
				 vec[pos].clase[0] = cn.ini->jg.clase[0];
				 vec[pos].clase[1] = cn.ini->jg.clase[1];
				 
				 }
			 	
		}
		avanzaSigCola(&cn);	
    }
}
