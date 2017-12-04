/*
 ============================================================================
 Name        : boleto_titulo.c
 Author      : Marcos Sixel
 Version     :
 ============================================================================
 */

#include "boleto_titulo.h"


char* gerar_linha_digitavel(char* codigo_barra, char* linha, bool formatado) {
	char ponto = '.';
	char espaco = ' ';
	char charZero = '\0';

	char *ponteiro;
	int digito_verificador_global;
	char base_calculo_digito[44];
	char digito_calculado;

	if (strlen((const char*)codigo_barra) != 44) {
		return NULL;
	}

	//primeiro bloco
	ponteiro = linha;
	strncpy(ponteiro, &codigo_barra[0], sizeof(char) * 4);
	strncpy(ponteiro+=4, &codigo_barra[19], sizeof(char));
	strncpy(++ponteiro, &ponto, sizeof(char));
	strncpy(++ponteiro, &codigo_barra[20], sizeof(char) * 4);

	//calculo digito primeiro bloco
	strncpy(base_calculo_digito, &codigo_barra[0], sizeof(char) * 4);
	strncpy(&base_calculo_digito[4], &codigo_barra[19], sizeof(char));
	strncpy(&base_calculo_digito[5], &codigo_barra[20], sizeof(char) * 4);
	base_calculo_digito[9] = '\0';
	digito_calculado = (char) modulo10(base_calculo_digito) + 48;

	strncpy(ponteiro+=4, &digito_calculado, sizeof(char));
	strncpy(++ponteiro, &espaco, sizeof(char));

	//segundo bloco
	strncpy(++ponteiro, &codigo_barra[24], sizeof(char) * 5);
	strncpy(ponteiro+=5, &ponto, sizeof(char));
	strncpy(++ponteiro, &codigo_barra[29], sizeof(char) * 5);

	//calculo digito segundo bloco
	strncpy(base_calculo_digito, &codigo_barra[24], sizeof(char) * 5);
	strncpy(&base_calculo_digito[5], &codigo_barra[29], sizeof(char) * 5);
	base_calculo_digito[10] = '\0';
	digito_calculado = (char) modulo10(base_calculo_digito) + 48;

	strncpy(ponteiro+=5, &digito_calculado, sizeof(char));
	strncpy(++ponteiro, &espaco, sizeof(char));

	//terceiro bloco
	strncpy(++ponteiro, &codigo_barra[34], sizeof(char) * 5);
	strncpy(ponteiro+=5, &ponto, sizeof(char));
	strncpy(++ponteiro, &codigo_barra[39], sizeof(char) * 5);

	//calculo digito segundo bloco
	strncpy(base_calculo_digito, &codigo_barra[34], sizeof(char) * 5);
	strncpy(&base_calculo_digito[5], &codigo_barra[39], sizeof(char) * 5);
	base_calculo_digito[10] = '\0';
	digito_calculado = (char) modulo10(base_calculo_digito) + 48;

	strncpy(ponteiro+=5, &digito_calculado, sizeof(char));
	strncpy(++ponteiro, &espaco, sizeof(char));

	//parse do digito verificador geral
	strncpy(++ponteiro, &codigo_barra[4], sizeof(char)); // Digito verificador
	digito_verificador_global = atoi((const char*)ponteiro);
	strncpy(++ponteiro, &espaco, sizeof(char));

	//calculo data/fator de vencimento
	strncpy(++ponteiro, &codigo_barra[5], sizeof(char) * 4); // Fator(data) de vencimento

	//calculo valor do titulo
	strncpy(ponteiro+=4, &codigo_barra[9], sizeof(char) * 10); //valor do titulo

	//encerrando string
	strncpy(ponteiro+=10, &charZero, sizeof(char));

	//validando digito verificador global
	//calculo digito segundo bloco
	strncpy(base_calculo_digito, &codigo_barra[0], sizeof(char) * 4);
	strncpy(&base_calculo_digito[4], &codigo_barra[5], sizeof(char) * 39);
	base_calculo_digito[43] = '\0';
	digito_calculado = (char) modulo11(base_calculo_digito) + 48;

	if ((digito_calculado - 48) != digito_verificador_global) {
		return NULL;
	}

	if (formatado == true) {
		linha = remover_caracteres_alpha(linha);
	}
	return linha;
}

double extrair_valor_titulo(char* codigo_barra) {
	char valor[11];
	double retorno;
	strncpy(valor, &codigo_barra[9], sizeof(char) * 10);
	valor[10] = '\0';
	retorno = atoi(valor)/100.0;
	return retorno;
}

