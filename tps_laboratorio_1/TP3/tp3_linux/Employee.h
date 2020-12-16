#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct {
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *salario);
void employee_delete(Employee *this);

int employee_setId(Employee *this, int id);
int employee_getId(Employee *this, int *id);

int employee_setNombre(Employee *this, char *nombre);
int employee_getNombre(Employee *this, char *nombre);

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas);

int employee_setSueldo(Employee *this, int sueldo);
int employee_getSueldo(Employee *this, int *sueldo);

int employee_isValidEmp(Employee *emp);

int menu();
int menuModificar();
int printEmployee(Employee *this);
int employee_getNewId(LinkedList* this);
int ordenarPorNombre(void *emp1, void *emp2);
int ordenarPorSueldo(void* emp1, void* emp2);
int employee_idEmployeeEmpty(LinkedList *pArrayListEmployee, int id);
int ordenarPorId(void* emp1, void* emp2);


#endif // employee_H_INCLUDED
