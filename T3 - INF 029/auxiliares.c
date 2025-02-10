#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "EstruturaVetores.h"
#define TAM 10

void bubbleSort(int vetorAux[], int k){
    int j;    
    for(int i = 0; i < k; i++){
        for(j = 0; j < k-1; j++){
            if(vetorAux[j] > vetorAux[j+1]){
               int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j+1];
                vetorAux[j+1] = temp;
            }
        }
    }
}

bool validarPosicao(int posicao){
    return posicao < 10 && posicao >=1;
}