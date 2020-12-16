#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"

int menu() {
	int opc;
	printf("\nMenu:\n\n");
	printf(
			"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf(
			"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf(
			"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf(
			"9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
	printf("10. Salir\n");
	__fpurge(stdin);
	utn_getNumero(&opc, "\nIngresar opcion:", "\nIngreso invalido\n", 1, 10, 5);
	return opc;
}

int menuModificar() {
	int opc;
	printf("Menu:\n\n");
	printf("1. Editar nombre: \n");
	printf("2. Editar horas trabajadas: \n");
	printf("3. Editar sueldo: \n");
	printf("4. Salir\n");
	__fpurge(stdin);
	utn_getNumero(&opc, "\nIngresar opcion:", "\nIngreso invalido\n", 1, 4, 5);
	return opc;
}

int employee_setId(Employee *this, int id) {
	int retorno = 0;
	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int employee_getId(Employee *this, int *id) {
	int retorno = 0;
	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int employee_setNombre(Employee *this, char *nombre) {
	int retorno = 0;
	if (this != NULL && nombre != NULL && strlen(nombre) > 1) {
		strcpy(this->nombre, nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_getNombre(Employee *this, char *nombre) {
	int retorno = 0;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int retorno = 0;
	if (this != NULL && horasTrabajadas > 0) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int retorno = 0;
	if (this != NULL && horasTrabajadas != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_setSueldo(Employee *this, int sueldo) {
	int retorno = 0;
	if (this != NULL && sueldo > 0) {
		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}

int employee_getSueldo(Employee *this, int *sueldo) {
	int retorno = 0;
	if (this != NULL && sueldo != NULL) {
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}

Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *salario) {
	Employee *nuevo;
	nuevo = employee_new();
	if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL
			&& salario != NULL && nuevo != NULL) {
		if (!employee_setId(nuevo, atoi(idStr))
				|| !employee_setNombre(nuevo, nombreStr)
				|| !employee_setSueldo(nuevo, atoi(salario))
				|| !employee_setHorasTrabajadas(nuevo,
						atoi(horasTrabajadasStr))) {
			employee_delete(nuevo);
			nuevo = NULL;
		}
	}
	return nuevo;
}

Employee* employee_new() {
	Employee *nuevo;
	nuevo = (Employee*) malloc(sizeof(Employee));
	if (nuevo != NULL) {
		nuevo->id = 0;
		strcpy(nuevo->nombre, " ");
		nuevo->sueldo = 0;
		nuevo->horasTrabajadas = 0;
	} else {
		employee_delete(nuevo);
		nuevo = NULL;
	}
	return nuevo;
}

void employee_delete(Employee *this) {
	if (this != NULL) {
		free(this);
	}
}

int employee_isValidEmp(Employee *emp) {
	int retorno = 0;
	int id;
	int horas;
	int sueldo;
	char nombre[128];

	if (emp != NULL) {
		employee_getId(emp, &id);
		employee_getHorasTrabajadas(emp, &horas);
		employee_getSueldo(emp, &sueldo);
		employee_getNombre(emp, nombre);
		if (id > 0 && horas > 0 && sueldo > 0 && nombre != NULL) {
			retorno = 1;
		}
	}
	return retorno;
}

int printEmployee(Employee *this) {
	int retorno = -1;
	if (this != NULL) {
		printf("%5d %12s %12d %10d\n", this->id, this->nombre,
				this->horasTrabajadas, this->sueldo);
		retorno = 0;
	}

	return retorno;
}

int ordenarPorNombre(void *emp1, void *emp2) {
	int retorno = -1;
	Employee *p1;
	Employee *p2;

	if (emp1 != NULL && emp2 != NULL) {
		p1 = (Employee*) emp1;
		p2 = (Employee*) emp2;

		if (strcmp(p1->nombre, p2->nombre) > 0) {
			retorno = 1;
		} else if (strcmp(p1->nombre, p2->nombre) < 0) {
			retorno = -1;
		} else if (strcmp(p1->nombre, p2->nombre) == 0) {
			retorno = 0;
		}
	}

	return retorno;
}

int employee_getNewId(LinkedList *this) {
	int auxId = 0;
	int flag = 0;
	Employee *auxEmp;
	if (ll_len(this) != 0) {
		for (int i = 0; i < ll_len(this); i++) {
			auxEmp = (Employee*) ll_get(this, i);
			employee_getId(auxEmp, &auxId);
			if (flag == 0) {
				auxId = auxEmp->id;
				flag = 1;
			}
				else if (auxEmp->id == 0){

				}
			else if (auxEmp->id > auxId) {

				auxId = auxEmp->id;
			}
		}
	}
	auxId++;
	return auxId;
}

int ordenarPorSueldo(void* emp1, void* emp2){
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1!=NULL && emp2!=NULL){
         p1 = (Employee*)emp1;
         p2 = (Employee*)emp2;

         if(p1->sueldo > p2->sueldo){
            retorno=1;
         }else if(p1->sueldo < p2->sueldo){
            retorno=-1;
         }else if(p1->sueldo == p2->sueldo){
            retorno=0;
        }
    }

    return retorno;
}

int ordenarPorId(void* emp1, void* emp2){
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1!=NULL && emp2!=NULL){
         p1 = (Employee*)emp1;
         p2 = (Employee*)emp2;

         if(p1->id > p2->id){
            retorno=1;
         }else if(p1->id < p2->id){
            retorno=-1;
         }else if(p1->id == p2->id){
            retorno=0;
        }
    }

    return retorno;
}

int employee_idEmployeeEmpty(LinkedList *pArrayListEmployee, int id){
	Employee *aux;
	int retorno = 0;
		int len;
		if (pArrayListEmployee != NULL) {
			len = ll_len(pArrayListEmployee);
			for (int i = 0; i < len; i++) {
				aux = (Employee*) ll_get(pArrayListEmployee, i);
				if(aux->id == id){
					retorno = -1;
					break;
				}
			}
		}
	return retorno;
}
