#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "maxMin.h"

int main(){
    tipoMaxMin mm;
    nuevoMm(&mm);
    printf("despues de nuevomm\n");
    if(esNulo(mm)){
        printf("mm inicializado a null\n");
        
        int t[9];
        for(int i = 0; i<9;i++){
            t[i] = 5;
        }
        
        iniciarMm(&mm, t);
        
        if(!esNulo(mm)){
            printf("se han introducido los datos correctamente\n");
            mostrarMm(mm);
            exit(0);
        } else
            exit(-1);
    } 
    printf("ª\n");
}
