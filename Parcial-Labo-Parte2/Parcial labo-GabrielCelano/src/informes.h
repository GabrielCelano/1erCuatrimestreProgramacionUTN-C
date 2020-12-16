#ifndef INFORMES_H_
#define INFORMES_H_
#include "electrodomesticos.h"
#include "reparaciones.h"
#include "utn.h"



#endif /* INFORMES_H_ */
/**
 * @brief Muestro todos los electrodomesticos modelo 2020
 * @param listE Electrodomestico*
 * @param listM Marca*
 * @param len int
 */
void printElectrodomesticos2020(Electrodomestico *listE, Marca *listM, int len);
/**
 * @brief Imprimo todos los electrodomesticos de una marca seleccionada
 * @param listE Electrodomestico*
 * @param listM Marca*
 * @param len int
 */
void printElectrodomesticosMarca(Electrodomestico *listE, Marca *listM, int len);

/**
 * @brief Imprimo todas las reparaciones de efectuadas al electrodomestico seleccionada
 * @param listR Reparacion*
 * @param listS Servicio*
 * @param listC Cliente*
 * @param listE Electrodomestico*
 * @param len int
 */
void printReparacionElectrodomestico(Reparacion *listR, Servicio *listS, Cliente *listC,
		Electrodomestico *listE, int len);

/**
 * @brief Imporete total de las reparaciones
 * @param listR Reparacion*
 * @param listS Servicio*
 * @param listC Cliente*
 * @param listE Electrodomestico*
 * @param len int
 */
void printImporteReparacionElectrodomestico(Reparacion *listR, Servicio *listS,
		Cliente *listC, Electrodomestico *listE, int len);




