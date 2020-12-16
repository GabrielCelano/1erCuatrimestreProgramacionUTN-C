#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eArticulo.h"
#include "utn.h"

void harcodearRubros(eRubro* listR, int len){
    eRubro hardRubro[] = {{1, "CUIDADO DE ROPA"}, {2, "LIMPIEZA Y DESINFECCION"}, {3, "CUIDADO PERSONAL E HIGIENE"}, {4, "CUIDADO DEL AUTOMOTOR"}};

    for (int i = 0; i < 4  ; i++) {
		listR[i] = hardRubro[i];
	}
}
/*
void listarRubros(eRubro* listR, int len) {
	int i;
	printf("\nID        DESCRIPCION\n");
	for (i = 0; i < len; i++) {
		if (listR != NULL) {
			printRubro(listR, i);
		}
	}
}

void printRubro(eRubro* listR, int i) {
	printf("%d      %s\n", listR[i].id, listR[i].descripcion);
}
*/
void eArticulo_delete(eArticulo *this) {
	if (this != NULL) {
		free(this);
	}
}

int eArticulo_setId(eArticulo *this, int id) {
	int retorno = 0;
	if (this != NULL && id > 0) { //verifico que this no sea null y que el id sea mayor a 0
		this->id = id; // seteo el nuevo valor id al campo id de mi estructura
		retorno = 1;
	}
	return retorno;
}

int eArticulo_getId(eArticulo *this, int *id) {
	int retorno = 0;
	if (this != NULL && id != NULL) { //verifico que la lista no sea null y el id que busco tambien
		*id = this->id; // le guardo a mi puntero id el valor del campo id
		retorno = 1;
	}
	return retorno;
}

int eArticulo_setArticulo(eArticulo *this, char *auxNombre) {
	int retorno = 0;
	if (this != NULL && auxNombre != NULL) {
		strcpy(this->articulo, auxNombre);
		retorno = 1;
	}
	return retorno;
}

int eArticulo_getArticulo(eArticulo *this, char *auxNombre) {
	int retorno = 0;
	if (this != NULL && auxNombre != NULL) {
		strcpy(auxNombre, this->articulo);
		retorno = 1;
	}
	return retorno;
}

int eArticulo_setPrecio(eArticulo *this, int auxPrecio) {
	int retorno = 0;
	if (this != NULL && auxPrecio > 0) {
		this->precio = auxPrecio;
		retorno = 1;
	}
	return retorno;
}

int eArticulo_getPrecio(eArticulo *this, int *auxPrecio) {
	int retorno = 0;
	if (this != NULL && auxPrecio != NULL) {
		*auxPrecio = this->precio;
		retorno = 1;
	}
	return retorno;
}

int eArticulo_setMedida(eArticulo *this, char *auxMedida) {
	int retorno = 0;
	if (this != NULL && auxMedida != NULL) {
		strcpy(this->medida, auxMedida);
		retorno = 1;
	}
	return retorno;
}

int eArticulo_getMedida(eArticulo *this, char *auxMedida) {
	int retorno = 0;
	if (this != NULL && auxMedida != NULL) {
		strcpy(auxMedida, this->medida);
		retorno = 1;
	}
	return retorno;
}

int eArticulo_setRubroId(eArticulo *this, int auxRubroId) {
	int retorno = 0;
	if (this != NULL && auxRubroId > 0) {
		this->rubroId = auxRubroId;
		retorno = 1;
	}
	return retorno;
}

int eArticulo_getRubroId(eArticulo *this, int *auxRubroId){
	int retorno = 0;
	if (this != NULL) {
		*auxRubroId = this->rubroId;
		retorno = 1;
	}
	return retorno;
}

eArticulo* eArticulo_new() {
	eArticulo *new;
	new = (eArticulo*) malloc(sizeof(eArticulo)); // le asigno una memoria dinamica a la variable new
	if (new != NULL) { // verifico si new viene NULL
		new->id = 0; // inicializo la estructura
		strcpy(new->articulo, " ");
        strcpy(new->medida, " ");
		new->precio = 0;
		new->rubroId = 0;
	} else { // si new viene NULL lo borro
		eArticulo_delete(new);
		new = NULL;
	}
	return new;
}

eArticulo* eArticulo_newParametros(char *idStr, char *nombreArticuloStr,
		char *medidaStr, char *precioStr, char *rubroId) {
	eArticulo *new;
	new = eArticulo_new(); // le asigno a new la direccion del retorno de eArticulo_new
	if (idStr != NULL && nombreArticuloStr != NULL && precioStr != NULL
			&& medidaStr != NULL && rubroId != NULL && new != NULL) {
		if (!eArticulo_setId(new, atoi(idStr)) //seteo los nuevos valores a eArticulo
				|| !eArticulo_setArticulo(new, nombreArticuloStr)
				|| !eArticulo_setMedida(new, medidaStr)
				|| !eArticulo_setPrecio(new, atoi(precioStr))
				|| !eArticulo_setRubroId(new, atoi(rubroId))) {
			eArticulo_delete(new);
			new = NULL;
		}
	}
	return new;
}

int eArticulo_isValid(eArticulo *pAux) {
	int retorno = -1, id, precio, rubroId;
	char articulo[50];
	char medida[20];

	if (pAux != NULL) { // valido que los datos cumplan el criterio
		eArticulo_getId(pAux, &id);
		eArticulo_getPrecio(pAux, &precio);
		eArticulo_getMedida(pAux, medida);
		eArticulo_getRubroId(pAux, &rubroId);
		eArticulo_getArticulo(pAux, articulo);
		if (id > 0 && precio > 0 && medida != NULL && rubroId > 0 && rubroId <=4 && articulo != NULL) {
			retorno = 0;
		}
	}
	return retorno;
}

int menu() {
	int opc;
	//system("cls");
	printf("\nMenu:\n\n");
	printf("1. Cargar archivo de articulos.\n");
	printf("2. Ordenar articulos.\n");
	printf("3. Lista de todos  los articulos.\n");
	printf("4. Aplicar descuento(MAP).\n");
	printf("5. Generar archivo de salida(mapeado.csv).\n");
	printf("6. Informes\n");
	printf("7. Salir\n");
	fflush(stdin);
	utn_getNumero(&opc, "\nIngresar opcion:", "\nOpcion incorrecta.\n",
			1, 7, 5);
	return opc;
}

int menuInformes() {
	int opc;
	//system("cls");
	printf("\nMenu Informes:\n\n");
	printf("1. Cantidad de articulos cuyo precio sea mayor a $100.\n");
	printf("2. Cantidad de articulos del rubro 1 - CUIDADO DE ROPA.\n");
	printf("3. Salir\n");
	fflush(stdin);
	utn_getNumero(&opc, "\nIngresar opcion:", "\nOpcion incorrecta.\n",
			1, 3, 5);
	return opc;
}


int printArticulo(eArticulo *this, eRubro *listR) {
	int retorno = -1, id, precio, rubroId;
	char articulo[50];
	char medida [20];

	if (this != NULL && listR != NULL) { // busco los valores del articulo filtrado
		eArticulo_getId(this, &id);
        eArticulo_getArticulo(this, articulo);
        eArticulo_getMedida(this, medida);
		eArticulo_getPrecio(this, &precio);
		eArticulo_getRubroId(this, &rubroId);
		for(int i = 0; i < 4; i++){//itero los id del rubro para que coincidan el id con la descripcion
        if(listR[i].id == rubroId){
		printf("\n%2d %35s %10s       $%5d %35s\n",id, articulo, medida, precio, listR[i].descripcion);
		break;
		retorno = 0;
        }
		}
	}

	return retorno;
}

int compareByName(void *eArt1, void *eArt2) {
	int retorno = 0;
	char articuloA[50];
	char articuloB[50];
	if (eArt1 != NULL && eArt2 != NULL) {

		eArticulo_getArticulo(eArt1, articuloA);
		eArticulo_getArticulo(eArt2, articuloB);

		if (strcmp(articuloA, articuloB) > 0) { //si devuelve mayor a 0 artB es menor a artA
			retorno = 1;
		} else if (strcmp(articuloA, articuloB) < 0) { //si devuelve menor a 0 artA es menor a artB
			retorno = -1;
		} else if (strcmp(articuloA, articuloB) == 0) {// si devuelve == 0 indica que son iguales
 			retorno = 0;
		}
	}

	return retorno;
}


void* eArticulo_llmap(void *pAux) {
   // eArticulo* pArticulo = eArticulo_new();
	int auxPrecio = 0;
	int auxPrecioNuevo = 0;
	if (pAux != NULL) {
		if (eArticulo_filterRubro(pAux)==0) { //SI DEVULVE 0, DEVUELVE EL ID DEL RUBRO CUIDADO DE ROPA
        eArticulo_getPrecio(pAux, &auxPrecio);
        if(auxPrecio >= 120){
        auxPrecioNuevo =  auxPrecio - ((20 * auxPrecio) / 100);
        eArticulo_setPrecio(pAux, auxPrecioNuevo);
        }
	}else if(eArticulo_filterRubro(pAux)==1){ //SI DEVULVE 1, DEVUELVE EL ID DEL RUBRO LIMPIEZA Y DESINFECCION
	    eArticulo_getPrecio(pAux, &auxPrecio);
        if(auxPrecio <= 200){
        auxPrecioNuevo =  auxPrecio - ((10 * auxPrecio) / 100);
        eArticulo_setPrecio(pAux, auxPrecioNuevo);
        }
	}
	}
	//return (void*)pArticulo;
}

int eArticulo_filterRubro(void* pAux){
    int retorno = -1;
    int auxRubroId;
    if(pAux!=NULL){
    eArticulo_getRubroId(pAux, &auxRubroId); // busco el rubroId
        if(auxRubroId == 1){ // si el id del rubro es 1 retorno 0
            retorno = 0;
        }else if(auxRubroId == 2){ // si el id del rubro es 2 retorno 1
            retorno = 1;
        }
    }
    return retorno;
}

int eArticulo_filterPrecioArticulo(void* pAux){
   int retorno = 0;
   int auxPrecio;
   if(pAux!=NULL){
       eArticulo_getPrecio(pAux, &auxPrecio); // busco el precio
   if(auxPrecio > 100){ // si el precio es mayor a 100 retorna 1
        retorno = 1;
   }else{
       retorno = 0;
   }
   }
   return retorno;
}

int eArticulo_filterRubro1(void* pAux){
   int retorno = 0;
   int auxRubro1;
   if(pAux!=NULL){
       eArticulo_getRubroId(pAux, &auxRubro1); //busco el id del rubro
   if(auxRubro1 == 1){ // si el id es 1 retorna 1
        retorno = 1;
   }else{retorno = 0;}
   }
   return retorno;
}
