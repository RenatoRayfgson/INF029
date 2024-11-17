#include <stdio.h>
#include <string.h>
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
int tamanhoNumero(int numero){  
  char numeroString[127];
  sprintf(numeroString, "%d", numero);
  return strlen(numeroString);
}
void removerAcentos(const char *texto, char *fraseSemAcento) {
    int i = 0, j = 0;
    while (texto[i] != '\0') {
        // Verifica os bytes iniciais de caracteres em UTF-8
        if ((unsigned char)texto[i] == 0xC3) { // Caractere acentuado
            switch ((unsigned char)texto[i + 1]) {
                case 0xA0: case 0xA1: case 0xA2: case 0xA3: case 0xA4: // á à â ã ä
                    fraseSemAcento[j++] = 'a';
                    break;
                case 0xA8: case 0xA9: case 0xAA: case 0xAB: // é è ê ë
                    fraseSemAcento[j++] = 'e';
                    break;
                case 0xAC: case 0xAD: case 0xAE: case 0xAF: // í ì î ï
                    fraseSemAcento[j++] = 'i';
                    break;
                case 0xB2: case 0xB3: case 0xB4: case 0xB5: case 0xB6: // ó ò ô õ ö
                    fraseSemAcento[j++] = 'o';
                    break;
                case 0xB9: case 0xBA: case 0xBB: case 0xBC: // ú ù û ü
                    fraseSemAcento[j++] = 'u';
                    break;
                case 0xA7: // ç
                    fraseSemAcento[j++] = 'c';
                    break;
                case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: // Á À Â Ã Ä
                    fraseSemAcento[j++] = 'A';
                    break;
                case 0x88: case 0x89: case 0x8A: case 0x8B: // É È Ê Ë
                    fraseSemAcento[j++] = 'E';
                    break;
                case 0x8C: case 0x8D: case 0x8E: case 0x8F: // Í Ì Î Ï
                    fraseSemAcento[j++] = 'I';
                    break;
                case 0x92: case 0x93: case 0x94: case 0x95: case 0x96: // Ó Ò Ô Õ Ö
                    fraseSemAcento[j++] = 'O';
                    break;
                case 0x99: case 0x9A: case 0x9B: case 0x9C: // Ú Ù Û Ü
                    fraseSemAcento[j++] = 'U';
                    break;
                case 0x87: // Ç
                    fraseSemAcento[j++] = 'C';
                    break;
                default:
                    fraseSemAcento[j++] = texto[i + 1]; // Caractere não mapeado
                    break;
            }
            i += 2; // Pula os dois bytes do caractere UTF-8
        } else {
            fraseSemAcento[j++] = texto[i++]; // Copia diretamente outros caracteres
        }
    }
    fraseSemAcento[j] = '\0'; // Finaliza a string
}
void tudoMinusculo(char *fraseSemAcento){
  int i = 0;
  while(fraseSemAcento[i] != '\0'){
    if(fraseSemAcento[i]>='A' && fraseSemAcento[i]<='Z'){
      fraseSemAcento[i]=fraseSemAcento[i]+32;
    }
    i++;
  }
}
//aa