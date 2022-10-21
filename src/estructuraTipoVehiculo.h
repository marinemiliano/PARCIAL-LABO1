/*
 * estructuraTipoVehiculo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: marin
 */

#ifndef ESTRUCTURATIPOVEHICULO_H_
#define ESTRUCTURATIPOVEHICULO_H_
#include "entradas.h"
#define  CHAR_DESCRIPCION 30
#define  LIBRE 0
#define  OCUPADO 1


typedef struct
{
	int idTipo;
	char descripcion[CHAR_DESCRIPCION];
	int isEmpty;

}eTipoVehiculo;



#endif /* ESTRUCTURATIPOVEHICULO_H_ */
