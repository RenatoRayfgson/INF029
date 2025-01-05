#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "EstruturaVetores.h"
#define TAM 10

/*void bubbleSort(*numero, int k){
    Auxiliar temp;
    for(int i=0; i<k; i++){
        for(int j=0; j<k-1; j++){
            if(ponto[j].distancia>ponto[j+1].distancia){
                temp = ponto[j];
                ponto[j] = ponto[j+1];
                ponto[j+1]=temp;
            }
        }
    }
}*/

bool validarPosicao(int posicao){
    return posicao < 10 && posicao >=1;
}