/*
 * utils.c
 *
 *  Created on: 4 de dez de 2017
 *      Author: marcos.sixel
 */

#include "utils.h"

const long _seconds_in_day = 86400;

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

struct tm* adicionar_dias_calendario(struct tm *calendario, int dias) {
	time_t time;
	time = mktime(calendario);
	time = adicionar_dias(time, dias);
	return localtime(&time);
}

time_t adicionar_dias(time_t time, int dias){
    return time + (dias * _seconds_in_day);
}
