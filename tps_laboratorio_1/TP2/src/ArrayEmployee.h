#ifndef AMB_H_
#define ABM_H_


struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

#endif /* ABM_H_ */
/**
 * @brief Menu principal
 * @return retorno la opcion del menu
 */
int menu();

/**
 * @brief Menu modificar
 * @return retorno la opcion del menu
 */
int menuModify();

/**
 * @brief menu modificar
 * @return retorno la opcion del menu
 */
int menuInformar();

/**
 * @brief menu ordenar
 * @return retorno la opcion del menu
 */
int menuOrdenar();

/**
 * @brief Inicializo todas las posiciones de isEmpty en 1(1 si esta vacia, o 0 si esta ocupada)
 * @param list Employee*
 * @param len int
 * @return int retorno -1 si es un Error/ 0 si esta todo Ok
 */
int initEmployees(Employee *list, int len);

/**
 * @brief Ingreso valores a la primer posicion vacia de isEmpty
 * @param list Employee*
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param salary float
 * @param sector int
 * @return int retorno -1 si es un Error/ 0 si esta todo Ok
 */
int addEmployee(Employee *list, int len);

/**
 * @brief Busca un empleado por id, y dandole opciones si desea modificar algo
 * @param list Employee*
 * @param len int
 * @return int retorno -1 si es un Error/ 0 si esta todo Ok
 */
void modifyEmployee(Employee *list, int len);

/**
 * @brief Elimina de manera logica (isEmpty en 1), ingresando como parametro su id
 * @param list Employee*
 * @param len int
 * @return int retorno -1 si es un Error/ 0 si esta todo Ok
 */
int removeEmployee(Employee *list, int len);

/**
 * @brief Muestro en pantalla los datos de una posicion de Employee* list(isEmpty 0)
 * @param list Employee*
 * @param i int
 * @return int retorno -1 si es un Error/ 0 si esta todo Ok
 */
int printEmployee(Employee *list, int i);

/**
 * @brief Muestro en pantalla los datos de todas las posiciones de Employee* list(isEmpty 0)
 * @param list
 * @param len
 * @return int retorno -1 si es un Error/ 0 si esta todo Ok
 */
int printEmployees(Employee *list, int len);

/**
 * @brief Realiza la suma total de todas las posiciones de salary, y saca un promedio
 * @param list Employee*
 * @param len int
 * @return  int retorno -1 si es un Error/ 0 si esta todo Ok
 */
int totalEmployees(Employee *list, int len);


/**
 * @brief Ordena el array Employee por apellido y sector de forma ascendente o descendente
 * @param list Employee*
 * @param len int
 * @param order int
 * @return int retorno -1 si es un Error/ 0 si esta todo Ok
 */
int sortEmployees(Employee *list, int len, int order);

/**
 * @brief Busco el primer array vacio
 * @param list Employee*
 * @param len int
 * @return int retorna la primer posicion vacia
 */
int employee_getEmpty(Employee *list, int len);

/**
 * @brief Busco un empleado por id
 * @param list Employee*
 * @param len int
 * @return Retorno el id del empelado
 */
int findEmployeeById(Employee *list, int len);

/**
 * @brief Pregunto si todos los arrays estan vacios
 * @param list Employee*
 * @param len int
 * @return Retorno -1 si al meno uno esta ocupado o 0 si estan todos vacios
 */
int employee_flagAlta(Employee *list, int len);
