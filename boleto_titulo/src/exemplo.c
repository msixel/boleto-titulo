/*
 * exemplo.c
 *
 *  Created on: 4 de dez de 2017
 *      Author: marcos.sixel
 */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "boleto_titulo.h"
#include "utils.h"

char* codigoBarras           = "34197736400001058981090000555270066201476000";
char* saidaEsperadaLimpa     = "34191090080055527006562014760003773640000105898";
char* saidaEsperadaFormatada = "34191.09008 00555.270065 62014.760003 7 73640000105898";

int main(void) {
	char saidaCalculadaLimpa[54];
	char saidaCalculadaFormatada[54];
	char buf_data_vencimento[11];

	gerar_linha_digitavel(codigoBarras, saidaCalculadaLimpa, true);
	gerar_linha_digitavel(codigoBarras, saidaCalculadaFormatada, false);

	fprintf(stdout, "saidaCalculadaLimpa=%s\n", saidaCalculadaLimpa);
	fprintf(stdout, "saidaCalculadaFormatada=%s\n", saidaCalculadaFormatada);

	if (strcmp(saidaEsperadaLimpa, saidaCalculadaLimpa) == 0 &&
			strcmp(saidaEsperadaFormatada, saidaCalculadaFormatada) == 0) {
		fprintf(stdout, "Passou\n");
	} else {
		fprintf(stdout, "Falha\n");
	}

	fprintf(stdout, "Valor %.2lf \n", extrair_valor_titulo(codigoBarras));
    fprintf(stdout, "data vencimento=%s \n", extrair_data_vencimento_DDBMMBYYYY(codigoBarras, buf_data_vencimento));
	return EXIT_SUCCESS;
}

