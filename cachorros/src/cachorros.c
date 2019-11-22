/*
 ============================================================================
 Name        : cachorros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "cachorro.h"
#include "utn.h"
int filtraMachos(void* pPerroA);
int filtracallejeros(void* pPerroA);
int filtraMenores(void* pPerroA);
int main()
{
    int option = 0;
    //char respuesta[4036];
    LinkedList* listaCachorros = ll_newLinkedList();
    LinkedList* listaCachorrosfiltrados = ll_newLinkedList();
    LinkedList* listaCachorrosfiltradosCallejeros = ll_newLinkedList();
    LinkedList* listaCachorrosfiltradosMachos = ll_newLinkedList();
    do
    {
        printf( "\n Menu:\n"
                "1. Cargar los datos de los empleados desde un  archivo (modo texto).\n"
                "2. imprimir lista\n"
                "3. flitrar menores de 45 dias"
                "4. filtrar machos\n"
                "5. generar listado de callejeros\n"
                "6. salir\n");

        if (getInt(&option,"ingrese una opcion\n","ERROR , NO CORRESPONDE OPCION\n",1,10,5)==-1)
        {
            printf("dato mal ingresado\n");
        }
        else
        {

            switch(option)
            {
            case 1:
                //ll_removeLinkedlist(listaCachorros);
                //if(getString(respuesta,"ingrese nombre del archivo\n","ERROR ,NO INCRESO CORRECTAMENTE \n",1,50,5)==-1)
                  /*{
                   printf("ERROR AL INGRESAR NOMBRE DEL ARCHIVO, SE SALDRA AL MENU PRINCIPAL\n");
                   break;
                  }*/

                if (controller_loadFromText("cachorros.csv",listaCachorros)!=-1)
                {
                    printf("DATOS GUARDADOS CON EXITO\n");
                    break;

                }
                else
                {
                    printf("ERROR, LOS DATOS NO SE PUEDEN GUARDAR\n");
                    break;
                }
                break;
            case 2:
            	controller_List(listaCachorros);
            	break;
            case 3:
            	listaCachorrosfiltrados=filter(listaCachorros,filtraMenores);
            	controller_List(listaCachorrosfiltrados);
            	controller_saveAsText("cachorrosmenores.csv",listaCachorrosfiltrados);
                break;
            case 4:
            	listaCachorrosfiltradosMachos=filter(listaCachorros,filtraMachos);
            	controller_List(listaCachorrosfiltradosMachos);
            	controller_saveAsText("cachorrosMachos.csv",listaCachorrosfiltradosMachos);
                break;
            case 5:
            	listaCachorrosfiltradosCallejeros=filter(listaCachorros,filtracallejeros);
            	controller_List(listaCachorrosfiltradosCallejeros);
            	controller_saveAsText("cachorrosCallejeros.csv",listaCachorrosfiltradosCallejeros);
                break;
            case 6:
                printf("QUE TENGA UN BUEN DIA\n");
                break;
            default :
                printf("OPCION INCORRECTA\n");
                break;
            }
        }
    }
    while(option != 6);
    return 0;
}

int filtraMenores(void* pPerroA)
{
    Cachorro *A;
    A=(Cachorro*)pPerroA;


    if (A->dias > 45)
        return 1;
    else
    {
        return -1;
    }
    return 0;
}

int filtraMachos(void* pPerroA)
{
    Cachorro *A;
    A=(Cachorro*)pPerroA;
    if (A->genero == 'M')
        return 1;
    else
    {
        return 0;
    }
    return -1;
}
int filtracallejeros(void* pPerroA)
{
    Cachorro *A;
    A=(Cachorro*)pPerroA;
    if (strcmp(A->raza ,"Callejero")==0)
        return 1;
    else
    {
        return -1;
    }
    return 0;
}

