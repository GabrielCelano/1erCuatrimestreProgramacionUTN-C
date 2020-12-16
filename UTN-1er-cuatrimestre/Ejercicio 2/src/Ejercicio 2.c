/*
 ============================================================================
 Name        : 123123.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numero = 0;
	int acu = 0;
	char respuesta = 'n';

	do {
		printf("Ingrese un numero");
		scanf("%d", &numero);
		acu = acu + numero;

		printf("Quiere continuar ingresando? s/n");
		__fpurge(stdin);
		scanf("%c", &respuesta);

	} while(respuesta == 's');

	printf("\nLa suma total de todos los numeros ingresados es: %d", acu);

}
