#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "electrodomesticos.h"
#include "reparaciones.h"
#include "utn.h"

#define MAX_INPUT 10000

void hardcodearMarcas(Marca listaM[], int len) {
	Marca hardMarca[] = { { 1000, "Whirpool" }, { 1001, "Sony" }, { 1002,
			"Liliana" }, { 1003, "Gafa" }, { 1004, "Philips" } };

	for (int i = 0; i < len; i++) {
		listaM[i] = hardMarca[i];
	}

}

void iniElectrodomestico(Electrodomestico *listE, int len) {
	if (listE != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			listE[i].isEmpty = 1;
		}
	}
}

int electrodomestico_getEmptyIndex(Electrodomestico *listE, int len) {
	int respuesta = -1;
	int i;
	if (listE != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (listE[i].isEmpty != 0) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

int electrodomestico_flagAlta(Electrodomestico *listE, int limite) {
	int respuesta = -1;
	int i;
	if (listE != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			if (listE[i].isEmpty == 0) {
				respuesta = 0;
				break;
			}
		}
	}
	return respuesta;
}

int altaElectrodomestico(Electrodomestico *listE, Marca *listM, int len,
		int indice, int *id) {
	int respuesta = -1;
	Electrodomestico bufferElectrodomestico;

	if (listE != NULL && listM != NULL && id != NULL && indice >= 0) {
		printf("\nDando de ALTA ELECTRODOMESTICO id: %d", indice);
		listarMarcas(listM, TAM_MARCAS);
		if (utn_getNumero(&bufferElectrodomestico.idMarca,
				"\nIngresar ID de la marca: ",
				"\n****************No existe id marca****************\n****************Volver a ingresar****************\n",
				1000, 1004, 3) == 0
				&& utn_getNumero(&bufferElectrodomestico.serie,
						"Ingresar numero de serie: ",
						"\n****************Ingreso invalido****************\n****************Volver a ingresar****************\n",
						0, 9999999, 3) == 0
				&& utn_getNumero(&bufferElectrodomestico.modelo,
						"Ingresar modelo(año): ",
						"\n****************Ingreso invalido****************\n****************Volver a ingresar****************\n",
						1900, 2021, 3) == 0) {

			respuesta = 0;
			bufferElectrodomestico.id = indice;
			bufferElectrodomestico.isEmpty = 0;
			listE[indice] = bufferElectrodomestico;
			printf(
					"\n             ****************SE CARGO CON EXITO****************");
			printElectrodomestico(listE, listM, indice, len);
			printf(
					"\n-------------------------------------------------------------------------------------\n");
		}
	}
	return respuesta;
}




void listarMarcas(Marca *listM, int len) {
	int i;
	printf("\n      ****************LISTA DE MARCAS****************");
	printf("\nID        MARCA\n");
	for (i = 0; i < len; i++) {
		if (listM != NULL) {
			listarMarca(listM, i);
		}
	}
}

void listarMarca(Marca *listM, int i) {
	printf("%d      %s\n", listM[i].id, listM[i].descripcion);
}

void bajaElectrodomestico(Electrodomestico *listE, Marca *listM, int len,
		int indice) {
	char rta;
	do {
		printf("\nSeguro desea borrar? s/n\n");
		__fpurge(stdin);
		scanf("%c", &rta);
		rta = tolower(rta);
	} while (!(rta == 's' || rta == 'n'));

	switch (rta) {
	case 's':
		listE[indice].isEmpty = 1;
		printf("\n*****************Se borro con exito*****************\n");
		break;
	case 'n':
		break;
	}
}

void modificarElectrodomestico(Electrodomestico *listE, Marca *listM, int len,
		int posicion) {
	int option;
	char rta;
	Electrodomestico bufferModify;
	do {
		if (listE != NULL && listE[posicion].isEmpty == 0) {
			printf(
					"\n                         ELECTRODOMESTICO A MODIFICAR                         ");
			printElectrodomestico(listE, listM, posicion, len);
			printf(
					"\n-------------------------------------------------------------------------------------");
			utn_getNumero(&option,
					"\n\n1) Modificar id MARCA.\n2) Mofidicar numero de serie.\n3) Modificar modelo(año).\n5) Salir.\nIngresar opcion: ",
					"\n****************Opcion invalida****************\n\n****************Volver a ingresar****************\n",
					1, 5, 3);
			switch (option) {
			case 1:
				listarMarcas(listM, TAM_MARCAS);
				if (utn_getNumero(&bufferModify.idMarca, "\nNuevo id MARCA: ",
						"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
						1000, 1004, 3) == 0) {
					listE[posicion].idMarca = bufferModify.idMarca;
				}

				break;
			case 2:
				if (utn_getNumero(&bufferModify.serie,
						"\nNuevo numero de serie: ",
						"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
						0, 20000, 3) == 0) {
					listE[posicion].serie = bufferModify.serie;
				}
				break;
			case 3:
				if (utn_getNumero(&bufferModify.modelo, "\nNuevo modelo(año): ",
						"\n****************Ingreso invalido****************\n\n****************Volver a ingresar****************\n",
						1950, 2021, 3) == 0) {
					listE[posicion].modelo = bufferModify.modelo;
				}
				break;
			case 5:
				printf("Seguro desea salir? s/n\n");
				__fpurge(stdin);
				scanf("%c", &rta);
				rta = tolower(rta);
				break;
			}
		}
	} while (!(rta == 's'));
}

int electrodomesticoBuscarID(Electrodomestico *listE, int limite,
		int valorBuscado) {
	int respuesta = -1;
	int i;

	if (listE != NULL && limite > 0 && valorBuscado >= 0) {
		for (i = 0; i < limite; i++) {
			if (listE[i].id == valorBuscado && listE[i].isEmpty == 0) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

void listarElectrodomesticosEnOrden(Electrodomestico *listE, Marca *listM, int len,
		int orden) {
	int i;
	int j;
	Electrodomestico bufferElectrodomestico;
	if (listE != NULL && len > 0 && (orden == 1 || orden == 0)) {
		for (i = 0; i < len - 1; i++) {
			for (j = i + 1; j < len; j++) {
				if ((listE[i].modelo < listE[j].modelo && orden == 1)) {
					bufferElectrodomestico = listE[i];
					listE[i] = listE[j];
					listE[j] = bufferElectrodomestico;
				} else if ((listE[i].modelo == listE[j].modelo)
						|| (listE[i].serie < listE[j].serie && orden == 1)) {
					bufferElectrodomestico = listE[i];
					listE[i] = listE[j];
					listE[j] = bufferElectrodomestico;
				}
			}
		}
		printElectrodomesticos(listE, listM, len);
		printf("\n-------------------------------------------------------------------------------------\n");
	}
}



void printElectrodomesticos(Electrodomestico *listE, Marca *listM, int len) {
	printf(
			"\n                         LISTA DE ELECTRODOMESTICOS                         ");
	for (int i = 0; i < len; i++) {
		printElectrodomestico(listE, listM, i, len);
	}
}

void printElectrodomestico(Electrodomestico *listE, Marca *listM, int posicion,
		int len) {
	for (int i = 0; i < len; i++) {
		if (listE != NULL && listM != NULL
				&& listM[i].id == listE[posicion].idMarca
				&& listE[posicion].isEmpty == 0) {
			printf(
					"\n-------------------------------------------------------------------------------------");
			printf(
					"\nID: %d | Nro serie del electrodomestico: %d | Marca: %s | Modelo(año): %d",
					listE[posicion].id, listE[posicion].serie,
					listM[i].descripcion, listE[posicion].modelo);
			break;
		}
	}
}
