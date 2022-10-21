/*
 * estructura.c
 *
 *  Created on: 21 oct. 2022
 *      Author: marin
 */


#include "estructuraVehiculo.h"
#define REINTENTOS 3
#define CHAR_DESCRIPCION 30
#define  CHAR_COLOR 10



int VEHICULO_inicilizarEstructura(eVehiculo listaVehiculos[],int tamVehiculos)
{
	int retorno;
	int i;
	retorno=-1;

	if(listaVehiculos != NULL && tamVehiculos > 0)
	{
		for(i=0;i<tamVehiculos;i++)
		{
			listaVehiculos[i].isEmpty=LIBRE;
		}
		retorno=0;
	}
	return retorno;
}


int VEHICULO_altaEstructura(eVehiculo listaVehiculos[],int tamVehiculos)													//la lista de sectores
{
	int retorno;
	retorno=-1;
	int posicionLibre;
	eVehiculo unVehiculo;

	if(listaVehiculos!=NULL && tamVehiculos > 0)
	{
		posicionLibre = VEHICULO_buscarIndiceLibre(listaVehiculos, tamVehiculos);

		unVehiculo=VEHICULO_pedirDatosUnViaje();
		if(posicionLibre != -1)
		{
			listaVehiculos[posicionLibre] = unVehiculo;
			retorno=0;
		}
	}
	return retorno;
}

int VEHICULO_buscarIndiceLibre(eVehiculo listaVehiculos[],int tamVehiculos)
{
	int retorno;
	retorno=-1;
	int i;
	if(listaVehiculos != NULL && tamVehiculos > 0)
	{
		for(i=0;i<tamVehiculos;i++)
		{
			if(listaVehiculos[i].isEmpty==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}


eVehiculo VEHICULO_pedirDatosUnViaje()
{

	eVehiculo aux;
	utn_getNumero("ingrese id de viaje de 1 a 1000","error numero fuera de rango, reingrese id de viaje", 1, 1000, REINTENTOS,&aux.idVehiculo);

	utn_getString("ingrese descripcion del vehiculon", "error, reingrese destino\n", REINTENTOS ,CHAR_DESCRIPCION,aux.descripcion);

	utn_getNumero("ingrese año de fabricacion",
				   "error numero fuera de rango reingrese cantidad de pasajeros", 1880, 2022, REINTENTOS,&aux.modelo);

	utn_getString("ingrese destino del viaje\n", "error, reingrese destino\n", REINTENTOS ,CHAR_DESCRIPCION,aux.descripcion);

	utn_getString("ingrese destino del viaje\n", "error, reingrese destino\n", REINTENTOS,CHAR_COLOR,aux.color);

	aux.isEmpty=OCUPADO;
	return aux;
}

void VEHICULO_mostrarUnaEstructura(eVehiculo unVehiculo)
{
	printf("%d - %s - %d\n",unVehiculo.idVehiculo,unVehiculo.descripcion,unVehiculo.modelo);
}



int VEHICULO_mostrarEstructuras(eVehiculo listaVehiculos[],int tamVehiculos)
{
	int retorno;
	retorno=-1;
	int i;
	if(listaVehiculos != NULL && tamVehiculos > 0)
	{
		for(i=0;i<tamVehiculos;i++)
		{
			if(listaVehiculos[i].isEmpty==OCUPADO)
			{
				VIAJE_mostrarUnaEstructura(listaVehiculos[i]);
			}
			retorno=1;
		}
	}
	return retorno;
}


