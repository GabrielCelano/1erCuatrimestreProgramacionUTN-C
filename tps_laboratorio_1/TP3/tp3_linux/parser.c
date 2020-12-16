#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	char buffer[4][30];
	int cant, retorno = 0;
	Employee *bufferEmployee;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		while (!feof(pFile)) {
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0],
					buffer[1], buffer[2], buffer[3]);
			bufferEmployee = employee_newParametros(buffer[0], buffer[1],
					buffer[2], buffer[3]);
			if (bufferEmployee != NULL && employee_isValidEmp(bufferEmployee)) {
				ll_add(pArrayListEmployee, bufferEmployee);
				retorno = 1;
			}
			if (cant < 4) {
				if (feof(pFile)) {
					break;
				} else {
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int cant = 0;
	Employee *nuevo;
	if (pFile != NULL && pArrayListEmployee != NULL) {
		while (!feof(pFile)) {
			nuevo = employee_new();
			cant = fread(nuevo, sizeof(Employee), 1, pFile);
			if (nuevo != NULL) {
				if (employee_isValidEmp(nuevo) == 0) {
					ll_add(pArrayListEmployee, nuevo);
					retorno = 0;
				} else {
					employee_delete(nuevo);
				}
			}
			if (cant < 1) {
				if (feof(pFile)) {
					break;
				} else {
					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}
