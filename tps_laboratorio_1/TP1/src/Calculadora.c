/*
 ============================================================================
 Name        : Calculadora2.c
 Author      : Gabriel Celano
 Division    : 1ro "E"
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "operaciones.h"


int main(void) {

	double numIngresado1=0;
	double numIngresado2=0;
	double resuSuma;
	double resuRest;
	double resuDivi;
	double resuMult;
	double resuFact1;
	double resuFact2;

	char operacion;
	int flagA=0;
	int flagB=0;
	int flagC=0;
	char rta;

	do{
		printf("\n\n----------Menu Calculadora----------\n\n");  //INGRESO LA OPERACION DESEADA
	    printf("\nA) Ingresar el 1er operando: (A=%.2f)",numIngresado1);
		printf("\nB) Ingresar el 2do operando: (B=%.2f)",numIngresado2);
		printf("\nC) Calcular todas las operaciones.");
		printf("\nD) Informar resultados.");
	    printf("\nE) Salir.");
	    printf("\nIngresar operacion deseada: \n");
	    __fpurge(stdin);
	    scanf("%c", &operacion);
	    operacion=tolower(operacion);
	    operacion = pedirOpcion(operacion);


	    switch(operacion){
	    case 'a': //OPERACION A
	    	printf("\nIngresar 1er operando: ");
	    	numIngresado1=pedirNumero(numIngresado1);
	    	flagC=0;
	    	flagA=1;
	    	break;
	    case 'b': //OPERACION B: si se ingreso la operacion a, se puede ingresar la operacion b
	        if(flagA==1){
	    	printf("\nIngresar 2do operando: ");
	    	numIngresado2=pedirNumero(numIngresado2);
	        flagC=0;
	    	flagB=1;
	    	}
	    	else{
	        printf("\n*****Primero debe ingresar el primer operando*****\n");
	    	}
		    break;
	    case 'c': //OPERACION C: si se ingresaron los dos operando, se puede calcular
	    	if(flagA==0||flagB==0){
	        printf("\n*****Primero debe ingresar los operando*****\n");
	    	}
	    	else if(flagA==1&&flagB==1){
	    	resuSuma=suma(numIngresado1,numIngresado2);
	        resuRest=rest(numIngresado1,numIngresado2);
	    	resuDivi=divi(numIngresado1,numIngresado2);
	    	resuMult=mult(numIngresado1,numIngresado2);
	    	resuFact1=fact1(numIngresado1);
	    	resuFact2=fact2(numIngresado2);
	    	printf("\n*****Los calculos se resolvieron con exito****\n");
	        flagC=1;
	    	}
	    	break;
	    case 'd': //OPERACION D: si se ingresaron los dos operando y ademas se realizo el calculo, se puede mostrar los resultados
	    	if(flagA==0||flagB==0){
	        printf("\n*****Primero debe ingresar los operando*****\n");
	    	}
	    	else if(flagA==1&&flagB==1&&flagC==0){
	        printf("\n*****Primero debe realizar los calculos*****\n");
	        }
	    	else{
	        printf("\nEl resultado de A=%.2f + B=%.2f es: %.2f\n",numIngresado1,numIngresado2,resuSuma);
	        printf("\nEl resultado de A=%.2f - B=%.2f es: %.2f\n",numIngresado1,numIngresado2,resuRest);
	        if(numIngresado2==0){
	        printf("\nEl resultado de A=%.2f / B=%.2f es: *No es posible dividir por cero* \n",numIngresado1,numIngresado2);//Si numIngresado2 es 0 no se puede divir
	        }
	        else{
	        printf("\nEl resultado de A=%.2f / B=%.2f es: %.2f\n",numIngresado1,numIngresado2,resuDivi);
	        }
	        printf("\nEl resultado de A=%.2f * B=%.2f es: %.2f\n",numIngresado1,numIngresado2,resuMult);
	        printf("\nEl factorial de A=%.2f es: %.2f \n",numIngresado1,resuFact1);
	        printf("\nEl factorial de B=%.2f es: %.2f \n ",numIngresado2,resuFact2);
	    	}
	    	break;
	    case 'e': //OPERACION E: pregunto si quiero salir del programa
	    	printf("\nSeguro desea salir? (s/n): ");
	    	__fpurge(stdin);
	    	scanf("%c", &rta);
	    	break;
	    }
	}while(!(rta =='s'||rta =='S'));
}

