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
#include "funcoes_modulo.h"
#include "utils.h"

char* gerar_linha_digitavel(char* codigo_barra, char* linha, bool formatado);
double extrair_valor_titulo(char* codigo_barra);

#endif /* BOLETO_TITULO_H_ */
