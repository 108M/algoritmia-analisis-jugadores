#include<ctype.h>
#include <stdlib.h>
#include <stdio.h>

#include "maxMin.h"

int main(){
    char nombre[50], basura;
    int a, aux;

    int t[9];
    
    //maxmin
    tipoMaxMin mm;
    nuevoMm(&mm);
    
    int j = 1;
    int i = -1;
    
    printf( "Introduzca el nombre del fichero a leer: \n");
    scanf (" %s", nombre);
    
    //abrir fichero
    FILE *f;
    f=fopen(nombre,"r");
    
    while (!feof(f))
    {
        if (fscanf (f,"%d",&a) == 1 && basura == ','){
            aux = a;
            i = i + 1;
            
            t[i] = aux;
           //printf("%d ",t[i]);
            if ( i == 8){
                if (j == 1) {
                    //iniciar maxmin con los primeros valores
                    iniciarMm(&mm, t);
                    
                    j = 2;
                    i = -1;
                }
                else {
					printf("asdf");
                    compararMmYt(&mm, t);
                    i = -1;
                }
            }
            
        }else{
            basura=fgetc(f);   
        }
        
        //printf("\n");
        fclose;
        
    }
    //muestra los maximos y minimos
    mostrarMm(mm);
    
    return 0;
}
