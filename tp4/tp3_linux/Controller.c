#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path,"r");
    int retorno=-1;
    int control;
    if(pFile != NULL)
    {
        control=parser_EmployeeFromText(pFile,pArrayListEmployee);
        if(control!=-1)
            retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pFileB;
    pFileB = fopen(path,"rb");
    int retorno=-1;
    int control;
    if(pFileB != NULL && path !=NULL && pArrayListEmployee!=NULL)
    {
        control=parser_EmployeeFromBinary(pFileB,pArrayListEmployee);
        if(control!=-1)
            retorno=0;
    }
    fclose(pFileB);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxNombre [4036];
    int retorno = -1;
    Employee*empleado;
    if(pArrayListEmployee!=NULL)
    {
        printf("ALTA DE EMPLEADO\n");
        empleado=employee_new();
        if (getNombre(auxNombre, "Ingrese nombre\n","ERROR ,NO INCRESO CORRECTAMENTE \n", 2, 50, 3)
                != -1)
        {
            if (getInt(&auxHorasTrabajadas, "Ingrese horas trabajadas del empleado \n", "ERROR ,NO INCRESO CORRECTAMENTE \n",1,
                       1000000, 3) == 0)
            {
                if (getInt(&auxSueldo,
                           "Ingese sueldo del empleado\n","ERROR ,NO INCRESO CORRECTAMENTE \n",1,
                           9000000, 3) != -1)
                {
                    employee_setId(empleado,retorno);
                    employee_setNombre(empleado,auxNombre);
                    employee_setHorasTrabajadas(empleado,auxHorasTrabajadas);
                    employee_setSueldo(empleado,auxSueldo);
                    if (ll_add(pArrayListEmployee,empleado)
                            == 0)
                    {
                        printf("Alta exitosa\n");
                        retorno = 0;
                    }

                }
            }
        }
    }
    if (retorno != 0)
    {
        printf("Error al cargar los datos\n");
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int idIn=0;
    int retorno=-1;
    int index=0;
    Employee*auxEmpleado;
    if(pArrayListEmployee!=NULL)
    {
        auxEmpleado=employee_new();
        printf("MODIFICACION DE EMPLEADO \n");
        if (getInt(&idIn,"ingrese el id del empleado a modificar\n","ERROR,DATO NO CORRESPONDE\n",1,1000000,5)!=-1)
        {
            if (ll_getIndexById(pArrayListEmployee,idIn,&index)==-1)
            {
                printf("el id ingresado no existe\n");
            }
            else
            {
                auxEmpleado=ll_get(pArrayListEmployee,index);
                if(controller_listModific(pArrayListEmployee,auxEmpleado)!=-1)
                {
                    if(ll_set(pArrayListEmployee,index,auxEmpleado)!=-1)
                    {
                        retorno=0;
                        printf("MODIFICACION EXITOSA\n");
                    }
                }
            }


        }

        if (retorno != 0)
        {
            printf("Error al cargar los datos\n");
        }

    }


    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int sueldo=0;
    int horasTrabajadas=0;
    char nombre[4036];
    int idIn=0;
    int id=0;
    int retorn=-1;
    char conf;
    int index=0;
    Employee*auxEmpleado;
    if(pArrayListEmployee!=NULL)
    {
        auxEmpleado=employee_new();
        printf("ELIMINAR EMPLEADO \n");
        if (getInt(&idIn,"ingrese el id del empleado a modificar\n","ERROR,DATO NO CORRESPONDE\n",1,1000000,5)!=-1)
        {
            if (ll_getIndexById(pArrayListEmployee,idIn,&index)==-1)
            {
                printf("el id ingresado no existe\n");
            }
            else
            {
                auxEmpleado=(Employee*)ll_get(pArrayListEmployee,index);
                if (auxEmpleado!=NULL)
                {
                    employee_getId(auxEmpleado,&id);
                    employee_getNombre(auxEmpleado,nombre);
                    employee_getHorasTrabajadas(auxEmpleado,&horasTrabajadas);
                    employee_getSueldo(auxEmpleado,&sueldo);
                    printf("ID          NOMBRE           HORAS DE TRABAJO        SUELDO \n");
                    printf("%d        %s          %d           %d    \n",id,nombre,horasTrabajadas,sueldo );
                }
                printf("Desea eliminarlo? (S / N) \n");
                getChar(&conf,"ingrese S si para confirmar\n","ERROR ,NO INCRESO CORRECTAMENTE \n",'a','z',5);
                if (conf != 's' && conf != 'n')
                {
                    printf("ERROR AL INGRESAR RESPUESTA\n");
                }
                if (conf == 's')
                {
                    if (ll_remove(pArrayListEmployee,index)!=-1)
                    {
                        retorn=0;
                        printf("SE ELIMINO EL EMPLEADO CON EXITO \n");
                    }

                }
                if(conf=='n')
                {
                    retorn=0;
                    printf("NO SE ELIMINO EL EMPLEADO \n");
                }

            }
        }
    }
    if (retorn ==-1)
    {
        printf("Error al eliminar los datos\n");
    }
    return retorn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int len=0;
    int auxid=0;
    int auxHorasTrabajadas=0;
    int auxSueldo=0;
    char auxNombre[4036];
    Employee* auxEmpleado;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        printf("        ID       |        NOMBRE      |       HORAS TRABAJADAS        |      SUELDO     \n"
               "----------------------------------------------------------------------------------------\n");
        for(i=0; i<len; i++)
        {
            auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            if (auxEmpleado!=NULL)
            {
                employee_getId(auxEmpleado,&auxid);
                employee_getNombre(auxEmpleado,auxNombre);
                employee_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas);
                employee_getSueldo(auxEmpleado,&auxSueldo);

                printf("      %d        |        %s         |      %d        |       %d\n",auxid,auxNombre,auxHorasTrabajadas,auxSueldo );
                printf("----------------------------------------------------------------------------\n");
            }

        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int desicion;
    int retorno=-1;
    if (pArrayListEmployee!=NULL)
    {
        printf("COMO DESEA ORDENAR?\n"
               "0 --> DESENDIENTE\n"
               "1 --> ASENDENTE\n");
        if(getInt(&desicion,"ingrese respuesta 1 /0 \n","ERROR , NO CORRESPONDE INGRESO\n",0,1,5)!=-1)
        {
            ll_sort(pArrayListEmployee,comparaEmpleados,desicion);
            retorno=0;
        }
        else
        {
            printf("EL ORDENAMIENTO NO SE PUDO LOGRAR\n");
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* Texto;
    int i;
    int retorno=-1;
    int sueldo=0;
    int horasTrabajadas=0;
    char nombre[4036];
    int id=0;
    int len=ll_len(pArrayListEmployee);
    Employee*empleado;
    if(len!=0 && path != NULL && pArrayListEmployee !=NULL )
    {
        empleado=employee_new();
        Texto=fopen(path,"w");
        if (Texto==NULL)
        {
            printf("\nNo se pudo abrir el archivo.\n");
            retorno=-1;
        }
        fprintf(Texto,"id / nombre / horasTrabajadas / sueldo \n");
        for (i=0; i<len; i++)
        {
            empleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&id);
            employee_getHorasTrabajadas(empleado,&horasTrabajadas);
            employee_getNombre(empleado,nombre);
            employee_getSueldo(empleado,&sueldo);
            fprintf(Texto,"%d / %s / %d / %d \n",id,nombre,horasTrabajadas,sueldo);
            retorno=0;

        }
        fclose(Texto);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* Binario;
    int retorno=-1;
    int i;
    int len=ll_len(pArrayListEmployee);
    if(len!=0 && path != NULL && pArrayListEmployee !=NULL )
    {
        Binario=fopen(path,"wb");
        if (Binario==NULL)
        {
            printf("\nNo se pudo abrir el archivo.\n");
            retorno=-1;
        }
        for (i=0; i<len; i++)
        {
            fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,Binario);
            retorno=0;

        }
        fclose(Binario);
    }
    return retorno;
}

/** \brief submenu  para modificar el empleado
 *
 *\param pArrayListEmployee LinkedList*
 *\param iauxEmpleado Employee * puntero
 *
 *
 * \return int
 */

int controller_listModific (LinkedList*pArrayListEmployee,void *auxEmpleado)
{

    int auxSueldo=0;
    int sueldo=0;
    int id=0;
    char comfirmacion;
    int option=0;
    char auxNombre[4036];
    char nombre[4036];
    int auxHorasTrabajadas=0;
    int horasTrabajadas=0;
    int retorno=-1;
    Employee *list;
    if (pArrayListEmployee!=NULL && auxEmpleado!=NULL)
    {
        list=auxEmpleado;
        employee_getId(auxEmpleado,&id);
        employee_getNombre(auxEmpleado,nombre);
        employee_getHorasTrabajadas(auxEmpleado,&horasTrabajadas);
        employee_getSueldo(auxEmpleado,&sueldo);
        printf("ID          NOMBRE           HORAS DE TRABAJO        SUELDO \n");
        printf("%d          %s                %d               %d  \n",id,nombre,horasTrabajadas,sueldo);

        do
        {

            printf ("\n"
                    "                  ºººººººººººººººººººººººººººººººººººººº\n"
                    "                  ºº                                  ºº\n"
                    "                  ºº      MENU DE MODIFICACION        ºº\n"
                    "                  ºº                                  ºº\n"
                    "                  ºº  1_MODIFICAR NOMBRE              ºº\n"
                    "                  ºº  2_MODIFICAR HORAS DE TRABAJO    ºº\n"
                    "                  ºº  3_MODIFICAR SUELDO              ºº\n"
                    "                  ºº  4_CONFIRMAR MODIFICACION        ºº\n"
                    "                  ºº                                  ºº\n"
                    "                  ºººººººººººººººººººººººººººººººººººººº\n");

            getInt(&option,"ingrese opcion a elegir\n","ERROR ,NO INCRESO CORRECTAMENTE \n",1,4,5);
            switch (option)
            {
            case 1:
                printf("Nombre a cambiar : %s\n",nombre);
                if(getNombre(auxNombre,"ingrese nombre para cambiarlo\n","ERROR ,NO INCRESO CORRECTAMENTE \n",4,50,5)==-1)
                {
                    printf("ERROR AL INGRESAR NOMBRE, SE SALDRA DE LA MODIFICAICON\n");
                    break;
                }
                employee_setNombre(list,auxNombre);
                break;
            case 2:
                printf("Horas de trabajo a modificar  : %d\n",horasTrabajadas);
                if(getInt(&auxHorasTrabajadas,"ingrese horas  trabajadas para cambiarlo\n","ERROR ,NO INCRESO CORRECTAMENTE \n",1,500000,5)==-1)
                {
                    printf("ERROR AL INGRESAR HORAS DE TRABAJO , SE SALDRA DE LA MODIFICAICON\n");
                    break;
                }
                employee_setHorasTrabajadas(list,auxHorasTrabajadas);
                break;
            case 3:
                printf("Sueldo a cambiar : %d\n",sueldo);
                if(getInt(&auxSueldo,"ingrese sueldo para cambiarlo\n","ERROR ,NO INCRESO CORRECTAMENTE \n",1,900000,5)==-1)
                {
                    printf("ERROR AL INGRESAR SUELDO  , SE SALDRA DE LA MODIFICAICON\n");
                    break;
                }
                employee_setSueldo(list,auxSueldo);
                break;
            case 4:
                employee_getNombre(list,nombre);
                employee_getHorasTrabajadas(list,&horasTrabajadas);
                employee_getSueldo(list,&sueldo);
                printf("ID          NOMBRE           HORAS DE TRABAJO        SUELDO \n");
                printf("%d          %s                %d               %d  \n",id,nombre,horasTrabajadas,sueldo);
                printf("Desea hacer  la modificacion (S / N) \n");
                getChar(&comfirmacion,"ingrese S si para confirmar\n","ERROR ,NO INCRESO CORRECTAMENTE \n",'a','z',5);
                if (comfirmacion != 's' && comfirmacion != 'n')
                {
                    printf("Error al ingresar");
                }
                if (comfirmacion == 's')
                {
                    employee_setId(auxEmpleado,id);
                    employee_setNombre(auxEmpleado,nombre);
                    employee_setHorasTrabajadas(auxEmpleado,horasTrabajadas);
                    employee_setSueldo(auxEmpleado,sueldo);
                    retorno = 0;
                }
                break;
            default:
                printf("ERROR , eleccion no corresponde \n");
                break;
            }
        }
        while (comfirmacion != 's' && comfirmacion != 'n');
    }
    return retorno;
}

/** \brief su funcion es recorrer el linkelist comparando el id y devuelve posicion en la lista
 *
 *\param pArrayListEmployee LinkedList*
 *\param idIn int
 *\param posicion int* puntero
 *
 * \return int
 */

int ll_getIndexById(LinkedList* this,int idIn,int*posicion )
{
    int i=0;
    int retorno=-1;
    int id=0;
    Employee*element;
    if(this != NULL && idIn >=0 )
    {
        for (i=0; i<ll_len(this); i++)
        {
            element=(Employee*)ll_get(this,i);
            employee_getId(element,&id);
            if(id==idIn)
            {
                *posicion=i;
                retorno=id;
                break;
            }

        }
    }
    return retorno;
}
int comparaEmpleados(void* pEmpleadoA,void* pEmpleadoB)
{
    Employee *A;
    Employee*B;
    A=(Employee*)pEmpleadoA;
    B=(Employee*)pEmpleadoB;
    if (strcmp(A->nombre,B->nombre)>0)
        return 1;
    if(strcmp(A->nombre,B->nombre)==0 && A->id > B->id)
        return 1;
    if(strcmp(A->nombre,B->nombre)<0)
    {
        return -1;
    }
    return 0;
}

/** \brief borrar de cada empleado de la lista y liberar memoria de cada empleado
 *
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int ll_removeLinkedlist(LinkedList* this )
{

    int retorno=-1;
    Employee*element;
    int i=ll_len(this);
    if(this != NULL )
    {
        while(ll_isEmpty(this)!=1)
        {
            element=(Employee*)ll_pop(this,i);
            employee_delete(element);
            i--;

        }
        retorno=0;
    }
    return retorno;
}
