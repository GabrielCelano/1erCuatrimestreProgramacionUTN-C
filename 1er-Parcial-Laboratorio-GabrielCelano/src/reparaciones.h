#ifndef REPARACIONES_H_
#define REPARACIONES_H_
#include "electrodomesticos.h"

struct {
	int dia;
	int mes;
	int anio;
}typedef Fecha;

struct {
	int id; //EMPIEZA EN 20000
	char descripcion[25];
	int precio;
}typedef Servicio;

struct {
	int id;
	char nombre[20];
	char apellido[20];
}typedef Cliente;

struct {
	int id;
	int serie;
	int idServicio;
	Cliente eCliente;
	Fecha eFecha;
	int isEmpty;
}typedef Reparacion;

#endif /* REPARACIONES_H_ */


//INICIALIZACION
/**
 * @brief Inicializo el array
 * @param listR Reparacion*
 * @param len int
 */
void iniReparacion(Reparacion *listR, int len);
//HARCODEO
/**
 * @brief Harcodeo los clientes
 * @param listaC Cliente*
 * @param len int
 */
void hardcodearClientes(Cliente *listaC, int len);

/**
 * @brief Harcodeo los servicios
 * @param listaS Servicio*
 * @param len int
 */
void hardcodearServicios(Servicio *listaS, int len);

//PRINTS
/**
 * @brief Muestro la reparacion cargada con exito
 * @param listR Reparacion*
 * @param listS Servicio*
 * @param listC Cliente*
 * @param listE Electrodomestico*
 * @param posicion int
 * @param len int
 */
void printReparacion(Reparacion *listR, Servicio *listS, Cliente *listC, Electrodomestico *listE
		,int posicion, int len);

/**
 * @brief Muestro el servicio de la posicion i
 * @param listS Servicio*
 * @param i int
 */
void listarServicio(Servicio *listS, int i);

/**
 * @brief Muestro todos los servicios
 * @param listS Servicio*
 * @param len int
 */
void listarServicios(Servicio *listS, int len);

/**
 * @brief Muestro todas las altas de reparaciones
 * @param listE Electrodomestico*
 * @param listR Reparacion*
 * @param listS Servicio*
 * @param listC Cliente*
 * @param len int
 */
void listarReparaciones(Electrodomestico *listE, Reparacion *listR,
		Servicio *listS, Cliente *listC, int len);

/**
 * @brief Muestro el alta reparacion de la posicion solicitada
 * @param listE Electrodomestico*
 * @param listR Reparacion*
 * @param listS Servicio*
 * @param listC CLiente*
 * @param posicion len
 * @param len len
 */
void listaReparacion(Electrodomestico *listE, Reparacion *listR, Servicio *listS,
		Cliente *listC, int posicion, int len);

/**
 * @brief Muestro todos los clientes
 * @param listC Cliente*
 * @param len int
 */
void listarClientes(Cliente *listC, int len);

/**
 * @brief Muestro el cliente de la posicion solicitada
 * @param listC Cliente*
 * @param i int
 */
void listarCliente(Cliente *listC, int i);


//VALIDACIONES
/**
 * @brief Busco el primer lugar vacio
 * @param listR Reparacion*
 * @param limite int
 * @return Devuelvo la primer posicion vacia
 */
int reparacion_getEmpty(Reparacion *listR, int limite);

/**
 * @brief Doy de alta una reparacion
 * @param listE Electrodomestico*
 * @param listM Marca*
 * @param listR Reparacion*
 * @param listS Servicio*
 * @param listC Cliente*
 * @param len int
 * @param indice int
 * @param id int
 * @return Devuelvo 0 si el alta fue exito o -1 si no se pudo
 */
int altaReparacion(Electrodomestico *listE, Marca *listM, Reparacion *listR,
		Servicio *listS, Cliente *listC, int len, int indice, int *id);

/**
 * @brief Valido la fecha ingresada
 * @param listR Reparacion*
 * @param posicion int
 */
void getFecha(Reparacion *listR, int posicion);

/**
 * @brief Valido el cliente ingresado
 * @param listR Reparacion*
 * @param posicion int
 */
void getCliente(Reparacion *listR, int posicion);
