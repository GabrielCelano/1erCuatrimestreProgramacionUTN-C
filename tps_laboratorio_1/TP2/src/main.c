/*
 ============================================================================
 Name        : TP2.c
 Author      : Gabriel Celano 1ro 'E'
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployee.h"
#include "utn.h"
#define TAM 1000

// MAIN
int main(void) {
	Employee arrayEmployees[TAM];
	char rta = 'n';
	char rtaInformes = 'n';

	initEmployees(arrayEmployees, TAM); //Inicializo todas las posiciones de isEmpty en 1

	printf("**********'Trabajo practico N2: ABM'**********\n");
	do {
		switch (menu()) {
		case 1:
			addEmployee(arrayEmployees, TAM);
			break;
		case 2:
			if (employee_flagAlta(arrayEmployees, TAM) == 0) {
				modifyEmployee(arrayEmployees, TAM);
			} else {
				printf("\nTodavia no hay empleados dados de alta.\n");
			}
			break;
		case 3:
			if (employee_flagAlta(arrayEmployees, TAM) == 0) {
				removeEmployee(arrayEmployees, TAM);
			} else {
				printf("\nTodavia no hay empleados dados de alta.\n");
			}
			break;
		case 4:
			if (employee_flagAlta(arrayEmployees, TAM) == 0) {
				do {
					switch (menuInformar()) {
					case 1:
						switch (menuOrdenar()) {
						case 1:
							sortEmployees(arrayEmployees, TAM, 0);
							break;
						case 2:
							sortEmployees(arrayEmployees, TAM, 1);
							break;
						case 3:
							printf("Seguro quiere salir de listado? s/n\n"); //Salir del programa
							__fpurge(stdin);
							scanf("%c", &rtaInformes);
							rtaInformes = tolower(rtaInformes);
							break;
						}
						break;
					case 2:
						totalEmployees(arrayEmployees, TAM);
						break;
					case 3:
						printf("Seguro quiere salir de informes? s/n\n"); //Salir del programa
						__fpurge(stdin);
						scanf("%c", &rtaInformes);
						rtaInformes = tolower(rtaInformes);
						break;
					}
				} while (!(rtaInformes == 's'));
			} else {
				printf("\nTodavia no hay empleados dados de alta.\n");
			}
			break;
		case 5:
			printf("Seguro quiere salir del programa? s/n\n"); //Salir del programa
			__fpurge(stdin);
			scanf("%c", &rta);
			rta = tolower(rta);
			break;
		}
	} while (!(rta == 's'));
}
