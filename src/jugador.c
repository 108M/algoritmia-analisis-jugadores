#include "jugador.h"
#include <string.h>
#include <stdlib.h>

jugador crearJugador (){
	jugador jg;
	printf("Introduzca los datos del jugador que piensa crear: \n");
	printf("Introduzca los puntos fisicos (FP): \n");
	scanf("%f", &jg.FP);
	printf("Introduzca los puntos de tecnica (TP): \n");
	scanf("%f", &jg.TP);
	printf("Introduzca los puntos de Patada : \n");
	scanf("%f", &jg.patada);
	printf("Introduzca los puntos de cuerpo : \n");
	scanf("%f", &jg.cuerpo);
	printf("Introduzca los puntos de control: \n");
	scanf("%f", &jg.control);
	printf("Introduzca los puntos de guardia : \n");
	scanf("%f", &jg.guardia);
	printf("Introduzca los puntos de velocidad : \n");
	scanf("%f", &jg.velocidad);
	printf("Introduzca los puntos de estamina: \n");
	scanf("%f", &jg.estamina);
	printf("Introduzca los puntos de valor: \n");
	scanf("%f", &jg.valor);
	printf("Introduzca su primera supertecnica: \n");
	scanf(" %s", jg.supertecnica);
	printf("JUGADOR CREADO CON EXITO \n");
	return jg;
	
}




tipoElementoJG getFP(jugador jg){
    return jg.FP;
}
void setFP(jugador *jg, tipoElementoJG FP){
    jg->FP = FP;
}


tipoElementoJG getTP(jugador jg){
    return jg.TP;
}
void setTP(jugador *jg, tipoElementoJG TP){
    jg->TP = TP;
}


tipoElementoJG getPatada(jugador jg){
    return jg.patada;
}
void setPatada(jugador *jg, tipoElementoJG patada){
    jg->patada = patada;
}


tipoElementoJG getCuerpo(jugador jg){
    return jg.cuerpo;
}
void setCuerpo(jugador *jg, tipoElementoJG cuerpo){
    jg->cuerpo = cuerpo;
}


tipoElementoJG getControl(jugador jg){
    return jg.control;
}
void setControl(jugador *jg, tipoElementoJG control){
    jg->control = control;
}


tipoElementoJG getGuardia(jugador jg){
    return jg.guardia;
}
void setGuardia(jugador *jg, tipoElementoJG guardia){
    jg->guardia = guardia;
}


tipoElementoJG getVelocidad(jugador jg){
    return jg.velocidad;
}
void setVelocidad(jugador *jg, tipoElementoJG velocidad){
    jg->velocidad = velocidad; 
}


tipoElementoJG getEstamina(jugador jg){
    return jg.estamina;
}
void setEstamina(jugador *jg, tipoElementoJG estamina){
    jg->estamina = estamina;
}


tipoElementoJG getValor(jugador jg){
    return jg.valor;
}
void setValor(jugador *jg, tipoElementoJG valor){
    jg->valor = valor;
}

char *getClase(jugador jg){
    char *dev;
    dev = (char*)malloc((strlen(jg.clase)+1)*sizeof(char));
    strcpy(dev, jg.clase);
    return dev;
}
void setClase(jugador *jg, char *clase){
    strcpy(jg->clase, clase);
}

char *getSupertecnica(jugador jg){
    char *dev;
    dev = (char*)malloc((strlen(jg.supertecnica)+1)*sizeof(char));
    strcpy(dev, jg.supertecnica);
    return dev;
}
void setSupertecnica(jugador *jg, char *supertecnica){
    strcpy(jg->supertecnica, supertecnica);
}
