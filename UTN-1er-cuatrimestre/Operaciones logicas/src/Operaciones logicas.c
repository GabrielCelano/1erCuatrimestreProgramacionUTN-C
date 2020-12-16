/*
 ============================================================================
 Name        : Operaciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) { // devuelve 1 o 0, no devuelve true o false como en javascript
	int a = 1;
	int b = 0;
	int resultado;

	resultado = a && b;
	printf("Resultado de a intersenccion b es: %d", resultado);

	float vara = 3.14;
	float varb = 5.5;
	int resultadof;

	resultadof = vara < varb;
	printf("\nResultado de la comparacion es: %d", resultadof);
}
