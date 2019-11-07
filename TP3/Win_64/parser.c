#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char id[4096];
    char nombre[4096];
    char horasTrabajadas[4096];
    char sueldo[4096];
    Employee* auxEmpleado;
    int retorno=-1;
    if(pFile != NULL &&  pArrayListEmployee != NULL )
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
               id,
               nombre,
               horasTrabajadas,
               sueldo);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                   id,
                   nombre,
                   horasTrabajadas,
                   sueldo);
            auxEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
            if(auxEmpleado!=NULL)
            {
                ll_add(pArrayListEmployee, auxEmpleado);
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
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
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
