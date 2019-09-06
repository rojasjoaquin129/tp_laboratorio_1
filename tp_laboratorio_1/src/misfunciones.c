/*
 * misfunciones.c
 *
 *  Created on: 6 sep. 2019
 *      Author: joaquin
 */
#include <stdio.h>
#include <stdlib.h>
#include "misfunciones.h"


/* mediante el numero ingresado verifica alguna del las opicones
 * devuelve un entero para verificar si funciono correctamente*/

    int listaDeComandos(float *pNumeroA,float *pNumeroB, float *pResultadoSalvado,int *pAuxiliarNuloB, int *pResultadoFactorialBSalvado,int comparador){
    float resultado=0;
    char letraIngresadaParaCase4;
    int resultadoFactorialB=0;
    int verificadorNumeroB=0;
    float auxiliarNumeroA=0;
    float auxiliarNumeroB=0;
    int verificacionListaDeComando=0;
    switch (comparador){
	 case 1:
		 if(getFloat(&auxiliarNumeroA,"Ingrese 1er valor (A)\n","ERROR DATO INVALIDO (al 5to intento se cerra el programa)\n",4)==0)
            {
            *pNumeroA=auxiliarNumeroA;}else{
		 verificacionListaDeComando=1;
		 }
        break;
	 case 2:
		 if(getFloat(&auxiliarNumeroB,"Ingrese 2do valor (B)\n","ERROR DATO INVALIDO (al 5to intento se cerra el programa)\n",4)==0){
            *pNumeroB=auxiliarNumeroB;
		 }else{
		 verificacionListaDeComando=1;}
		 break;
	 case 3:
            auxiliarNumeroA=*pNumeroA;
            auxiliarNumeroB=*pNumeroB;
            if (calculos(auxiliarNumeroA,auxiliarNumeroB,&resultado,&verificadorNumeroB, &resultadoFactorialB,&letraIngresadaParaCase4)==1){
                printf("ERROR, no ingreso correctamente la opcion \n");
                fflush(stdin);
            }else{
            *pResultadoSalvado=resultado;
            *pResultadoFactorialBSalvado=resultadoFactorialB;
            }
            *pAuxiliarNuloB=verificadorNumeroB;
            break;
	 case 4:
	     verificadorNumeroB=*pAuxiliarNuloB;
	     resultado=*pResultadoSalvado;
	     resultadoFactorialB=*pResultadoFactorialBSalvado;
         if (mostarResultado(resultado,&letraIngresadaParaCase4,resultadoFactorialB,verificadorNumeroB)==1){
            printf("ERROR, no ingreso calculo para resolver ,intente nuevamente ingresando en la opcion 3");
         }
		 break;
     case 5:
        verificacionListaDeComando=1;
        break;
    default:
        printf("ERROR,valor invalido,ingrese correctamente \n") ;
        break;
    }
     return verificacionListaDeComando;
}
    /*ingresa un carracter para elejir q operacion ejecutar
     * llama a las funciones de operaciones para calcular el resultado
     * regresa un int para verificar si funciono correctamente
     * salva la letra ingresada del operador para poder mostrar el resultado
     * salva el resultado general y el del factorial del segundo numero ingresado(B) ya q en los bucles vuelven a cero
     *
     *  */
int calculos(float numeroUno,float numeroDos, float *pResultado,int  *pVerificadorNumeroB,int *pResultadoFactorialB,char *pLetraIngresadaParaCase4){
    char letraIngresada;
    int verificadorCalculadora=0;
    float resultadoAuxiliar;
    printf("Calcular todas las operaciones\n a. Calcular la suma (A+B) \n b. Calcular la resta (A-B) \n c. Calcular la divicion (AB) \n d. Calcular la multiplicacion (AB) \n e. Calcular el factorial(A!)\n");
    fflush(stdin);
	scanf("%s",&letraIngresada);
	*pLetraIngresadaParaCase4=letraIngresada;
	switch(letraIngresada){
	 case 'a':
		 resultadoAuxiliar=suma(numeroUno,numeroDos);
		 break;
	 case 'b':
		 resultadoAuxiliar=resta (numeroUno,numeroDos);
		 break;
	 case 'c':
		 if (divicion (numeroUno,numeroDos,&resultadoAuxiliar)==0){
          *pVerificadorNumeroB=1;
		 }
		 break;
	 case 'd':
		 resultadoAuxiliar=multiplicacion (numeroUno,numeroDos);
		 break;
     case 'e':
		 resultadoAuxiliar=factorial (numeroUno);
		 *pResultadoFactorialB=factorial(numeroDos);
		 break;

    default:
        verificadorCalculadora=1;
        break;
	 }
	 *pResultado=resultadoAuxiliar;
	 return verificadorCalculadora;
}
/*factorea el numero ingesado*/
int factorial(int numeroAFactorial)
{
int resp;
if (numeroAFactorial==0){
    return 0;
}
if(numeroAFactorial==1){
return 1;}
resp=numeroAFactorial*factorial(numeroAFactorial-1);
return resp;
}

/*muestra el resultado dependiendo de la operacion elejida
 * devuelve un int para verificar si elegio una operacion correcta*/
int mostarResultado(float resultado,char *pLetraIngresadaParaCase4,int resultadoFactorialB, int verificadorNumeroB){
    int verificadorMostrarResultado=0;
    switch(*pLetraIngresadaParaCase4){
	 case 'a':
		 printf("El resultado de A+B es %f\n",resultado);
		 break;
	 case 'b':
		  printf("El resultado de A-B es %f\n",resultado);
		 break;
	 case 'c' :
		 if (verificadorNumeroB==1){
         printf("no es posible dividir por cero\n");
		 }else {
         printf("El resultado de AB es %f\n",resultado);
		 }
		 break;
	 case 'd':
		 printf("El resultado de AB es %f\n",resultado);
		 break;
     case 'e':
         printf( "El resultado de A es  %f\n El resultado de B es  %d\n",resultado,resultadoFactorialB);
		 break;

    default:
        verificadorMostrarResultado=1;
        break;
    }
    return verificadorMostrarResultado;
}



/*ingresa un entero para elejir que operacion hacer
 * muestra que operacion quiere hacer
 * detecta si ingreso un letra o un numero flotante
 * devuelte un entero para verificar si ingreso correctamente
 * puede ingresar la cantidad de intentos a indicar */
int getInt(int *pNumero,
		char *pMensaje,
		char *pMensajeError,
		float *pNumeroA,
		float *pNumeroB,
		int reitentos){
	int verificadorIngreso=0;
	float numeroauxiliar=0;
	do{
	printf(pMensaje);
	fflush(stdin);
	if (scanf("%f",&numeroauxiliar)==0 ){
     printf(pMensajeError);
     printf(" 1. Ingresar 1er operador (A= %f)\n 2. Ingresar 2do operador (B= %f)\n" ,
    		 *pNumeroA,*pNumeroB);
     verificadorIngreso=1;
	} else
	{
    reitentos=-1;
    verificadorIngreso=0;
	*pNumero=numeroauxiliar;
	}
	reitentos--;
	}
    while(reitentos>=0);
	return verificadorIngreso;
}/**

 *\brinf solicita un numero al usuario y lo valida
 *\ param pNumero puntero donde se guarda el numero ingresado
 *\ param pmensaje mensaje a ser mostrado
 *\ param pMensajeErrir mensaje a ser mostrado en caso de error
 *\ return si obtuvo el numero (1) si no (0)
 *
 */
int getFloat(float *pNumero, char *pMensaje, char *pMensajeError,int reitentos){
	int verificadorIngreso=0;
	float numeroauxiliar;
	do{
	printf(pMensaje);
	fflush(stdin);
	if (scanf("%f",&numeroauxiliar)==0){
     printf(pMensajeError);
     verificadorIngreso=1;
	} else
	{
    reitentos=-1;
    verificadorIngreso=0;
	*pNumero=numeroauxiliar;
	}
	reitentos--;
	}
    while(reitentos>=0);
	return verificadorIngreso;
}
/*funcion suma */
float suma (float numeroUno,float numeroDos){
	return numeroUno+numeroDos;
}
/*funcion resta*/
float resta (float numeroUno,float numeroDos){
	return numeroUno-numeroDos;
}
/*funcion divicion
 * devuelte un entero para verifiar si se puede dividir*/
int divicion (float numeroUno,float numeroDos,float *pResultado){
	int verficadorNumeroDosNulo=0;
	if(numeroDos != 0){
		*pResultado= (float)numeroUno/numeroDos;
		verficadorNumeroDosNulo=1;
	}
	return verficadorNumeroDosNulo;
}
/*devuelve una multiplicacion */
float multiplicacion (float numeroUno,float numeroDos){
	return numeroUno*numeroDos;
	}


