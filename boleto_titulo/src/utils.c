/*
 * utils.c
 *
 *  Created on: 4 de dez de 2017
 *      Author: marcos.sixel
 */

#include "utils.h"

char* remover_caracteres_alpha(char* linha) {
	char* ponteiroLeitura;
	char* ponteiroEscrita;
	ponteiroEscrita = linha;
	ponteiroLeitura = linha;
	while (*ponteiroLeitura != '\0') {
		if (isdigit(*ponteiroLeitura) ){
			strncpy(ponteiroEscrita, ponteiroLeitura, sizeof(char));
			ponteiroEscrita++;
		}
		ponteiroLeitura++;
	}
	*ponteiroEscrita = '\0';
	return linha;
}
