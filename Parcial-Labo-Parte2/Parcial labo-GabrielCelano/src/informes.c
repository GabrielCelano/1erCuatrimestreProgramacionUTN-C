#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "electrodomesticos.h"
#include "reparaciones.h"
#include "utn.h"
#include "informes.h"



void printElectrodomesticos2020(Electrodomestico *listE, Marca *listM, int len) {
	//int posicion;
	for (int i = 0; i < len; i++) {
		if (listE != NULL && listM != NULL && listE[i].modelo == 2020
				&& listE[i].isEmpty == 0) {
			printf(
					"\n-------------------------------------------------------------------------------------");
			printf(
					"\nID: %d | Nro serie del electrodomestico: %d | Marca: %s | Modelo(año): %d",
					listE[i].id, listE[i].serie, listM[i].descripcion,
					listE[i].modelo);
		}
	}
}

void printElectrodomesticosMarca(Electrodomestico *listE, Marca *listM, int len) {
	//int posicion;
	int idMarca;
	listarMarcas(listM, TAM_MARCAS);
	if (utn_getNumero(&idMarca, "\nIngresar ID de la marca: ",
			"\n****************No existe id marca****************\n****************Volver a ingresar****************\n",
			1000, 1004, 3) == 0) {
		for (int i = 0; i < len; i++) {
			if (listE != NULL && listM != NULL && listE[i].idMarca == idMarca) {
				for (int x = 0; x < len; x++) {
					if (listE != NULL && listM != NULL
							&& idMarca == listM[x].id) {
						printf(
								"\n-------------------------------------------------------------------------------------");
						printf(
								"\nID: %d | Nro serie del electrodomestico: %d | Marca: %s | Modelo(año): %d",
								listE[i].id, listE[i].serie,
								listM[x].descripcion, listE[i].modelo);
					}
				}
			} else {
				printf("                             NO EXISTE");
				break;
			}
		}

	}
}

void printReparacionElectrodomestico(Reparacion *listR, Servicio *listS,
		Cliente *listC, Electrodomestico *listE, int len) {
	int serie;
	if (utn_getNumero(&serie, "Ingresar numero de serie: ",
			"\n****************Ingreso invalido****************\n****************Volver a ingresar****************\n",
			0, 9999999, 3) == 0) {
		for (int iReparacion = 0; iReparacion < len; iReparacion++) {
			if (listR != NULL && listS != NULL
					&& listR[iReparacion].serie == serie
					&& listR[iReparacion].isEmpty == 0) {
				for (int iCliente = 0; iCliente < len; iCliente++) {
					if (listR != NULL && listS != NULL && listC != NULL
							&& listR[iReparacion].eCliente.id
									== listC[iCliente].id) {
						for (int iServicio = 0; iServicio < len; iServicio++) {
							if (listR != NULL && listS != NULL
									&& listR[iReparacion].idServicio
											== listS[iServicio].id) {
								printf(
										"\n---------------------------------------------------------------------------------------------------------------------------------------------");
								printf(
										"\nReparacion(ID): %d | Cliente: %s %s | Fecha de ingreso: %d/ %d/ %d | Numero de serie: %d | Servicio: %s | Precio: $%d",
										listR[iReparacion].id,
										listC[iCliente].nombre,
										listC[iCliente].apellido,
										listR[iReparacion].eFecha.dia,
										listR[iReparacion].eFecha.mes,
										listR[iReparacion].eFecha.anio,
										listR[iReparacion].serie,
										listS[iServicio].descripcion,
										listS[iServicio].precio);
								break;
							}
						}
						break;
					}
				}
			} else {
				printf(
						"                                                 NO HAY REPARACIONES");
				break;
			}
		}
	}
}




void printImporteReparacionElectrodomestico(Reparacion *listR, Servicio *listS,
		Cliente *listC, Electrodomestico *listE, int len) {
	int acu = 0;
	int serie;
	if (utn_getNumero(&serie, "Ingresar numero de serie: ",
			"\n****************Ingreso invalido****************\n****************Volver a ingresar****************\n",
			0, 9999999, 3) == 0) {
		for (int iReparacion = 0; iReparacion < len; iReparacion++) {
			if (listR != NULL && listS != NULL
					&& listR[iReparacion].serie == serie
					&& listR[iReparacion].isEmpty == 0) {
				for (int iCliente = 0; iCliente < len; iCliente++) {
					if (listR != NULL && listS != NULL && listC != NULL
							&& listR[iReparacion].eCliente.id
									== listC[iCliente].id) {
						for (int iServicio = 0; iServicio < len; iServicio++) {
							if (listR != NULL && listS != NULL
									&& listR[iReparacion].idServicio
											== listS[iServicio].id) {
								acu = acu + listS[iServicio].precio;
								break;
							}
						}
						break;
					}
				}
			} else {
				printf(
						"                                                 NO HAY REPARACIONES");
				break;
			}
		}
	}
	printf("\n-------------------------------------------------------------------------------------------------------");
	printf("\nPrecio total de todas las reparaciones del electrodomestico: $%d",	acu);
}


