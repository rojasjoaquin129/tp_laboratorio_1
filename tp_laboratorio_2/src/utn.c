/*
 * utn.c
 *
 *  Created on: 28 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//Linux
#define PURGAR __fpurge(stdin);
//Windows
//#define PURGAR fflush(stdin);


int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			PURGAR
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
int getFloat(float *pResultado,
			 char *pMensaje,
			 char *pMensajeError,
			 float minimo,
			 float maximo,
			 int reintentos)
{
	int retorno = EXIT_ERROR;
	float buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",pMensaje);
			PURGAR
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
int getChar(  char *pResultado,
			  char *pMensaje,
			  char *pMensajeError,
			  char minimo,
			  char maximo,
			  int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			PURGAR
			if(scanf("%c",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s", pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
int getString (char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer[500];
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",pMensaje);
			PURGAR
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1] = '\0';
			if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
			{
				strncpy(pResultado,buffer,maximo+1);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

void burbuja(int array[], int limite){
	int i;
	int flagOrdeno=1;
	int swap;

	while(flagOrdeno == 1){
		flagOrdeno = 0;
		for(i=0; i<limite-1; i++){
			if(array[i] > array[i+1]){
				swap = array[i];
				array[i] = array[i+1];
				array[i+1] = swap;
				flagOrdeno = 1;
			}
		}
	}
}

void insercion(int array[], int limite){
	int i;
	int j;
	int flagOrdeno;
	int swap;


	for(i=1; i<limite; i++){
		j=i;
		flagOrdeno = 1;
		while(flagOrdeno != 0 && j!=0){
			flagOrdeno = 0;

			if(array[j-1] > array[j]){
				swap = array[j-1];
				array[j-1] = array[j];
				array[j] = swap;
				flagOrdeno = 1;
			}
			j--;
		}
	}
}
