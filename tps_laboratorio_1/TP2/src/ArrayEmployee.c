#include "ArrayEmployee.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#define TAMSTRING 51

int initEmployees(Employee *list, int len) { //Inicializo la estructura Employee, guardandole un 1 a cada posicion de isEmpty(1 significa que esta vacio, 0 que esta ocupado)
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int menu() {
	int opc;
	printf("\nMenu:\n\n");
	printf("1. ALTA.\n");
	printf("2. MODIFICAR.\n");
	printf("3. BAJA.\n");
	printf("4. INFORMAR.\n");
	printf("5. Salir\n");
	__fpurge(stdin);
	utn_getNumero(&opc, "\nIngresar opcion:", "\nIngreso invalido\n", 1, 5, 5);
	return opc;
}

int menuModify() {
	int opc;
	printf("\nMenu modificar:\n\n");
	printf("1. Modificar nombre.\n");
	printf("2. Modificar apellido.\n");
	printf("3. Modificar salario.\n");
	printf("4. Modificar sectors.\n");
	printf("5. Salir\n");
	__fpurge(stdin);
	utn_getNumero(&opc, "\nIngresar opcion:", "\nIngreso invalido\n", 1, 5, 5);
	return opc;
}

int menuInformar() {
	int opc;
	printf("\nMenu informes:\n\n");
	printf("1. Listado de empleados.\n");
	printf("2. Total y promedio de los salarios.\n");
	printf("3. Salir\n");
	__fpurge(stdin);
	utn_getNumero(&opc, "\nIngresar opcion:", "\nIngreso invalido\n", 1, 3, 5);
	return opc;
}

int menuOrdenar() {
	int opc;
	printf("\nMenu listado:\n\n");
	printf("1. Ascendente (A-Z).\n");
	printf("2. Descendente (Z-A).\n");
	printf("3. Salir\n");
	__fpurge(stdin);
	utn_getNumero(&opc, "\nIngresar opcion:", "\nIngreso invalido\n", 1, 3, 5);
	return opc;
}

int addEmployee(Employee *list, int len) { //Doy de alta, validando que lo ingresado sean strings, enteros o flotantes.
	int retorno = -1;
	int auxId;
	Employee bufferEmployee;
	auxId = employee_getEmpty(list, len);
	if (list != NULL && auxId >= 0) {
		printf("\n****************Dando de ALTA id: %d****************", auxId);
		if (utn_getNombre(bufferEmployee.name, TAMSTRING, "\nIngresar nombre: ",
				"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
				3) == 0
				&& utn_getNombre(bufferEmployee.lastName, TAMSTRING,
						"\nIngresar apellido: ",
						"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
						3) == 0
				&& utn_getNumeroFlotante(&bufferEmployee.salary,
						"\nIngresar salario: ",
						"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
						1, 9999999, 3) == 0
				&& utn_getNumero(&bufferEmployee.sector, "\nIngresar sector: ",
						"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
						0, 100, 3) == 0) {
			bufferEmployee.id = auxId;
			bufferEmployee.isEmpty = 0;
			list[auxId] = bufferEmployee;
			printf("\n*******************CARGA EXITOSA*******************");
			printEmployee(list, auxId);
			printf("\n***************************************************\n");
			retorno = 0;
		}
	} else {
		printf("\n**********Se supero el limite de cargas**********");
	}
	return retorno;
}

void modifyEmployee(Employee *list, int len) { // Busco por ID, verificando si isEmpty esta vacio u ocupado y pregunto si desea modificar algo.
	int auxId;
	char rta;
	Employee bufferModify;
	auxId = findEmployeeById(list, len);
	if (auxId != -1) {
		do {
			printf("\n\n***************************************************");
			printEmployee(list, auxId);
			switch (menuModify()) {
			case 1:
				if (utn_getNombre(bufferModify.name, TAMSTRING,
						"Ingresar nuevo nombre: ",
						"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
						3) == 0) {
					__fpurge(stdin);
					strcpy(list[auxId].name, bufferModify.name);
				}
				break;
			case 2:
				if (utn_getNombre(bufferModify.lastName, TAMSTRING,
						"Ingresar nuevo apellido: ",
						"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
						3) == 0) {
					__fpurge(stdin);
					strcpy(list[auxId].lastName, bufferModify.lastName);
				}
				break;
			case 3:
				if (utn_getNumeroFlotante(&bufferModify.salary,
						"Ingresar nuevo salario: ",
						"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
						1, 200000, 3) == 0) {
					list[auxId].salary = bufferModify.salary;
				}
				break;
			case 4:
				if (utn_getNumero(&bufferModify.sector,
						"Ingresar nuevo sector: ",
						"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
						0, 100, 3) == 0) {
					list[auxId].sector = bufferModify.sector;
				}
				break;
			case 5:
				printf("\nSeguro desea salir? s/n\n");
				__fpurge(stdin);
				scanf("%c", &rta);
				rta = tolower(rta);
				break;
			}
		} while (!(rta == 's'));
	}
}

int printEmployee(Employee *list, int i) { //Imprimo una sola posicion.
	int retorno = -1;
	printf("\nID %d: %s %s - Salario: $%.2f - Sector: %d", list[i].id,
			list[i].name, list[i].lastName, list[i].salary, list[i].sector);
	retorno = 0;
	return retorno;
}

int removeEmployee(Employee *list, int len) { //Busco por ID, y pregunto si lo desea borrar, dejando esa posicion de isEmpty vacia.
	int retorno = -1;
	char rta;
	int auxId;
	auxId = findEmployeeById(list, len);
	if (auxId != -1) {
		printf("\n***************************************************\n");
		printEmployee(list, auxId);
		do {
			printf("\nSeguro desea borrar al empleado? s/n\n");
			__fpurge(stdin);
			scanf("%c", &rta);
			rta = tolower(rta);
		} while (!(rta == 's' || rta == 'n'));

		switch (rta) {
		case 's':
			list[auxId].isEmpty = 1;
			retorno = 0;
			printf("\n*****************Se borro con exito*****************\n");
			break;
		case 'n':
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int printEmployees(Employee *list, int len) { //Imprimo todas las posiciones.
	int retorno = -1;
	int i;
	for (i = 0; i < len; i++) {
		if (list != NULL && list[i].isEmpty == 0) {
			printEmployee(list, i);
		}
	}
	return retorno;
}

int totalEmployees(Employee *list, int len) { // Realizo calculos.
	int retorno = -1;
	int i;
	int contPromedio = 0;
	int contSalario = 0;
	float acu = 0;
	float total = 0;
	float promedio = 0;

	for (i = 0; i < len; i++) {
		if (list != NULL && list[i].isEmpty == 0) {
			contPromedio++;
			acu = list[i].salary;
			total = total + acu;
		}
	}
	promedio = total / contPromedio;
	for (i = 0; i < len; i++) {
		if (list != NULL && list[i].isEmpty == 0 && list[i].salary > promedio) {
			contSalario++;
		}
	}
	printf(
			"\n***************************************************************\n");
	printf("\nSalario total de todos los empleados es: $%.2f", total);
	printf("\nPromedio total de todos los sueldos es: $%.2f", promedio);
	printf("\nCantidad de empleados que superan el salario promedio es: %d\n",
			contSalario);
	printf(
			"\n***************************************************************\n");
	return retorno;
}

int sortEmployees(Employee *list, int len, int order) { //Ordeno los empleados alfabeticamente por apellido u sector, eligiendo de forma ascendente o descendente.
	int retorno = -1;
	int i;
	int j;
	int auxiliarCmpString;
	Employee buffer;
	if (list != NULL && len > 0 && (order == 1 || order == 0)) {
		for (i = 0; i < len - 1; i++) {
			for (j = i + 1; j < len; j++) {
				auxiliarCmpString = strcmp(list[i].lastName, list[j].lastName);
				if ((auxiliarCmpString < 0 && order == 1)
						|| (auxiliarCmpString > 0 && order == 0)
						|| (auxiliarCmpString == 0
								&& (list[i].sector < list[j].sector
										&& order == 1))
						|| (auxiliarCmpString == 0
								&& (list[i].sector > list[j].sector
										&& order == 0))) {
					buffer = list[i];
					list[i] = list[j];
					list[j] = buffer;
				}
			}
		}
		printf("\n                   LISTA DE EMPLEADOS\n\n");
		printf("\n**********************************************************");
		printEmployees(list, len);
		printf(
				"\n**********************************************************\n");
		retorno = 0;
	}
	return retorno;
}

int employee_getEmpty(Employee *list, int len) {
	int retorno = -1;
	int i;
	if (list != NULL && len >= 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int employee_flagAlta(Employee *list, int len) {
	int retorno = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int findEmployeeById(Employee *list, int len) {
	int retorno = -1;
	int auxId;
	printf("\n****************LISTA DE EMPLEADOS****************\n");
	printEmployees(list, len);
	if (utn_getNumero(&auxId, "\nIngresar id: ",
			"\n**********Ingreso invalido**********n", 0, 1000, 5) == 0) {
		if (list[auxId].isEmpty == 0) {
			retorno = auxId;
		} else {
			printf("\nNo existe empleado.\n");
		}
	}
	return retorno;
}
