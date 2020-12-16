/*
 ============================================================================
 Name        : Parcial laboratorio
 Author      : Gabriel Celano 1ro 'E'
 Version     : 2.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "reparaciones.h"
#include "electrodomesticos.h"
#include "utn.h"
#include "informes.h"
#define TAM 1000
#define TAMR 5
#define TAM_HARD_C 5
#define TAM_HARD_M 5
#define TAM_HARD_S 4

// MAIN
int main(void) {

	Electrodomestico arrayElectrodomesticos[TAM];
	Reparacion arrayReparaciones[TAM];
	Marca arrayMarcas[TAM_HARD_M];
	Servicio arrayServicios[TAM_HARD_S];
	Cliente arrayClientes[TAM];
	int flagAlta = -1;
	int flagReparacion = -1;
	int auxiliarIndice;
	int auxID;
	int idReparacion = 0;
	int idElectrodomestico = 0;
	int opcion;
	int opcionInformes;
	int orden = 1;
	char rta = 'n';
	char rtaInformes = 'n';
	//Harcodeo MARCAS, SERVICIOS Y CLIENTES
	hardcodearMarcas(arrayMarcas, TAM_HARD_M);
	hardcodearServicios(arrayServicios, TAM_HARD_S);
	hardcodearClientes(arrayClientes, TAM_HARD_C);

	//Inicializo todas las posiciones de isEmpty en 1
	iniElectrodomestico(arrayElectrodomesticos, TAM);
	iniReparacion(arrayReparaciones, TAM);
	do {

		if (!utn_getNumero(&opcion,
				"\n1) ALTA ELECTRODOMESTICO.\n2) MODIFICAR ELECTRODOMESTICO.\n3) BAJA ELECTRODOMESTICO.\n4) LISTAR ELECTRODOMESTICOS.\n5) LISTAR MARCAS.\n6) LISTAR SERVICIOS.\n7) ALTA REPARACION.\n8) LISTAR REPARACIONES\n9) LISTAR CLIENTES\n10) INFORMES\n11) SALIR.\nIngresar opcion: ",
				"\n**********No es una opcion**********\n", 1, 11, 3)) { // Valido que el retorno de la funciones menu este todo OK, sino no puedo entrar al switch
			switch (opcion) {
			case 1:
				auxiliarIndice = electrodomestico_getEmptyIndex( //Busco el primer id vacio
						arrayElectrodomesticos, TAM);
				if (auxiliarIndice >= 0) {
					flagAlta = altaElectrodomestico(arrayElectrodomesticos,
							arrayMarcas,
							TAM, auxiliarIndice, &idElectrodomestico); //Llamo el alta de electrodomestico y pongo en 0 o -1 la bandera, para poder ingresar o no a los demas case
				}
				break;
			case 2:
				if (flagAlta == 0) {
					printElectrodomesticos(arrayElectrodomesticos, arrayMarcas,
					TAM); //Muestro todos los id de los electrodomesticos
					printf(
							"\n-------------------------------------------------------------------------------------");
					if (utn_getNumero(
							&auxID, //Valido el id que deseo modificar
							"\nIngresar id que desea modificar: ",
							"\n****************Ingreso invalido****************\n****************Volver a ingresar****************\n",
							0, TAM, 3) == 0) {
						auxID = electrodomesticoBuscarID(arrayElectrodomesticos,
						TAM, auxID);
						if (auxID != -1) {
							modificarElectrodomestico(arrayElectrodomesticos, //Llamo a la funcion modificar electrodomesticos
									arrayMarcas, TAM, auxID);
						} else {
							printf("\n**************ID VACIO************\n");
						}
					}
				} else {
					printf(
							"\n****************PRIMERO DAR DE ALTA ELECTRODOMESTICO****************\n");
				}
				break;
			case 3:
				if (flagAlta == 0) {
					printElectrodomesticos(arrayElectrodomesticos, arrayMarcas,
					TAM);
					printf(
							"\n-------------------------------------------------------------------------------------");
					if (utn_getNumero(&auxID,
							"\n\nIngresar id que desea borrar: ",
							"\n****************Ingreso invalido****************\n****************Volver a ingresar****************\n",
							0, TAM, 3) == 0) {
						auxID = electrodomesticoBuscarID(arrayElectrodomesticos,
						TAM, auxID);
						if (auxID != -1) {
							bajaElectrodomestico(arrayElectrodomesticos, //Llamo a la funcion baja electrodomestico
									arrayMarcas,
									TAM, auxID);
							flagAlta = electrodomestico_flagAlta( //Verifico si hay todavia espacios ocupados o si estan todos vacios
									arrayElectrodomesticos, TAM);
						} else {
							printf("\n**************ID VACIO************\n");
						}
					}
				} else {
					printf(
							"\n****************PRIMERO DAR DE ALTA ELECTRODOMESTICO****************\n");
				}
				break;
			case 4:
				if (flagAlta == 0) {
					listarElectrodomesticosEnOrden(arrayElectrodomesticos, arrayMarcas,
					TAM, orden);
				} else {
					printf(
							"\n****************PRIMERO DAR DE ALTA ELECTRODOMESTICO****************\n");
				}
				break;
			case 5:
				listarMarcas(arrayMarcas, TAM_HARD_M); // Muestro todas las marcas
				break;
			case 6:
				listarServicios(arrayServicios, TAM_HARD_S); //Muestro todos los servicios
				break;
			case 7:
				if (flagAlta == 0) {
					auxiliarIndice = reparacion_getEmpty(arrayReparaciones, //Busco el primer lugar vacio de las reparaciones
							TAM);
					if (auxiliarIndice >= 0) { //LLamo a la funcion alta reparacion para dar de alta una reparacion
						flagReparacion = altaReparacion(arrayElectrodomesticos,
								arrayMarcas, arrayReparaciones, arrayServicios,
								arrayClientes, TAM, auxiliarIndice,
								&idReparacion);
					}
				} else {
					printf(
							"\n****************PRIMERO DAR DE ALTA ELECTRODOMESTICO****************\n");
				}
				break;
			case 8:
				if (flagAlta == 0 && flagReparacion == 0) {
					listarReparaciones(arrayElectrodomesticos,
							arrayReparaciones, arrayServicios, arrayClientes,
							TAM);
					printf(
							"\n---------------------------------------------------------------------------------------------------------------------------------------------\n");
				} else {
					printf(
							"\n****************PRIMERO DAR DE ALTA ELECTRODOMESTICO O REPARACIONES****************\n");
				}
				break;
			case 9:
				listarClientes(arrayClientes, TAM_HARD_C); //Muestro todos los clientes
				break;
			case 10:
				//do {
					if (!utn_getNumero(&opcionInformes,
							"\n1) Mostrar Electrodomesticos del año(modelo) 2020.\n2) Mostrar Electrodomesticos de una marca seleccionada.\n3) Mostrar todas las reparaciones efectuadas al electrodomestico seleccionado.\n4) Informar importe total de las reparaciones realizadas a un electrodomestico seleccionado\n5) Salir de informes.\nIngresar opcion: ",
							"\n**********No es una opcion**********\n", 1, 5,
							3)) {
						switch (opcionInformes) {
						case 1:
							printElectrodomesticos2020(arrayElectrodomesticos, arrayMarcas, TAM);
							printf("\n-------------------------------------------------------------------------------------\n");
							break;
						case 2:
							printElectrodomesticosMarca(arrayElectrodomesticos, arrayMarcas, TAM);
							printf("\n-------------------------------------------------------------------------------------\n");
							break;
						case 3:
							listarElectrodomesticosEnOrden(arrayElectrodomesticos, arrayMarcas, TAM, orden);
							printReparacionElectrodomestico(arrayReparaciones, arrayServicios, arrayClientes, arrayElectrodomesticos, TAM);
							printf("\n---------------------------------------------------------------------------------------------------------------------------------------------\n");
							break;
						case 4:
						    listarElectrodomesticosEnOrden(arrayElectrodomesticos, arrayMarcas, TAM, orden);
							printImporteReparacionElectrodomestico(arrayReparaciones, arrayServicios, arrayClientes, arrayElectrodomesticos, TAM);
							printf("\n-----------------------------------------------------------------------------\n");
							break;
						case 5:
							printf("Seguro quiere salir de informes? s/n\n"); //Salir del programa
						    __fpurge(stdin);
							scanf("%c", &rtaInformes);
							rtaInformes = tolower(rtaInformes);
							break;
						}
					}
				//} while (!(rta == 's'));
				break;
			case 11:
				printf("Seguro quiere salir del programa? s/n\n"); //Salir del programa
				__fpurge(stdin);
				scanf("%c", &rta);
				rta = tolower(rta);
				break;
			}
		}
	} while (!(rta == 's'));
}

