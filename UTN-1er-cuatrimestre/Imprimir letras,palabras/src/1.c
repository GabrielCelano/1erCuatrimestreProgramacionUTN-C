/*
 ============================================================================
 Name        : NUevo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

		char nombre2[20];
		char letra = 'A';
		char nombre[20]="Juan"; //tengo que asignarle la cantidad de bits que necesito para formar el nombre

		printf("Letra tiene el valor = %c", letra);
		printf("\n Nombre tiene el valor = %s", nombre);

		printf("\nIngrese un nombre");
		scanf("%s", nombre2); // en este caso no poner '&'
		printf("El nombre ingresado es: %s", nombre2);

		return 0;
}
