/*
 * cachorro.h
 *
 *  Created on: 21 nov. 2019
 *      Author: alumno
 */

#ifndef CACHORRO_H_
#define CACHORRO_H_

typedef struct
{
    int id;
    char nombre[128];
    int dias;
    char raza[128];
    char reservado[128];
    char genero;
}Cachorro;

Cachorro* cachorro_new();
Cachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* dias ,char* raza,char* reservado , char* genero);
void cachorro_delete(Cachorro* this);

int cachorro_setNombre(Cachorro* this,char* nombre);
int cachorro_getNombre(Cachorro* this,char* nombre);

int cachorro_setReservado(Cachorro* this,char* reservado);
int cachorro_getReservado(Cachorro* this,char* reservado);

int cachorro_setRaza(Cachorro* this,char* raza);
int cachorro_getRaza(Cachorro* this,char* raza);

int cachorro_setId(Cachorro* this,int id);
int cachorro_getId(Cachorro* this,int* id);

int cachorro_setDias(Cachorro* this,int dias);
int cachorro_getDias(Cachorro* this,int* dias);

int cachorro_setGenero(Cachorro* this,char* reservado);
int cachorro_getGenero(Cachorro* this,char* reservado);
#endif /* CACHORRO_H_ */
