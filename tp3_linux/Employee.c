#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int isValidNombre(char* nombre);
static int isValidId(int id);
static int isValidHora(int horas);
static int isValidSueldo(int sueldo);

Employee* employee_new()
{
    return malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* retorno = NULL;
    Employee* this;
    this = employee_new();
    if(this != NULL)
    {
        if( 	employee_setNombre(this,nombreStr) == 0 &&
                employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))== 0 &&
                employee_setId(this,atoi(idStr))== 0 &&
                employee_setSueldo(this,atoi(sueldoStr))==0)
        {
            retorno = this;
        }
        else
        {
            employee_delete(this);
        }

    }
    return retorno;
}


void employee_delete(Employee* this)
{
    free(this);
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    return 1;
}


int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this!=NULL && isValidId(id))
    {
        retorno = 0;
        if(id < 0)
        {
            maximoId++;
            this->id = maximoId;
        }
        else
        {
            if(id > maximoId)
                maximoId = id;
            this->id = id;
        }
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno = 0;
    }
    return retorno;
}

static int isValidId(int id)
{
    return 1;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this!=NULL && isValidHora(horasTrabajadas))
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

static int isValidHora(int horas)
{
    return 1;
}

static int isValidSueldo(int sueldo)
{
    return 1;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this!=NULL && isValidSueldo(sueldo))
    {
        this->sueldo=sueldo;
        retorno = 0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno = 0;
    }
    return retorno;
}



