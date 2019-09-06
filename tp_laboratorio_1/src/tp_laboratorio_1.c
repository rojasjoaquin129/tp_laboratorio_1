/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "misfunciones.h"
/* muestra el mensaje para ingresar
 * ingresa un numero para calcular
 * se repite hasta q el operador quiera salir o ingrese erroneamente 5 veces */
int main()
{
    int primeroComando;
    float numeroA=0;
    float numeroB=0;
    int auxiliarNuloB=0;
    float resultadoSalvado=0;
    int resultadoFactorialBSalvado=0;
    int salirDelPrograma=1;
    do{
    printf(" 1. Ingresar 1er operador (A= %f)\n 2. Ingresar 2do operador (B= %f )\n"
           ,numeroA,numeroB);
    if(getInt(&primeroComando," 3. Calcular todas las operaciones\n 4. Informar resultado\n 5. Salir \n","ERROR DATO INVALIDO (al 5to intento se cerra el programa)\n",&numeroA,&numeroB,4)==0)
        {
        if(listaDeComandos (&numeroA ,&numeroB,&resultadoSalvado,&auxiliarNuloB,&resultadoFactorialBSalvado,primeroComando)==0){
            salirDelPrograma=0;}else{
                salirDelPrograma=1;}}
            else {
                salirDelPrograma=1;}
        }while(salirDelPrograma==0);
    }

