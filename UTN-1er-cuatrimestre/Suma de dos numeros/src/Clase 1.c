/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	setbuf(stdout, NULL);

	int numero;
	int numero2;
	int resultado;

	printf("\n Ingrese un numero: ");
	scanf("%d", &numero);

	printf("\n Ingrese otro numero: ");
	scanf("%d", &numero2);

	resultado = numero + numero2;
	printf("\n El resultado de la suma de los dos numeros es: %d", resultado);

	return 0;

}
