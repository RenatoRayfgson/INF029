#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "EstruturaVetores.h"
#define TAM 10

Auxiliar *vetor;

int criarEstruturaAuxiliar(int posicao, int tamanho){//Ao invés de usar a variável retorno, preferi fazer diretamente, pra evitar o uso de diversos else if, nesse caso, se dá uma falha na validação ele já para diretamente!
    if(!validarPosicao(posicao)){
        return POSICAO_INVALIDA;
    }
    posicao--;
    if(tamanho < 1){
        return TAMANHO_INVALIDO;
    }
    if(vetor[posicao].numero != NULL){
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    vetor[posicao].numero = (int*)malloc(sizeof(int)*tamanho);
    
    if(vetor[posicao].numero == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }    
    
    vetor[posicao].tamanho = tamanho;
    vetor[posicao].qtd = 0;    
    return SUCESSO; 
}

int inserirNumeroEmEstrutura(int posicao, int valor){    
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;   

    if(!validarPosicao(posicao)){
        return POSICAO_INVALIDA;
    }
    posicao--;

    if(vetor[posicao].numero == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if(vetor[posicao].qtd == vetor[posicao].tamanho){
        return SEM_ESPACO;
    }
    vetor[posicao].numero[vetor[posicao].qtd] = valor;
    vetor[posicao].qtd++;
    return SUCESSO;
}

int excluirNumeroDoFinaldaEstrutura(int posicao){
    if(!validarPosicao(posicao)){        
        return POSICAO_INVALIDA;
    }    
    posicao--;    
    if(vetor[posicao].numero == NULL){        
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if(vetor[posicao].qtd == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    vetor[posicao].numero[vetor[posicao].qtd - 1] = 0;    
    vetor[posicao].qtd--;
    return SUCESSO;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
    int busca = -1;
    if(!validarPosicao(posicao)){
        return POSICAO_INVALIDA;
    }    
    posicao--;    
    if(vetor[posicao].numero == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if(vetor[posicao].qtd == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    for(int i = 0; i<vetor[posicao].qtd; i++){
        if(valor == vetor[posicao].numero[i]){
            busca = i;
            break;
        }
    }
    if(busca == -1){
        return NUMERO_INEXISTENTE;
    }
    for(int j = busca; j < vetor[posicao].qtd; j++){
        vetor[posicao].numero[j] = vetor[posicao].numero[j+1];
    }
    vetor[posicao].qtd--;
    return SUCESSO;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int qtd = 0;
    if(!validarPosicao(posicao)){
        return POSICAO_INVALIDA;
    }
    posicao--;
    if(vetor[posicao].numero == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    for(int i = 0; i < vetor[posicao].qtd; i++){                  
        vetorAux[i] = vetor[posicao].numero[i];
        qtd++;        
    }
    if(qtd < 1){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    return SUCESSO;   
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int qtd = 0;
    if(!validarPosicao(posicao)){
        return POSICAO_INVALIDA;
    }
    posicao--;
    if(vetor[posicao].numero == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    for(int i = 0; i < vetor[posicao].qtd; i++){                  
        vetorAux[i] = vetor[posicao].numero[i];
        qtd++;        
    }
    if(qtd < 1){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    bubbleSort(vetorAux, qtd);
    return SUCESSO; 
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int sentinela = 0;
    int qtdEstruturasVazias = 0;
    for(int i = 0; i < 10; i++){
        if(vetor[i].qtd != 0){
            qtdEstruturasVazias++;            
        }
        int j;
        for(j = 0; j < vetor[i].qtd; j++){
            vetorAux[j+sentinela] = vetor[i].numero[j];
        }
        sentinela += j;
    }  
    if(qtdEstruturasVazias == 0){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    return SUCESSO;     
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int sentinela = 0;
    int qtdEstruturasVazias = 0;
    for(int i = 0; i < 10; i++){
        if(vetor[i].qtd != 0){
            qtdEstruturasVazias++;            
        }
        int j;
        for(j = 0; j < vetor[i].qtd; j++){
            vetorAux[j+sentinela] = vetor[i].numero[j];
        }
        sentinela += j;
    }  
    if(qtdEstruturasVazias == 0){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    bubbleSort(vetorAux, sentinela);
    return SUCESSO;     
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){    
    if(!validarPosicao(posicao)){
        return POSICAO_INVALIDA;
    }
    posicao--;    
    if(vetor[posicao].numero == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    int tamanhoFinal = novoTamanho + vetor[posicao].tamanho;
    if(tamanhoFinal < 1){
        return NOVO_TAMANHO_INVALIDO;
    }
    int *novoNumero = realloc(vetor[posicao].numero, sizeof(int) * tamanhoFinal);
    if(novoNumero == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }
    vetor[posicao].numero = novoNumero;
    vetor[posicao].tamanho = tamanhoFinal;
    if(vetor[posicao].qtd > vetor[posicao].tamanho){
        vetor[posicao].qtd = vetor[posicao].tamanho;
    }
    return SUCESSO;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    if(!validarPosicao){
        return POSICAO_INVALIDA;
    }
    posicao--;
    if(vetor[posicao].numero == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if(vetor[posicao].qtd == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    return vetor[posicao].qtd;
}

No *montarListaEncadeadaComCabecote(){
    No *comeco = (No*)malloc(sizeof(No));
    No *ficha = comeco;
    if(comeco == NULL){
        return NULL;
    }
    comeco -> conteudo = 0;
    comeco -> prox = NULL;
    for(int i = 0; i < 10; i++){
        if(vetor[i].numero != NULL){
            for(int j = 0; j < vetor[i].qtd; j++){
                No *encad = (No*)malloc(sizeof(No));
                encad->conteudo = vetor[i].numero[j];
                encad->prox = NULL;
                ficha->prox = encad;
                ficha = encad;

            }
        }
    }
    return comeco;
}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]){    
    int i = 0;
    No *ficha = inicio->prox;
    while(ficha != NULL){
        vetorAux[i] = ficha -> conteudo;
        ficha = ficha -> prox;
        i++;
    }
}

void destruirListaEncadeadaComCabecote(No **inicio){
    No *ficha = *inicio;
    No *seguinte = NULL;
    while(ficha != NULL){
        seguinte = ficha -> prox;
        free(ficha);
        ficha = seguinte;
    }
    *inicio = NULL;
}

int salvarArquivo(const char* arquivo){
    FILE *fp = fopen(arquivo, "w");
    if(fp == NULL){
        perror("fopen");
        return 0;
    }
    for(int i = 0; i < 10; i++){
        if(i>0){
            fprintf(fp, "\n");
        }
        fprintf(fp, "%d %d %d", i+1, vetor[i].qtd, vetor[i].tamanho);
        for(int j = 0; j < vetor[i].qtd; j++){
            fprintf(fp, " %d", vetor[i].numero[j]);
        }
    }
    fclose(fp);
    return 1;
}

int recuperarArquivo(){

}

void inicializar(){
    vetor = (Auxiliar*)malloc(sizeof(Auxiliar)*10);
    for(int i = 0; i < 10; i++){
        vetor[i].numero = NULL;
        vetor[i].qtd = 0;
        vetor[i].tamanho = 0;

    }
}

void finalizar(){
    for(int i = 0; i < 10; i++){
        if(vetor[i].numero == NULL){
            free(vetor[i].numero);
        }
    }
    free(vetor);
}


