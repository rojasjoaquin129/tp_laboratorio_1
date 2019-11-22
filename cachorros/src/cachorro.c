#include "cachorro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int isValidNombre(char* nombre);
static int isValidId(int id);
static int isValidDia(int horas);
static int isValidReservado(char *reservado);
static int isValidGenero(char* genero);

Cachorro* cachorro_new()
{
    return malloc(sizeof(Cachorro));
}

Cachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* dias ,char* raza,char* reservado , char* genero)
{
    Cachorro* retorno = NULL;
    Cachorro* this;
    this = cachorro_new();
    if(this != NULL)
    {
        if( 	cachorro_setNombre(this,nombreStr) == 0 &&
        		cachorro_setRaza(this,raza) == 0 &&
                cachorro_setDias(this,atoi(dias))== 0 &&
                cachorro_setId(this,atoi(idStr))== 0 &&
				cachorro_setReservado(this,reservado) == 0 &&
                cachorro_setGenero(this,genero)==0)
        {
            retorno = this;
        }
        else
        {
            cachorro_delete(this);
        }

    }
    return retorno;
}


void cachorro_delete(Cachorro* this)
{
    free(this);
}

int cachorro_setNombre(Cachorro* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int cachorro_getNombre(Cachorro* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

int cachorro_setGenero(Cachorro* this,char* genero)
{
    int retorno = -1;
    if(this!=NULL && isValidGenero(genero))
    {
        this->genero =*genero;
        retorno = 0;
    }
    return retorno;
}

int cachorro_getGenero(Cachorro* this,char* genero)
{
    int retorno = -1;
    if(this!=NULL && genero!=NULL)
    {
        *genero =this->genero;

        retorno = 0;
    }
    return retorno;
}



int cachorro_setReservado(Cachorro* this,char* reservado)
{
    int retorno = -1;
    if(this!=NULL && isValidReservado(reservado))
    {
        strcpy(this->reservado,reservado);
        retorno = 0;
    }
    return retorno;
}

int cachorro_getReservado(Cachorro* this,char* reservado)
{
    int retorno = -1;
    if(this!=NULL && reservado!=NULL)
    {
        strcpy(reservado, this->reservado);
        retorno = 0;
    }
    return retorno;
}

int cachorro_setRaza(Cachorro* this,char* raza)
{
    int retorno = -1;
    if(this!=NULL && isValidNombre(raza))
    {
        strcpy(this->raza,raza);
        retorno = 0;
    }
    return retorno;
}

int cachorro_getRaza(Cachorro* this,char* raza)
{
    int retorno = -1;
    if(this!=NULL && raza!=NULL)
    {
        strcpy(raza, this->raza);
        retorno = 0;
    }
    return retorno;
}


static int isValidNombre(char* nombre)
{
    return 1;
}

static int isValidGenero(char* genero)
{
    return 1;
}

int cachorro_setId(Cachorro* this,int id)
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
int cachorro_getId(Cachorro* this,int* id)
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


int cachorro_setDias(Cachorro* this,int dias)
{
    int retorno = -1;
    if(this!=NULL && isValidDia(dias))
    {
        this->dias=dias;
        retorno = 0;
    }
    return retorno;
}

int cachorro_getDias(Cachorro* this,int* dias)
{
    int retorno = -1;
    if(this!=NULL && dias!=NULL)
    {
        *dias=this->dias;
        retorno = 0;
    }
    return retorno;
}

static int isValidDia(int horas)
{
    return 1;
}

static int isValidReservado(char *reservado)
{
    return 1;
}
/*int cachorro_setSueldo(Cachorro* this,int sueldo)
{
    int retorno = -1;
    if(this!=NULL && isValidSueldo(sueldo))
    {
        this->sueldo=sueldo;
        retorno = 0;
    }
    return retorno;
}
int cachorro_getSueldo(Cachorro* this,int* sueldo)
{
    int retorno = -1;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno = 0;
    }
    return retorno;
}
*/
