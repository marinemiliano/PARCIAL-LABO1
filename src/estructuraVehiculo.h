/*
 * estructura.h
 *
 *  Created on: 21 oct. 2022
 *      Author: marin
 */

#ifndef ESTRUCTURAVEHICULO_H_
#define ESTRUCTURAVEHICULO_H_

#include "entradas.h"
#define  CHAR_DESCRIPCION 30
#define  CHAR_COLOR 10
#define  LIBRE 0
#define  OCUPADO 1


typedef struct
{
	int idVehiculo;
	char descripcion[CHAR_DESCRIPCION];
	int  modelo; //(año de fabricaciónn
	char color [CHAR_COLOR];
	int tipoId;
	int isEmpty;

}eVehiculo;


int VEHICULO_inicilizarEstructura(eVehiculo listaVehiculos[],int tamVehiculos);
int VEHICULO_buscarIndiceLibre(eVehiculo listaVehiculos[],int tamVehiculos);


int VEHICULO_altaEstructura(eVehiculo listaVehiculos[],int tamVehiculos);
int VEHICULO_mostrarEstructuras(eVehiculo listaVehiculos[],int tamVehiculos);

void VEHICULO_mostrarUnaEstructura(eVehiculo unVehiculo);
int VEHICULO_mostrarEstructuras(eVehiculo listaVehiculos[],int tamVehiculos);

eVehiculo VEHICULO_pedirDatosUnViaje();


#endif /* ESTRUCTURAVEHICULO_H_ */
