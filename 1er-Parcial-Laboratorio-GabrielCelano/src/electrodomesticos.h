#ifndef ELECTRODOMESTICOS_H_
#define ELECTRODOMESTICOS_H_

#define TAM_MARCAS 5

struct {
	int id; //EMPIEZA EN 1000
	char descripcion[20];
}typedef Marca;

struct {
	int id;
	int serie;
	int idMarca;
	int modelo;
	int isEmpty;
}typedef Electrodomestico;

#endif /* ELECTRODOMESTICOS_H_ */

//INICIALIZACION
/**
 * @brief Hardcodeo las marcas
 * @param listM Marca*
 * @param len int
 */
void hardcodearMarcas(Marca *listaM, int len);

/**
 * @brief Inicializo las posiciones de isEmpty
 * @param listE Electrodomestico*
 * @param len int
 */
void iniElectrodomestico(Electrodomestico *listE, int len);

//VALIDACIONES
/**
 * @brief Busco la primer posicion vacia
 * @param listE Electrodomestico*
 * @param limite int
 * @return Devuelvo la primer posicion vacia
 */
int electrodomestico_getEmptyIndex(Electrodomestico *listE, int limite);

/**
 * @brief Doy de alta un electrodomestico
 * @param listE Electrodomestico*
 * @param listM Marca*
 * @param limite int
 * @param indice int
 * @param id int
 * @return Devuelvo 0 si el alta fue un exito o -1 si no lo fue
 */
int altaElectrodomestico(Electrodomestico *listE, Marca *listM, int limite,
		int indice, int *id);

/**
 * @brief Busco la posicion del id ingresado
 * @param listE Electrodomestico*
 * @param limite int
 * @param valorBuscado int
 * @return Devuelvo la posicion del if buscado
 */
int electrodomesticoBuscarID(Electrodomestico *listE, int limite,
		int valorBuscado);

/**
 * @brief Doy de baja el id ingresado
 * @param listE Electrodomestico*
 * @param listM Marca*
 * @param len int
 * @param id int
 */
void bajaElectrodomestico(Electrodomestico *listE, Marca *listM, int len, int id);

/**
 * @brief Modifico el id ingresado
 * @param listE Electrodomestico*
 * @param listM Marca*
 * @param len int
 * @param posicion int
 */
void modificarElectrodomestico(Electrodomestico *listE, Marca *listM, int len,
		int posicion);

/**
 * @brief Verifico si hay todavia espacios ocupados o si estan todos vacios
 * @param listE Electrodomestico
 * @param limite int
 * @return Devuelo 0 si hay espacios ocupados o -1 si estan todos vacios
 */
int electrodomestico_flagAlta(Electrodomestico *listE, int limite);

//PRINTS
/**
 * @brief Muestro el electrodomestico de la posicion ingresada
 * @param listE Electrodomestico
 * @param listM Marca
 * @param posicion int
 * @param len int
 */
void printElectrodomestico(Electrodomestico *listE, Marca *listM, int posicion,
		int len);

/**
 * @brief Muestro todos los electrodomesticos
 * @param listE Electrodomestico*
 * @param listM Marca*
 * @param len int
 */
void printElectrodomesticos(Electrodomestico *listE, Marca *listM, int len);

/**
 * @brief Ordeno por modelo y serie
 * @param listE Electrodomestico*
 * @param listM Marca*
 * @param len int
 * @param order int
 */
void listarElectrodomesticosEnOrden(Electrodomestico *listE, Marca *listM, int len,
		int order);

/**
 * @brief Muestro la marca de la posicion ingresada
 * @param listM Marca*
 * @param id int
 */
void listarMarca(Marca *listM, int id);

/**
 * @brief Muestro todas las marcas
 * @param listM Marca*
 * @param len int
 */
void listarMarcas(Marca *listM, int len);
