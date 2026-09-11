#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "maxMin.h"

void nuevoMm(tipoMaxMin *mm){
    *mm = NULL;
}

bool esNulo(tipoMaxMin mm){
    return mm == NULL;
}

//inicia la cola con los elementos del primer jugador
void iniciarMm(tipoMaxMin *mm, tipoElementoCola t[9]) {
    //reservar para tener un maxMIin
    *mm = (MaxMin*)malloc(sizeof(MaxMin));
    
    //rellenar maxmin
    (*mm)->FP[0] = t[0];
    (*mm)->FP[1] = t[0];
    
    (*mm)->TP[0] = t[1];
    (*mm)->TP[1] = t[1];
    
    (*mm)->Patada[0] = t[2];
    (*mm)->Patada[1] = t[2];
    
    (*mm)->Cuerpo[0] = t[3];
    (*mm)->Cuerpo[1] = t[3];
    
    (*mm)->Control[0] = t[4];
    (*mm)->Control[1] = t[4];
    
    (*mm)->Guardia[0] = t[5];
    (*mm)->Guardia[1] = t[5];
    
    (*mm)->Velocidad[0] = t[6];
    (*mm)->Velocidad[1] = t[6];

    (*mm)->Estamina[0] = t[7];
    (*mm)->Estamina[1] = t[7];

    (*mm)->Valor[0] = t[8];
    (*mm)->Valor[1] = t[8];
}

//compara maxmin con los elementos del sigueinte jugador guardados en t
void compararMmYt(tipoMaxMin *mm, tipoElementoCola t[9]) {
	
	
	if (t[0] >= (*mm)->FP[1]) {
		(*mm)->FP[1] = t[0];
	}
	if (t[0] < (*mm)->FP[0]) {
		(*mm)->FP[0] = t[0];
	}
	
	if (t[1] >= (*mm)->TP[1]) {
		(*mm)->TP[1] = t[1];
	}
	if (t[1] < (*mm)->TP[0]) {
		(*mm)->TP[0] = t[1];
	}
	
	if (t[2] >= (*mm)->Patada[1]) {
		(*mm)->Patada[1] = t[2];
	}
	if (t[2] < (*mm)->Patada[0]) {
		(*mm)->Patada[0] = t[2];
	}
	
	if (t[3] >= (*mm)->Cuerpo[1]) {
		(*mm)->Cuerpo[1] = t[3];
	}
	if (t[3] < (*mm)->Cuerpo[0]) {
		(*mm)->Cuerpo[0] = t[3];
	}
	
	if (t[4] >= (*mm)->Control[1]) {
		(*mm)->Control[1] = t[4];
	}
	if (t[4] < (*mm)->Control[0]) {
		(*mm)->Control[0] = t[4];
	}
	
	if (t[5] >= (*mm)->Guardia[1]) {
		(*mm)->Guardia[1] = t[5];
	}
	if (t[5] < (*mm)->Guardia[0]) {
		(*mm)->Guardia[0] = t[5];
	}
	
	if (t[6] >= (*mm)->Velocidad[1]) {
		(*mm)->Velocidad[1] = t[6];
	}
	if (t[6] < (*mm)->Velocidad[0]) {
		(*mm)->Velocidad[0] = t[6];
	}
	
	if (t[7] >= (*mm)->Estamina[1]) {
		(*mm)->Estamina[1] = t[7];
	}
	if (t[7] < (*mm)->Estamina[0]) {
		(*mm)->Estamina[0] = t[7];
	}
	
	if (t[8] >= (*mm)->Valor[1]) {
		(*mm)->Valor[1] = t[8];
	}
	if (t[8] < (*mm)->Valor[0]) {
		(*mm)->Valor[0] = t[8];
	}
}

//muestra por pantalla los valores de maxmin
void mostrarMm(tipoMaxMin mm){
    printf("El maximo FP es %f y el minimo FP es %f\n", mm->FP[1], mm->FP[0]);
    printf("El maximo TP es %f y el minimo FP es %f\n", mm->TP[1], mm->TP[0]);
    printf("El maximo Valor es %f y el minimo Valor es %f\n", mm->Valor[1], mm->Valor[0]);
}

//devuelve el valor minimo de la habilidad i
tipoElementoCola devuelveMinimo(int i, tipoMaxMin mm){
    if(i==0){
        return mm->FP[0];
    }
    else if(i==1){
        return mm->TP[0];
    }
    else if(i==2){
        return mm->Patada[0];
    }
    else if(i==3){
        return mm->Cuerpo[0];
    }
    else if(i==4){
        return mm->Control[0];
    }
    else if(i==5){
        return mm->Guardia[0];
    }
    else if(i==6){
        return mm->Velocidad[0];
    }
    else if(i==7){
        return mm->Estamina[0];
    }
    else
        return mm->Valor[0];
}

//devuelve el valor máximo de la habilidad i
tipoElementoCola devuelveMaximo(int i, tipoMaxMin mm){
    if(i==0){
        return mm->FP[1];
    }
    else if(i==1){
        return mm->TP[1];
    }
    else if(i==2){
        return mm->Patada[1];
    }
    else if(i==3){
        return mm->Cuerpo[1];
    }
    else if(i==4){
        return mm->Control[1];
    }
    else if(i==5){
        return mm->Guardia[1];
    }
    else if(i==6){
        return mm->Velocidad[1];
    }
    else if(i==7){
        return mm->Estamina[1];
    }
    else
        return mm->Valor[1];
}
