/*
 ============================================================================
 Name        : NUEvo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num1;
	int num2;
	int resultado;
	char letra;
	char letra2;

	printf("Ingrese una letra: ");
	//fflush(stdin); en windows
	__fpurge(stdin); // en linux
	scanf("%c", &letra);

	printf("Ingrese otra letra: ");
	//fflush(stdin);
	__fpurge(stdin);
	scanf("%c", &letra2);

	printf("\n Ingrese un valor para num1");
	scanf("%d", &num1);

	printf("\n Ingrese un valor para num2");
	scanf("%d", &num2);

	printf("\n Usted ingreso el numero: %d y el numero: %d", num1, num2);
	resultado = num1 + num2;
	printf("\n El resutlado de la suma es %d", resultado);
}
