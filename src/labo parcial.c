/*
 ============================================================================
 Name        : labo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#define  CHAR_COLOR 10
#define  CHAR_DESCRIPCION 30
#define  ARRAY_VEHICULOS 10
#define  REINTENTOS 3
#define  ARRAY_TIPOS 3

#include "entradas.h"
#include "nexo.h"


int main(void)
{
	setbuf(stdout,NULL);

	eVehiculo listaVehiculos[ARRAY_VEHICULOS];

	eTipoVehiculo listaTipos[ARRAY_TIPOS]={{1000, "SEDAN 3PTAS"}, {1001,"SEDAN 5PTAS"}, {1002,"CAMIONETA"}};


	int opcion;
	int salir;

	VEHICULO_inicilizarEstructura(listaVehiculos, ARRAY_VEHICULOS);

	/*A. ALTA VEHICULO
	B. MODIFICAR VEHICULO: Se ingresará el idVehiculo, permitiendo en un submenú modificar:
	● descripcion
	● precioServicio
	C. BAJA VEHICULO: Se ingresará el id del vehículo y se realizará una baja lógica.
	D. LISTAR VEHICULOS: Hacer un único listado de todos los vehículos ordenados por tipo y por
	descripción.
	E. LISTAR TIPOS
	F. ALTA HOJA DE SERVICIO: Se dará de alta cada ocurrencia de la hoja de Servicio pidiéndole al
	usuario que elija un vehículo.
	G. LISTAR HOJAS DE SERVICIO
	H. INFORMES*/

		do
				{
					utn_getNumero(" 1.ALTA DEL VEHICULO \n 2.MODIFICAR VEHICULO\n 3.BAJA VEHICULO\n "
					"4.LISTAR VEHICULOS\n 5.LISTAR TIPOS\n 6.ALTA HOJA DE SERVICIO\n 7.LISTAR HOJAS DE SERVICIO\n 8.INFORMES\n"
					" 9.SALIR\n "
					"seleccione una opcion: ", "error numero ingresado no comprendido esntre 1 y 9 \n", 1, 9, REINTENTOS,&opcion);


						switch(opcion)
						{
							case 1:

								printf(" 1.ALTA DEL VEHICULO\n");
								{
									(NEXO_altaEstructura(listaVehiculos, ARRAY_VEHICULOS, listaTipos, ARRAY_TIPOS)==0)
									{
										printf("se cargo\n");
									}
									/*if(NEXO_altaEstructura(listaVehiculos,ARRAY_VEHICULOS,listaTipos,ARRAY_TIPOS)==0)
									{
										printf("se cargo\n");
									}*/
								}

							break;

							case 2:
									printf("2.MODIFICAR VEHICULO\n");
							break;

							case 3:
									printf("3.BAJA VEHICULO\n");
							break;

							case 4:
									printf("4.LISTAR VEHICULOS\n");

							break;

							case 5:
									printf("5.LISTAR TIPOS\n");
							break;

							case 6:
									printf("6.ALTA HOJA DE SERVICIO");
							break;

							case 7:
									printf("7.LISTAR HOJAS DE SERVICIO");
							break;

							case 8:
									printf("INFORMAR\n");
							break;

							case 9:
									printf("SALIR\n");

									utn_getNumero("ingrese 1 para salir /0 para seguir", "error", 0, 1, 3, &salir);
							break;


						}

					printf("SALIR\n");
					utn_getNumero("ingrese 1 para salir /0 para seguir", "error", 0, 1, 3, &salir);

				}while(salir != 1);




	return EXIT_SUCCESS;
}
