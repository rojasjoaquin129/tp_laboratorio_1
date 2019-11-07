#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flag=0;
    int flag2=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        printf( "\n Menu:\n"
                "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
                "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
                "3. Alta de empleado\n"
                "4. Modificar datos de empleado\n"
                "5. Baja de empleado\n"
                "6. Listar empleados\n"
                "7. Ordenar empleados por nombre \n"
                "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
                "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
                "10. Salir\n");

        if (getInt(&option,"ingrese una opcion\n","ERROR , NO CORRESPONDE OPCION\n",1,10,5)==-1)
        {
            printf("dato mal ingresado\n");
        }
        else
        {

            switch(option)
            {
            case 1:
                ll_removeLinkedlist(listaEmpleados);
                if (controller_loadFromText("data.csv",listaEmpleados)!=-1)
                {
                    printf("DATOS GUARDADOS CON EXITO\n");
                    break;
                    flag=1;
                }
                else
                {
                    printf("ERROR, LOS DATOS NO SE PUEDEN GUARDAR\n");
                    break;
                }
                break;
            case 2:
            	if(flag2==1)
            	{

					ll_removeLinkedlist(listaEmpleados);
					if(controller_loadFromBinary("data2.csv",listaEmpleados)!=-1)
					{
						printf("SE CARGO CON EXITO \n");
						break;
					}else {
						printf("NO TIENE GUARDADO EL ARCHIVO EN BINARIO , NO SE PUEDE CARGAR EN LA LISTA\n");
						break;
					}
            	}
					else
					{
						printf("NO TIENE GUARDADO EL ARCHIVO EN BINARIO , NO SE PUEDE CARGAR EN LA LISTA\n");
					}
					break;
            case 3:
                if(flag==1)
                {

                    if(controller_addEmployee(listaEmpleados)==-1)
                    {
                        printf("ERROR , NO SE PUDO DAR DEL ALTA EL EMPLEADO\n");
                        break;
                    }
                }
                else
                {
                    printf("NO SE AGREGO LA LISTA , NO SE PUEDE AGREGAR EMPLEADOS\n");
                }
                break;
            case 4:
                if(flag==1)
                {

                    if(controller_editEmployee(listaEmpleados)==-1)
                    {
                        printf("ERROR , NO SE PUDO HACER LA MODIFICACION DEL EMPLEADO\n");
                        break;
                    }
                }
                else
                {
                    printf("NO SE AGREGO LA LISTA , NO SE PUEDE MODIFICAR EL EMPLEADOS\n");
                }
                break;
            case 5:

                if(flag==1)
                {

                    if(controller_removeEmployee(listaEmpleados)==-1)
                    {
                        printf("ERROR , NO SE PUDO ELIMINAR EL EMPLEADO\n");
                        break;
                    }
                }
                else
                {
                    printf("NO SE AGREGO LA LISTA , NO SE PUEDE ELIMINAR EMPLEADOS\n");
                }
                break;
            case 6:
                if(flag==1){
                controller_ListEmployee(listaEmpleados);
                printf("ERROR ,NO SE PUEDE LISTAR LOS  EMPLEADOS\n");
                break;
                }
                else {
                  printf("NO SE AGREGO LA LISTA , NO SE PUEDE LISTAR LOS  EMPLEADOS\n");
                }
                break;
            case 7:
                if(flag==1){
                if (controller_sortEmployee(listaEmpleados)!=-1)
                {
                    printf("SE ORDENO CON EXITO \n");
                    break;
                }else
                {
                    printf("NO SE PUEDE ORDENAR LOS  EMPLEADOS\n");
                    break;
                }
                }
                else{
                    printf("NO SE AGREGO LA LISTA , NO SE PUEDE ORDENAR LOS  EMPLEADOS\n");
                }
                break;
            case 8:

                if(controller_saveAsText("data3.csv",listaEmpleados)!=-1)
                {
                    printf("SE GUARDO CON EXITO \n");
                    break;
                }
                else
                {
                    printf("NO TIENE LA LISTA CARGADA \n");
                    break;
                }
                break;
            case 9:

                if(controller_saveAsBinary("data2.csv",listaEmpleados)!=-1)
                {
                    printf("SE GUARDO CON EXITO \n");
                    flag2=1;
                    break;
                }
                else
                    printf("NO TIENE LA LISTA CARGADA EN TEXTO\n");
                break;
            case 10:
                printf("QUE TENGA UN BUEN DIA\n");
                break;
            default :
                printf("OPCION INCORRECTA\n");
                break;
            }
        }
    }
    while(option != 10);
    return 0;
}
