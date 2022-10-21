/*
 * entradas.h
 *
 *  Created on: 21 oct. 2022
 *      Author: marin
 */

#ifndef ENTRADAS_H_
#define ENTRADAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int esNumerica(char* cadena, int limite);
int myGets(char* cadena, int longitud);
int utn_getNumero(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int* pResultado);
int getInt(int* pResultado);
int getString(char* pResultado, int longitud);
int esString(char* cadena, int longitud);
int utn_getString(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado);

#endif /* ENTRADAS_H_ */
