#include <stdio.h>
#include <stdlib.h>
#include "RenatoRayfgsonBittencourt20241160004.h"
//Verifica se o bendito ano é bissexto ou não
int anoBissexto(int ano){
  return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}
//Apenas alterna a quantidade de dias dependendo do mês
int quantidadeDeDias(int mes, int ano){
  switch(mes){
    case 4: case 6: case 9: case 11: return 30;
    case 2: return anoBissexto(ano) ? 29 : 28;
    default: return 31;
  }
}