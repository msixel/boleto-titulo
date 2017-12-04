/*
 * boleto_titulo.h
 *
 *  Created on: 4 de dez de 2017
 *      Author: marcos.sixel
 */

#ifndef BOLETO_TITULO_H_
#define BOLETO_TITULO_H_

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "funcoes_modulo.h"
#include "utils.h"

char* gerar_linha_digitavel(char*, char*, bool);
double extrair_valor_titulo(char*);

char* extrair_data_vencimento_DDBMMBYYYY(char*, char*);
struct tm* extrair_data_vencimento_calendario(char*, struct tm*);
time_t extrair_data_vencimento(char*);

#endif /* BOLETO_TITULO_H_ */
