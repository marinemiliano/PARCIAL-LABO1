/*
 * nexo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: marin
 */


#include "nexo.h"
#include "entradas.h"
#define REINTENTOS 3
#define CHAR_DESCRIPCION 30
#define  CHAR_COLOR 10




int NEXO_altaEstructura(eVehiculo listaVehiculos[],int tamVehiculos,eTipoVehiculo listaTipos[],int ARRAY_TIPOS)
{
	int retorno;
	retorno=-1;
	int posicionLibre;
	eVehiculo unVehiculo;

	if(listaVehiculos!=NULL && tamVehiculos > 0)
	{
		posicionLibre = VEHICULO_buscarIndiceLibre(listaVehiculos, tamVehiculos);

		unVehiculo=NEXO_pedirDatosEmpleados(listaVehiculos,tamVehiculos, listaTipos,ARRAY_TIPOS);
		if(posicionLibre != -1)
		{
			unVehiculo[posicionLibre] = unVehiculo;
			retorno=0;
	}
	return retorno;
}

eVehiculo NEXO_pedirDatosEmpleados(eVehiculo listaViajes[],int tamViajes,eTipoVehiculo listaTipos[],int ARRAY_TIPOS)
{
	eVehiculo aux;
		utn_getNumero("ingrese id de viaje de 1 a 1000","error numero fuera de rango, reingrese id de viaje", 1, 1000, REINTENTOS,&aux.idVehiculo);

	utn_getString("ingrese descripcion del vehiculon", "error, reingrese destino\n", REINTENTOS ,CHAR_DESCRIPCION ,aux.descripcion);

		utn_getNumero("ingrese año de fabricacion",
					   "error numero fuera de rango reingrese cantidad de pasajeros\n", 1880, 2022, REINTENTOS,&aux.modelo);

		utn_getString("ingrese destino del viaje\n", "error, reingrese destino\n", REINTENTOS ,CHAR_DESCRIPCION,aux.descripcion);

		utn_getString("ingrese destino del viaje\n", "error, reingrese destino\n", REINTENTOS,CHAR_COLOR,aux.color);

		aux.isEmpty=OCUPADO;
	return aux;
}

/*int NEXO_darBaja(eVehiculo listaViajes[],int tamViajes,eTipoVehiculo listaTipos[],int ARRAY_TIPOS)
{
	int id;
	int posicion;
	int retorno;
	retorno=-1;    //SI EL RETORNO ES -1 ES PORQUE ALGO DE TODO ESTO FALLO

	NEXO_mostrarEstructuras(listaEmpleados, tamEmpleados, listaSectores, tamSectores);

	id= ing_pedirEnteroRango("ingrese id a dar de baja", -1000, 100000);

	posicion= EMP_buscarPosicionPorID(listaEmpleados, tamEmpleados, id);

	if(listaEmpleados != NULL && tamEmpleados > 0 && posicion != -1)
	{
		listaEmpleados[posicion].isEmpty=LIBRE;

		retorno=0;	//SI EL RETORNO ES 0 ES QUE SALIO TODO BIEN
	}
	else
	{
		retorno=-2; //SI EL RETORNO ES -2 ES QUE EL ID NO FUE ENCONTRADO
	}
	return retorno;
}

int NEXO_modificarEstructura(eVehiculo listaViajes[],int tamViajes,eTipoVehiculo listaTipos[],int ARRAY_TIPOS)
{
	int retorno;
	int posicion;
	int salir;
	int numero;
	int id;
	eEmpleado aux;
	char otraCadena[50];
	retorno=-5;

	NEXO_mostrarEstructuras(listaEmpleados, tamEmpleados, listaSectores, tamSectores);

	id=ing_pedirEnteroRango("ingrese id a modificar", -1000, 100000);

	aux = EMP_buscarUnoPorID(listaEmpleados, tamEmpleados, id);

	posicion= EMP_buscarPosicionPorID(listaEmpleados, tamEmpleados, id);

		if(listaEmpleados[posicion].isEmpty == CARGADO && listaEmpleados != NULL && tamEmpleados > 0 && posicion != -1 )
		{
			do{
				printf("1 para modificar nombre\n");
				printf("2 para modificar apellido\n");
				printf("3 para modificar salario\n");
				printf("4 para modificar sector\n");
				printf("5 para salir de la modificacion\n");


				utn_getNumero("ingrese numero entre 1 y 5" , "reingrese" ,1, 5,3,&numero);

				switch(numero)
				{
					case 1:

						//utn_getString("ingrese destino del viaje\n", "error, reingrese destino\n",3,STRING_DESTINO,aux.destino);
						//strncpy(listaEmpleados[posicion].nombre,aux.nombre,LEN_CHARS);

					break;

					case 2:

						//utn_getString("ingrese destino del viaje\n", "error, reingrese destino\n",3,STRING_DESTINO,aux.destino);
						//strncpy(listaEmpleados[posicion].apellido,aux.nombre,LEN_CHARS);

					break;

					case 3:

						//utn_getNumero("ingrese numero entre 1 y 5" , "reingrese" ,1, 5,3,&numero);

					break;

					case 4:

						//SEC_mostrarEstructuras(listaSectores,tamSectores);

						//utn_getNumero("ingrese numero entre 1 y 5" , "reingrese" ,1, 5,3,&numero);

					break;

					case 5:

						printf("SALIR\n");
						salir=ing_pedirEnteroRango("ingrese 1 para salir /0 para seguir", 0, 1);
					break;
				}

			}while(salir != 1);
		}
		return retorno;
}

void NEXO_mostrarUnaEstructura(eVehiculo listaViajes[],int tamViajes,eTipoVehiculo listaTipos[],int ARRAY_TIPOS)
{
	int id;
	eSector aux;
	id=unEmpleado.sector;
	aux=SEC_buscarUnoPorID(listaSectores, tamSectores, id);

	printf("%d - %s - %s - %.2f - %s\n",unEmpleado.id,unEmpleado.nombre,unEmpleado.apellido,
										unEmpleado.salario,aux.descripcionSector)
}

int NEXO_mostrarEstructuras(eVehiculo listaViajes[],int tamViajes,eTipoVehiculo listaTipos[],int ARRAY_TIPOS)
{
	int retorno;
	retorno=-1;
	int i;
	if(listaViajes!= NULL && tamViajes > 0)
	{
		for(i=0;i<tamViajes;i++)
		{
			if(listaViajes[i].isEmpty==CARGADO)
			{
				NEXO_mostrarUnaEstructura(listaViajes[i],tipoViajes, tamViajes);
			}
			retorno=1;
		}
	}
	return retorno;
}*/
