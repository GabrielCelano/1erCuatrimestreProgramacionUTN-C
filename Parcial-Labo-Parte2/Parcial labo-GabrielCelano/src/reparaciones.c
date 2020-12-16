#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "electrodomesticos.h"
#include "reparaciones.h"
#include "utn.h"
#define TAM 10
#define TAM_SERVICIOS 4
#define TAM_CLIENTES 5

void hardcodearServicios(Servicio *listaS, int len) {
	Servicio hardServicios[] = { { 20000, "Garantia", 250 }, { 20001,
			"Mantenimiento", 500 }, { 20002, "Repuestos", 400 }, { 20003,
			"Refaccion", 600 }, };
	for (int i = 0; i < len; i++) {
		listaS[i] = hardServicios[i];
	}
}

void hardcodearClientes(Cliente *listaC, int len) {
	Cliente hardClientes[] = { { 0, "Gabriel", "Celano" }, { 1, "Aylen",
			"Cabano" }, { 2, "Nahuel", "Novoa" }, { 3, "Sebastian", "Paez" }, {
			4, "Matias", "Bilat" } };
	for (int i = 0; i < len; i++) {
		listaC[i] = hardClientes[i];
	}

}

void listarClientes(Cliente *listC, int len) { //Imprimo todas las posiciones.
	int i;
	printf("\n      ****************LISTA DE CLIENTES****************");
	printf("\nID  NOMBRE     APELLIDO\n");
	for (i = 0; i < TAM_CLIENTES; i++) {
		if (listC != NULL) {
			listarCliente(listC, i);
		}
	}
}

void listarCliente(Cliente *listC, int i) {
	printf("%d   %s   %s\n", listC[i].id, listC[i].nombre, listC[i].apellido);
}

void iniReparacion(Reparacion *listR, int len) {
	if (listR != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			listR[i].isEmpty = 1;
		}
	}
}

void listarServicio(Servicio *listS, int i) {
	printf("%d      %s\n", listS[i].id, listS[i].descripcion);
}

void listarServicios(Servicio *listS, int len) {
	int i;
	printf("\n      ****************LISTA DE SERVICIOS****************");
	printf("\nID        SERVICIO\n");
	for (i = 0; i < TAM_SERVICIOS; i++) {
		if (listS != NULL) {
			listarServicio(listS, i);
		}
	}
}

int reparacion_getEmptyIndex(Reparacion *listR, int limite) {
	int respuesta = -1;
	int i;
	if (listR != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			if (listR[i].isEmpty == 1) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

int altaReparacion(Electrodomestico *listE, Marca *listM, Reparacion *listR,
		Servicio *listS, Cliente *listC, int len, int indice, int *id) {
	int respuesta = -1;
	int validacion = -1;
	int auxId;
	//Electrodomestico bufferElectrodomestico;
	Reparacion bufferReparaciones;

	if (listE != NULL && listM != NULL && id != NULL && indice >= 0) {
		printf("\nDando de ALTA REPARACION id: %d\n", indice);
		printElectrodomesticos(listE, listM, len);
		printf(
				"\n-------------------------------------------------------------------------------------");
		if (utn_getNumero(&bufferReparaciones.id,
				"\nIngresar id electrodomestico: ",
				"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
				0, TAM, 3) == 0) {
			auxId = electrodomesticoBuscarID(listE, len, bufferReparaciones.id);
			for (int i = 0; i < len; i++) {
				if (auxId >= 0) {
					bufferReparaciones.serie = listE[auxId].serie;
					bufferReparaciones.id = indice;
					validacion = 0;
					break;
				} else {
					printf("\n****************NO EXISTE*****************\n");
					break;
				}
			}
		}
		if (validacion == 0) {
			listarServicios(listS, len);
			if (utn_getNumero(&bufferReparaciones.idServicio,
					"\nIngresar servicio(id): ",
					"\n****************Ingreso invalido****************\n****************Volver a ingresar****************\n",
					20000, 20003, 3) == 0) {
				for (int i = 0; i < len; i++) {
					if (listS[i].id == bufferReparaciones.idServicio) {
						bufferReparaciones.idServicio = listS[i].id;
						bufferReparaciones.isEmpty = 0;
						listR[indice] = bufferReparaciones;
						listarClientes(listC, len);
						getCliente(listR, indice);
						getFecha(listR, indice);
						respuesta = 0;
					}
				}
			}
		}
	}
	printf(
			"\n                                                                  SE CARGO CON EXITO\n");
	printf(
			"---------------------------------------------------------------------------------------------------------------------------------------------\n");
	printReparacion(listR, listS, listC, listE, indice, len);
	printf(
			"\n---------------------------------------------------------------------------------------------------------------------------------------------\n");
	return respuesta;
}

int reparacion_getEmpty(Reparacion *listR, int len) {
	int respuesta = -1;
	int i;
	if (listR != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (listR[i].isEmpty != 0) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

void printReparacion(Reparacion *listR, Servicio *listS, Cliente *listC, Electrodomestico *listE
		,int posicion, int len) {
	for (int iServicio = 0; iServicio < len; iServicio++) {
		if (listR != NULL && listS != NULL
				&& listR[posicion].idServicio == listS[iServicio].id) {
			for (int iCliente = 0; iCliente < len; iCliente++) {
				if (listR != NULL && listS != NULL && listC != NULL
						&& listR[posicion].eCliente.id == listC[iCliente].id) {
					printf(
							"Reparacion(ID): %d | Cliente: %s %s | Fecha de ingreso: %d/ %d/ %d | Numero de serie: %d | Servicio: %s | Precio: $%d",
							listR[posicion].id, listC[iCliente].nombre,
							listC[iCliente].apellido,
							listR[posicion].eFecha.dia,
							listR[posicion].eFecha.mes,
							listR[posicion].eFecha.anio, listR[posicion].serie,
							listS[iServicio].descripcion,
							listS[iServicio].precio);
					break;
				}
		    }
			break;
		}
	}
}

void listarReparaciones(Electrodomestico *listE, Reparacion *listR,
		Servicio *listS, Cliente *listC, int len) {
	printf(
			"\n                                                       LISTA DE REPARACIONES");
	for (int i = 0; i < len; i++) {
		listaReparacion(listE, listR, listS, listC, i, len);
	}
}

void listaReparacion(Electrodomestico *listE, Reparacion *listR, Servicio *listS,
		Cliente *listC, int posicion, int len) {
	if (listR != NULL && listS != NULL && listE != NULL
			&& listR[posicion].isEmpty == 0) {
		for (int iServicio = 0; iServicio < len; iServicio++) {
			if (listR[posicion].idServicio == listS[iServicio].id) {
				for (int iCliente = 0; iCliente < len; iCliente++) {
					if (listR != NULL && listS != NULL && listC != NULL
							&& listR[posicion].eCliente.id
									== listC[iCliente].id) {
						printf(
								"\n---------------------------------------------------------------------------------------------------------------------------------------------");
						printf(
								"\nReparacion(ID): %d | Cliente: %s %s | Fecha de ingreso: %d/ %d/ %d | Numero de serie: %d | Servicio: %s | Precio: $%d",
								listR[posicion].id, listC[iCliente].nombre,
								listC[iCliente].apellido,
								listR[posicion].eFecha.dia,
								listR[posicion].eFecha.mes,
								listR[posicion].eFecha.anio,
								listR[posicion].serie,
								listS[iServicio].descripcion,
								listS[iServicio].precio);
						break;
					}
				}
				break;
			}
		}
	}
}

void getFecha(Reparacion *listR, int posicion) {
	Reparacion bufferFecha;
	if (listR != NULL) {
		if (utn_getNumero(&bufferFecha.eFecha.dia, "Ingresar dia: ",
				"\n****************Ingreso invalido****************\n****************Volver a ingresar****************\n",
				1, 31, 3) == 0
				&& utn_getNumero(&bufferFecha.eFecha.mes, "Ingresar mes: ",
						"\n****************Ingreso invalido****************\n****************Volver a ingresar****************\n",
						1, 12, 3) == 0
				&& utn_getNumero(&bufferFecha.eFecha.anio, "Ingresar año: ",
						"\n****************Ingreso invalido****************\n****************Volver a ingresar****************\n",
						1950, 2030, 3) == 0) {
			listR[posicion].eFecha = bufferFecha.eFecha;
		}
	}
}

void getCliente(Reparacion *listR, int posicion) {
	Reparacion bufferCliente;
	if (utn_getNumero(&bufferCliente.eCliente.id, "\nIngresar cliente(id): ",
			"\n****************Ingreso invalido****************\n****************Volver a ingresar****************\n",
			0, 4, 3) == 0) {
		listR[posicion].eCliente = bufferCliente.eCliente;
	}
}
