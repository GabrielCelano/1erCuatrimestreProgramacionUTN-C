#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	FILE *arch;
	int retorno = -1;
	if (path != NULL && pArrayListEmployee != NULL) {
		arch = fopen(path, "r");
		if (arch != NULL) {
			parser_EmployeeFromText(arch, pArrayListEmployee);
			fclose(arch);
			retorno = 0;
		} else {
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *arch;
	int retorno = -1;

	if (path != NULL && pArrayListEmployee != NULL) {
		arch = fopen(path, "rb");
		if (arch != NULL) {
			parser_EmployeeFromBinary(arch, pArrayListEmployee);
			fclose(arch);
			retorno = 0;
		} else {
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int retorno = 0;
	int auxSueldo;
	int auxId;
	int auxHoras;
	int opcion;
	char auxNombre[128];
	Employee *nuevo;
	if (pArrayListEmployee != NULL) {
		if (utn_getNumero(&opcion,
				"\n1)Carga manual (id ingresada por usuario).\n2)Carga automatica (ultimo id sin cargar).\nIngresar opcion:",
				"\nIngreso invalido.", 1, 2, 5) == 0) {
			switch (opcion) {
			case 1:
				utn_getNumero(&auxId, "\nIngresar id del empleado: ",
						"\nIngreso invalido.", 1, 999999, 5);
				if (employee_idEmployeeEmpty(pArrayListEmployee, auxId) == 0) {
					utn_getNombre(auxNombre, 50,
							"\nIngresar nombre del empleado:",
							"\nIngreso invalido.", 5);
					utn_getNumero(&auxHoras, "\nIngresar horas trabajadas: ",
							"\nIngreso invalido.", 0, 720, 5);
					utn_getNumero(&auxSueldo, "\nIngresar sueldo del empleado:",
							"\nIngreso invalido.", 1, 999999, 5);
					nuevo = employee_new();
					if (nuevo != NULL) {
						if (employee_setId(nuevo, auxId)
								&& employee_setNombre(nuevo, auxNombre)
								&& employee_setHorasTrabajadas(nuevo, auxHoras)
								&& employee_setSueldo(nuevo, auxSueldo)) {
							ll_add(pArrayListEmployee, nuevo);
							printf("\nSe dio de alta correctamente.\n");
							retorno = 0;
						}
					}
				} else {
					printf("\nId EXISTENTE, cargar con otro id.\n");
				}
				break;
			case 2:
				auxId = employee_getNewId(pArrayListEmployee);
				printf("\nId: %d", auxId);
				utn_getNombre(auxNombre, 50, "\nIngresar nombre del empleado:",
						"\nIngreso invalido.", 5);
				utn_getNumero(&auxHoras, "\nIngresar horas trabajadas: ",
						"\nIngreso invalido.", 0, 720, 5);
				utn_getNumero(&auxSueldo, "\nIngresar sueldo del empleado:",
						"\nIngreso invalido.", 1, 999999, 5);
				nuevo = employee_new();
				if (nuevo != NULL) {
					if (employee_setId(nuevo, auxId)
							&& employee_setNombre(nuevo, auxNombre)
							&& employee_setHorasTrabajadas(nuevo, auxHoras)
							&& employee_setSueldo(nuevo, auxSueldo)) {
						ll_add(pArrayListEmployee, nuevo);
						printf("\nSe dio de alta correctamente.\n");
						retorno = 0;
					}
				}
				break;
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int len;
	int auxSueldo;
	int auxId;
	int aux;
	int auxHoras;
	char auxNombre[128];
	char rta = 'n';
	Employee *nuevo;
	if (pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		utn_getNumero(&auxId,
				"\nIngresar ID del empleado que desea modificar: ",
				"\nIngreso invalido.", 1, 999999, 5);
		for (int i = 0; i < len; i++) {
			nuevo = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(nuevo, &aux);
			if (auxId == aux) {
				do {
					switch (menuModificar()) {
					case 1:
						utn_getNombre(auxNombre, 50,
								"\nIngresar nuevo nombre del empleado: ",
								"\nIngreso invalido.", 5);
						if (employee_setNombre(nuevo, auxNombre)) {
							retorno = 0;
						}
						break;
					case 2:
						utn_getNumero(&auxHoras,
								"\nIngresar nuevas horas tabajadas: ",
								"\nIngreso invalido.", 0, 720, 5);
						if (employee_setHorasTrabajadas(nuevo, auxHoras)) {
							retorno = 0;
						}
						break;
					case 3:
						utn_getNumero(&auxSueldo, "\nIngresar nuevo sueldo: ",
								"\nIngreso invalido.", 1, 999999, 5);
						if (employee_setSueldo(nuevo, auxSueldo)) {
							retorno = 0;
						}
						break;
					case 4:
						printf("Seguro quiere salir? s/n\n");
						__fpurge(stdin);
						scanf("%c", &rta);
						rta = tolower(rta);
						break;
					}
				} while (rta != 's');
			}
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int len;
	int idIng;
	int i;
	int idAux;
	Employee *this;

	if (pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		utn_getNumero(&idIng,
				"\nIngresar ID del empleado que desea dar de baja: ",
				"\nIngreso invalido.", 1, 999999, 5);
		for (i = 0; i < len; i++) {
			this = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(this, &idAux);
			if (idAux == idIng) {
				if (preguntarSiEstaSeguro(
						"\nSeguro que desea dar de baja a este empleado?s/n: ",
						"Error ing s/n") == 's') {
					ll_remove(pArrayListEmployee, i);
					retorno = 0;
					break;
				} else {
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	Employee *aux;
	int retorno = -1;
	int len;
	if (pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		printf("\n   Id       Nombre        Horas      Sueldo \n");
		for (int i = 0; i < len; i++) {
			aux = (Employee*) ll_get(pArrayListEmployee, i);
			printEmployee(aux);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int orden;
	int opcion;
	if (utn_getNumero(&opcion,
			"\n1)Ordenar por id.\n2)Ordenar por nombre.\n3)Ordenar por sueldo.\nIngresar opcion:",
			"Ingreso invalido.", 1, 3, 5) == 0) {
		if (pArrayListEmployee != NULL) {
			switch (opcion) {
			case 1:
				if (utn_getNumero(&orden,
						"\n1)Ordenar de forma ascendente.\n2)Ordenar de forma descendente.\nIngresar opcion:",
						"\nIngreso invalido", 1, 2, 5) == 0) {
					if (orden == 2) {
						orden = 0;
					}
					ll_sort(pArrayListEmployee, ordenarPorId, orden);
					retorno = 0;
				}
				break;
			case 2:
				if (utn_getNumero(&orden,
						"\n1)Ordenar de forma ascendente. (A-Z)\n2)Ordenar de forma descendente. (Z-A)\nIngresar opcion:",
						"\nIngreso invalido", 1, 2, 5) == 0) {
					if (orden == 2) {
						orden = 0;
					}
					ll_sort(pArrayListEmployee, ordenarPorNombre, orden);
					retorno = 0;
				}
				break;
			case 3:
				if (utn_getNumero(&orden,
						"\n1)Ordenar de forma ascendente.\n2)Ordenar de forma descendente.\nIngresar opcion:",
						"\nIngreso invalido", 1, 2, 5) == 0) {
					if (orden == 2) {
						orden = 0;
					}
					ll_sort(pArrayListEmployee, ordenarPorSueldo, orden);
					retorno = 0;
				}
				break;
			}
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	FILE *arch;
	Employee *emp;
	int len;
	int id;
	int sueldo;
	int horas;
	int retorno = -1;
	int i;
	char nombre[50];

	if (path != NULL && pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		arch = fopen(path, "w");
		if (arch != NULL) {
			for (i = 0; i < len; i++) {
				emp = (Employee*) ll_get(pArrayListEmployee, i);
				employee_getId(emp, &id);
				employee_getNombre(emp, nombre);
				employee_getHorasTrabajadas(emp, &horas);
				employee_getSueldo(emp, &sueldo);
				fprintf(arch, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
			}
			fclose(arch);
			if (i == len) {
				retorno = 0;
			}
		} else {
			retorno = -1;
		}

	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *arch;
	int retorno = -1;
	int i;
	int len = ll_len(pArrayListEmployee);
	Employee *emp;
	if (path != NULL && pArrayListEmployee != NULL) {
		arch = fopen(path, "wb");
		if (arch != NULL) {
			for (i = 0; i < len; i++) {
				emp = ll_get(pArrayListEmployee, i);
				if (emp != NULL)
					fwrite(emp, sizeof(Employee), 1, arch);
			}
			if (i == len) {
				retorno = 0;
				fclose(arch);
			} else {
				retorno = -1;
			}
		}
	}

	return retorno;
}

