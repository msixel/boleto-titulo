/*
 * exemplo.c
 *
 *  Created on: 4 de dez de 2017
 *      Author: marcos.sixel
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "boleto_titulo.h"

int main(void) {
	char* codigoBarras           = "34197736400001058981090000555270066201476000";
	char* saidaEsperadaLimpa     = "34191090080055527006562014760003773640000105898";
	char* saidaEsperadaFormatada = "34191.09008 00555.270065 62014.760003 7 73640000105898";
	char saidaCalculadaLimpa[54];
	char saidaCalculadaFormatada[54];

	gerar_linha_digitavel(codigoBarras, saidaCalculadaLimpa, true);
	gerar_linha_digitavel(codigoBarras, saidaCalculadaFormatada, false);

	printf("saidaCalculadaLimpa=%s\n", saidaCalculadaLimpa);
	printf("saidaCalculadaFormatada=%s\n", saidaCalculadaFormatada);

	if (strcmp(saidaEsperadaLimpa, saidaCalculadaLimpa) == 0 &&
			strcmp(saidaEsperadaFormatada, saidaCalculadaFormatada) == 0) {
		puts("Passou=true");
	} else {
		puts("Passou=false");
	}

	printf("Valor %.2lf \n", extrair_valor_titulo(codigoBarras));
	return EXIT_SUCCESS;
}

