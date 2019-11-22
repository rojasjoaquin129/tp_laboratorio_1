#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cachorro.h"
#include "parser.h"
#include "utn.h"
#include "controller.h"

int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    FILE* pFile;
    pFile = fopen(path,"r");
    int retorno=-1;
    int control;
    printf("solo");
    if(pFile != NULL)
    {
        control=parser_cachorrosFromText(pFile,pArrayList);
        if(control!=-1)
            retorno=0;
    }
    fclose(pFile);
    return retorno;
}
int ll_removeLinkedlist(LinkedList* this )
{

    int retorno=-1;
    Cachorro*element;
    int i=ll_len(this);
    if(this != NULL )
    {
        while(ll_isEmpty(this)!=1)
        {
            element=(Cachorro*)ll_pop(this,i);
            cachorro_delete(element);
            i--;

        }
        retorno=0;
    }
    return retorno;
}
int controller_List(LinkedList* pArrayList)
{
    int i;
    int len=0;
    int auxid=0;
    int auxDias=0;
    char auxNombre[4036];
    char auxRaza[4036];
    char auxReservado[4036];
    char auxGenero[4036];
    Cachorro* auxCachorro;
    if(pArrayList!=NULL)
    {
        len=ll_len(pArrayList);
        printf("        ID       |        NOMBRE      |       DIAS       |      RAZA    |    RESERVADO  |     GENERO    |  \n"
               "-----------------------------------------------------------------------------------------------------------\n");
        for(i=0; i<len; i++)
        {
            auxCachorro=(Cachorro*)ll_get(pArrayList,i);
            if (auxCachorro!=NULL)
            {
            	cachorro_getNombre(auxCachorro,auxNombre);
            	cachorro_getRaza(auxCachorro,auxRaza);
            	cachorro_getDias(auxCachorro ,& auxDias);
            	cachorro_getId(auxCachorro,&auxid);
            	cachorro_getReservado(auxCachorro,auxReservado);
            	cachorro_getGenero(auxCachorro,auxGenero);

                printf("      %d        |        %s         |      %d      |       %s    |    %s   |   %s     |\n",auxid,auxNombre,auxDias,auxRaza,auxReservado,auxGenero );
                printf("----------------------------------------------------------------------------\n");
            }

        }
    }
    return 1;
}
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* Texto;
    int i;
    int retorno=-1;
    int auxid=0;
        int auxDias=0;
        char auxNombre[4036];
        char auxRaza[4036];
        char auxReservado[4036];
        char auxGenero;
    int len=ll_len(pArrayListEmployee);
    Cachorro*empleado;
    if(len!=0 && path != NULL && pArrayListEmployee !=NULL )
    {
        empleado=cachorro_new();
        Texto=fopen(path,"w");
        if (Texto==NULL)
        {
            printf("\nNo se pudo abrir el archivo.\n");
            retorno=-1;
        }
        fprintf(Texto,"id / nombre / Dias / Raza  / Reservado / GENERO \n");
        for (i=0; i<len; i++)
        {
            empleado=(Cachorro*)ll_get(pArrayListEmployee,i);
            cachorro_getId(empleado,&auxid);
            cachorro_getRaza(empleado,auxRaza);
            cachorro_getNombre(empleado,auxNombre);
            cachorro_getReservado(empleado,auxReservado);
            cachorro_getGenero(empleado,&auxGenero);
            cachorro_getDias(empleado,&auxDias);

            fprintf(Texto,"%d / %s / %d / %s /% s / %c \n",auxid,auxNombre,auxDias,auxRaza,auxReservado,auxGenero);
            retorno=0;

        }
        fclose(Texto);
    }
    return retorno;
}
