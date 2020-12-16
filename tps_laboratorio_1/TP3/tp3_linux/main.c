/*
 ============================================================================
 Name        : Trabajo Practico Nro 3
 Author      : Gabriel Celano 1ro 'E'
 Version     : 1.0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "Controller.h"
/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	char rta = 'n';
	int flagLoadTxt = -1;
	LinkedList *listaEmpleados = ll_newLinkedList();
	printf("\n***********Trabajo Practico Nro 3***********\n");
	do {
		switch (menu()) {
		case 1:
			if (controller_loadFromText("data.csv", listaEmpleados) == 0) {
				flagLoadTxt = 0;
				printf("\nLos datos fueron cargados correctamente.\n");
			} else {
				printf("\nError al cargar archivos.\n");
			}
			break;
		case 2:
			if (controller_loadFromBinary("data.bin", listaEmpleados) == 0) {
				printf("\nLos datos fueron cargados correctamente.\n");
			} else {
				printf("Error al cargar archivos.\n");
			}
			break;
		case 3:
			if(flagLoadTxt == 0){
			if (controller_addEmployee(listaEmpleados) == 0) {
			} else {
				printf("\nError al ingresar el empleado.\n");
			}
			}else{
				printf("\nNo hay empleados cargados que mostrar, agregue o bien cargue desde el archivo.\n");
			}
			break;
		case 4:
			if(flagLoadTxt == 0){
			if (controller_editEmployee(listaEmpleados) == 0) {
				printf("\nEmpleado modificado con exito.\n");
			}
			}else{
				printf("\nNo hay empleados cargados que mostrar, agregue o bien cargue desde el archivo.\n");
			}
			break;
		case 5:
			if (!ll_isEmpty(listaEmpleados)) {
				if (controller_removeEmployee(listaEmpleados) == 0) {
					printf("\nEl empleado fue dado de baja con exito.\n");
				} else {
					printf("\nNo se pudo dar de baja al empleado.\n");
				}
			} else {
				printf("\nNo hay empleados cargados que mostrar, agregue o bien cargue desde el archivo.\n");
			}
			break;
		case 6:
			if (!ll_isEmpty(listaEmpleados)) {
				controller_ListEmployee(listaEmpleados);
			} else {
				printf(
						"\nNo hay empleados cargados que mostrar, agregue o bien cargue desde el archivo\n");
			}
			break;
		case 7:
			if (!ll_isEmpty(listaEmpleados)) {
				if (controller_sortEmployee(listaEmpleados) == 0) {
					printf("\nSe ordeno la lista de empleados con exito.\n");
				} else {
					printf("\nNo se pudo ordenar la lista de empleados.\n");
				}
			} else {
				printf(
						"\nNo hay empleados cargados que ordenar, agregue o bien cargue desde el archivo.\n");
			}
			break;
		case 8:
			if (!ll_isEmpty(listaEmpleados)) {
				if (controller_saveAsText("data.csv", listaEmpleados) == 0) {
					printf(
							"\nDatos de empleados guardados en el archivo TXT con exito.\n");
				} else {
					printf("\nNo se pudo guardar los datos en el archivo.\n");
				}
			} else {
				printf("\nNo hay nada que guardar.\n");
			}
			break;
		case 9:
			if (!ll_isEmpty(listaEmpleados)) {
				if (controller_saveAsBinary("data.bin", listaEmpleados) == 0) {
					printf(
							"\nDatos de empleados guardados en el archivo BIN con exito.\n");
				} else {
					printf("\nNo se pudo guardar los datos en el archivo.\n");
				}
			} else {
				printf("\nNo hay nada que guardar.\n");
			}

			break;
		case 10:
			printf("Seguro quiere salir del programa? s/n\n"); //Salir del programa
			__fpurge(stdin);
			scanf("%c", &rta);
			rta = tolower(rta);
			break;
		}
	} while (rta != 's');
	return 0;
}

