#include <stdio.h>
#include <stdlib.h>
#include "eArticulo.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "utn.h"
#include "Save.h"


int main() {
	LinkedList *pList = ll_newLinkedList();
	eRubro arrayRubro[4];
	int auxPrecio;
	int auxRubro1;
	int flagAltaArchivo=0;
	int flagAltaMapeado=0;
	char seguir = 'n';
	char seguirInformes = 'n';
	char path [20];

	harcodearRubros(arrayRubro, 4);

	if (pList != NULL) {
              do {
			switch (menu()) {
			case 1:
			    //free(pList);
				utn_getNombre(path, 20, "Ingresar nombre del archivo:\n", "Error, ingresar path correcto.\n", 5);
				if (flagAltaArchivo == 1) {
				    ll_deleteLinkedList(pList);
                    pList = ll_newLinkedList();
                    if(controller_loadFromText(path, pList) == 0){
					printf("\nLos datos fueron cargados correctamente.\n");
                    }else{
                    printf("\nError al cargar archivo (el archivo no existe).\n");
                    }
				}else{
                        if(controller_loadFromText(path, pList) == 0){
					printf("\nLos datos fueron cargados correctamente.\n");
					flagAltaArchivo = 1;
				} else {
					printf("\nError al cargar archivo (el archivo no existe).\n");
				}
				}
				break;
			case 2:
				if (ll_isEmpty(pList) == 0) {
					if (controller_sort(pList) == 0) {
                            printf("\nSe ordeno correctamente la lista.\n");
					} else {
						printf("\nError al ordenar.\n");
					}
				}else{printf("\nPara mostrar los datos primero hay que cargarlos.\n");
				}
				break;
			case 3:
			    if (ll_isEmpty(pList) == 0) {
			    if(controller_List(pList, arrayRubro) == 0){
			    }
			    }else{printf("\nPara mostrar los datos primero hay que cargarlos.\n");
			    }
			    printf("\nIngresar cualquier tecla para continuar...\n");
			    getchar();
				break;
			case 4:
			    if (ll_isEmpty(pList) == 0) {
			   ll_map(pList, eArticulo_llmap);
			   if(pList != NULL){
			       printf("\nMap correcto.\n");
			       flagAltaMapeado = 1;
			   }
                    }else{printf("\nPara mostrar los datos primero hay que cargarlos\n");
			    }
				break;
			case 5:
			    if (ll_isEmpty(pList) == 0 && flagAltaMapeado == 1) {
                        if(saveAsText("mapeado.csv", pList) == 1){
                            printf("\nSe genero 'mapeado.csv' y se guardaron los datos.\n");
                        }
			    }else{
			        printf("\nPara guardar un nuevo archivo primero cargar uno y realizar el MAP.\n");
			    }
				break;
			case 6:
			    if (ll_isEmpty(pList) == 0) {
			    do{
                    switch(menuInformes()){
                case 1:
			        auxPrecio = ll_count(pList, eArticulo_filterPrecioArticulo);
			        if(auxPrecio > 0){
                        printf("\nCantidad de articulos cuyo precio es mayor a $100: %d\n", auxPrecio);
			        }
			    printf("\nIngresar cualquier tecla para continuar...\n");
			    getchar();
			    break;
			    case 2:
			        auxRubro1 = ll_count(pList, eArticulo_filterRubro1);
			        if(auxPrecio > 0){
                        printf("\nCantidad de articulos del rubro 1 - CUIDADO DE ROPA: %d\n", auxRubro1);
			        }
			    printf("\nIngresar cualquier tecla para continuar...\n");
			    getchar();
                break;
                case 3:
                    printf("\nSeguro quiere salir de informes? s/n\n");
                    fflush(stdin);
                    scanf("%c", &seguirInformes);
                    break;
                    }
			    }while(seguirInformes != 's' && seguirInformes != 'S');
			    }else{
			        printf("\nPara mostrar los datos primero hay que cargarlos.\n");
			    }
				break;
            case 7:
                printf("\nSeguro quiere salir del programa? s/n\n");
                fflush(stdin);
                scanf("%c", &seguir);
				break;
			}
		}while (seguir != 's' && seguir != 'S');
	}
	ll_deleteLinkedList(pList); // libero el linkedlist
	free(pList);// libero el puntero a linkedlist
	return 0;
}

