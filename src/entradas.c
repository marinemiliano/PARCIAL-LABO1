/*
 * entradas.c
 *
 *  Created on: 21 oct. 2022
 *      Author: marin
 */


#include "entradas.h"


int utn_getNumero(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int* pResultado)
{
	int retorno = -1;
	int rtnGetInt;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		rtnGetInt = getInt(&bufferInt);

		if(rtnGetInt == 0 && pResultado != NULL && mensaje != NULL && mensajeError != NULL
				&& reintentos >= 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}

		printf("%s",mensajeError);
		reintentos--;

	}while(reintentos>=0);

	return retorno;
}

int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(	pResultado != NULL &&
		myGets(buffer, sizeof(buffer)) == 0 &&
		esNumerica(buffer,sizeof(buffer)) )
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	return retorno;
}


int esNumerica(char* cadena, int limite)
{
	int retorno = -1;
	int i;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1; //VERDADERO
		for(i = 0; i<limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strlen(bufferString)-1] == '\n')
			{
				bufferString[strlen(bufferString)-1] = '\0';
			}
			if(strlen(bufferString) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}


int utn_getString(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado)
{
	char bufferString[4096];
	int retorno = -1;
	int i = 0;

	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s",mensaje);

		if(getString(bufferString, sizeof(bufferString)) == 0 &&
		   strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			i++;
			bufferString[0] = toupper(bufferString[0]);
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}

		printf("%s",mensajeError);
	}

	return retorno;
}



int getString(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL)
    	{
    		if(	myGets(buffer,sizeof(buffer)) == 0 &&
    			esString(buffer, sizeof(buffer)) &&
    			strnlen(buffer,sizeof(buffer)) < longitud )
    		{
    			strncpy(pResultado,buffer,longitud);
    			retorno = 0;
    		}
    	}
    return retorno;
}

int esString(char* cadena, int longitud)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i = 0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] == " ")
			{
				if( (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') )
				{
					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}
