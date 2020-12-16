/*
 * operaciones.c
 *
 *  Created on: 8 sep. 2020
 *      Author: Gabriel
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "operaciones.h"

char pedirOpcion(char opcion)
{
	while(opcion!='a'&&opcion!='b'&&opcion!='c'&&opcion!='d'&&opcion!='e'){ //Valido si la operacion ingresada es correcta
		printf("\n*****Opcion ingresada incorrecta****\n");
		printf("\nVolver a ingresar: \n");
		__fpurge(stdin);
		scanf("%c", &opcion);
	}
	return opcion;
}

double pedirNumero(double numIngresado){//Guarda el numero ingresado en el operador A o en el B
	double numero;
	__fpurge(stdin);
	scanf("%lf", &numero);
	return numero;
}

double suma(double numIngresado1, double numIngresado2){//Realiza la suma de los operadores
	double total;
	total=numIngresado1+numIngresado2;
	return total;
}

double rest(double numIngresado1, double numIngresado2){//Realiza la resta de los operadores
	double  total;
	total=numIngresado1-numIngresado2;
	return total;
}

double divi(double numIngresado1, double numIngresado2){//Realiza la division de los operadores
	double total;
	total=numIngresado1/numIngresado2;
	return total;
}

double mult(double numIngresado1, double numIngresado2){//Realiza la multiplicacion de los operadores
	double total;
	total=numIngresado1*numIngresado2;
	return total;
}

double fact1(double numIngresado1){//Realizo el factorial de numIngresado1(A)
  double totalFactorial=1;
  if(numIngresado1==1){
      return 1;
  }
  for(int cont=1;cont<=numIngresado1;cont++){
	  totalFactorial=totalFactorial*cont;
  }
  return totalFactorial;
}

double fact2(double numIngresado2){//Realizo el factorial de numIngresado2(B)
  double totalFactorial=1;
  if(numIngresado2==1){
      return 1;
  }
  for(int cont=1;cont<=numIngresado2;cont++){
	  totalFactorial=totalFactorial*cont;
  }
  return totalFactorial;
}
