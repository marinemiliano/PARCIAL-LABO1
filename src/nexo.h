/*
 * nexo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: marin
 */

#ifndef NEXO_H_
#define NEXO_H_


#include  "estructuraTipoVehiculo.h"
#include "estructuraVehiculo.h"

eVehiculo NEXO_pedirDatosEmpleados(eVehiculo listaVehiculos[],int tamVehiculos,eTipoVehiculo listaTipos[],int ARRAY_TIPOS);
int NEXO_altaEstructura(eVehiculo listaVehiculos[],int tamVehiculos,eTipoVehiculo listaTipos[],int ARRAY_TIPOS);
void NEXO_mostrarUnaEstructura(eVehiculo listaViajes[],int tamViajes,eTipoVehiculo listaTipos[],int ARRAY_TIPOS);
int NEXO_mostrarEstructuras(eVehiculo listaViajes[],int tamViajes,eTipoVehiculo listaTipos[],int ARRAY_TIPOS);


int NEXO_darBaja(eVehiculo listaViajes[],int tamViajes,eTipoVehiculo listaTipos[],int ARRAY_TIPOS);
int NEXO_modificarEstructura(eVehiculo listaViajes[],int tamViajes,eTipoVehiculo listaTipos[],int ARRAY_TIPOS);





#endif /* NEXO_H_ */
