/*
 ============================================================================
 Name        : funcoes_modulo.c
 Author      : Marcos Sixel
 Version     :
 ============================================================================
 */

#include "funcoes_modulo.h"

int modulo10(char* numero) {
    int soma  = 0;
    int peso  = 2;
    int contador = strlen(numero) - 1;
    while (contador >= 0) {
        int multiplicacao;

        multiplicacao = ((int)numero[contador] - 48) * peso;
        if (multiplicacao >= 10) {multiplicacao = 1 + (multiplicacao-10);}
        soma = soma + multiplicacao;
        if (peso == 2) {
            peso = 1;
        } else {
            peso = 2;
        }
        contador = contador - 1;
    }
    int digito = 10 - (soma % 10);
    if (digito == 10) digito = 0;

    return digito;
}

int modulo11(char* numero) {
    int soma  = 0;
    int peso  = 2;
    int base  = 9;
    int contador = strlen( (const char *)numero) - 1;
    int i;
    for (i=contador; i >= 0; i--) {
        soma += ( ((int)numero[i] - 48) * peso);
        if (peso < base) {
            peso++;
        } else {
            peso = 2;
        }
    }
    int digito = 11 - (soma % 11);
    if (digito >  9) digito = 0;
    /* Utilizar o dígito 1(um) sempre que o resultado do cálculo padrão for igual a 0(zero), 1(um) ou 10(dez). */
    if (digito == 0) digito = 1;
    return digito;
}
