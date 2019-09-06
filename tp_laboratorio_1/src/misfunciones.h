/*
 * misfunciones.h
 *
 *  Created on: 6 sep. 2019
 *      Author: joaquin
 */

#ifndef MISFUNCIONES_H_
#define MISFUNCIONES_H_
int factorial(int numeroAFactorial);
int mostarResultado(float resultado,char *pLetraIngresadaParaCase4,int resultadoFactorialB, int verificadorNumeroB);
float suma (float numeroUno,float numeroDos);
float multiplicacion (float numeroUno,float numeroDos);
float resta (float numeroUno,float numeroDos);
int divicion (float numeroUno,float numeroDos,float *pResultado);
int calculos(float numeroUno,float numeroDos, float *pResultado,int  *pVerificadorNumeroB,int *pResultadoFactorialB,char *pLetraIngresadaParaCase4);
int getInt(int *pNumero, char *pMensaje, char *pMensajeError,float *pNumeroA, float *pNumeroB,int reitentos);
int getFloat(float *pNumero, char *pMensaje, char *pMensajeError,int reitentos);
int listaDeComandos(float *pNumeroA,float *pNumeroB, float *pResultadoSalvado,int *pAuxiliarNuloB, int *pResultadoFactorialBSalvado,int comparador);


#endif /* MISFUNCIONES_H_ */
