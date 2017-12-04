/*
 * utils.h
 *
 *  Created on: 4 de dez de 2017
 *      Author: marcos.sixel
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <ctype.h>
#include <string.h>
#include <time.h>

char* remover_caracteres_alpha(char*);
time_t adicionar_dias(time_t, int);
struct tm* adicionar_dias_calendario(struct tm*, int);

#endif /* UTILS_H_ */
