#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cachorro.h"
#include "utn.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_cachorrosFromText(FILE* pFile, LinkedList* pArrayListCachorro)
{
    char id[4096];
    char nombre[4096];
    char dias[4096];
    char reservado[4096];
    char genero[4096];
    char raza[4096];

    Cachorro* auxCachorro;
    //auxCachorro=cachorro_new();
    int retorno=-1;
    if(pFile != NULL &&  pArrayListCachorro != NULL )
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
               id,
               nombre,
               dias,
               raza,
			   reservado,
			   genero);
        while(!feof(pFile))
        {
        	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
        	               id,
        	               nombre,
        	               dias,
        	               raza,
        				   reservado,
        				   genero);
            auxCachorro=cachorro_newParametros(id,nombre,dias,raza,reservado,genero);
            if(auxCachorro!=NULL)
            {
               ll_add(pArrayListCachorro, auxCachorro);
                retorno=0;

            }
        }

    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int leido=0;
    int retorno=-1;
    if (pFile !=NULL && pArrayListEmployee!=NULL )
    {
        while(!feof(pFile))
        {
            Employee* auxEmpleadoBinario=employee_new();
            leido=fread(auxEmpleadoBinario,sizeof(Employee),1,pFile);
            if(leido!=0)
            {
                ll_add(pArrayListEmployee, auxEmpleadoBinario);
                retorno=0;
            }

        }
    }

    return retorno;
}
*/
