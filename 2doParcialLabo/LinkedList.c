#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {
	LinkedList *this; //variable puntero a la linkedlist
	this = (LinkedList*) malloc(sizeof(LinkedList)); //le asigno la direccion de memoria dinamica a la variable
	if (this != NULL) { //valido si me asigno la memoria dinamica
		this->size = 0; //inicializo el size en 0 porque es el primero que agrego
		this->pFirstNode = NULL; //lo pongo en null porque tengo asignado una direccion de memoria pero adentro no tiene nada
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) { // valido si la lista trae null
		returnAux = this->size; // le asigno al retorno el tamanio de la LinkedList
		//printf("\n%d\n", returnAux);
	}

	return returnAux;
}

/** \brief  Obtiene un puntero a un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList *this, int nodeIndex) {
	Node *pNode = NULL; // declaro un puntero a nodo y le asigno NULL para que no tenga basura

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) { //valido que no este nulo, que el node index sea >= a 0 y que sea menor al tamanio de len, no es igual a len para que no se vaya de rango
		if (nodeIndex == 0) { // verifico si es el primer nodo
			pNode = this->pFirstNode; // si es el primer lo guardo
		} else {
			pNode = this->pFirstNode;
			while (nodeIndex > 0) { // pregunto que el nodo ingresado sea mayor a cero
				pNode = pNode->pNextNode; // se guarda el next node del nodo donde estoy
				nodeIndex--; //decremento hasta llegar a 0 y devolver el node que busco
			}
		}
	}

	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex) {
	return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	int returnAux = -1;
	Node *pNewNode = NULL; //le anigno nulo
	Node *pAuxNode = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) {
		pNewNode = (Node*) malloc(sizeof(Node)); //le asigno una memoria dinamica a pNewNode
		pNewNode->pElement = pElement; // le asigno el puntero a elemento al elemento del nuevo nodo
		if (pNewNode != NULL && nodeIndex == 0) { //pregunto si el node es en la posicion 0
			pNewNode->pNextNode = this->pFirstNode; // resguardo lo que tengo en mi firstnode
			this->pFirstNode = pNewNode; // y en mi firtsnode guardo la direccion de memoria de mi nuevo nodo
			this->size++; //aumento el tamanio de la linkedlist por el nuevo nodo agregado
			returnAux = 0;
		} else { // si el node no es en la posicion 0
			pAuxNode = (Node*) malloc(sizeof(Node));
			if (pAuxNode != NULL) {
				pAuxNode = getNode(this, nodeIndex - 1); //le asigno a pAuxNode el pNextNode del anterior nodo
				pNewNode->pNextNode = pAuxNode->pNextNode; // le asigno a mi nuevo nodo la posicion de pAuxNode
				pAuxNode->pNextNode = pNewNode; //le asigno al nextnode de pAux la nueva direccion de memoria del siguiente
				this->size++; //aumento el tamanio de la linkedlist por el nuevo nodo agregado
				returnAux = 0;
			}
		}

	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement) {
	int returnAux = -1;
	if (this != NULL) { // verifico que no sea NULL
		returnAux = addNode(this, ll_len(this), pElement); // le paso la lista, la ultima posicion de mi lista y el elemento nuevo a agregar
	}
	return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param Index int Ubicacion del elemento
 * \return void* Retorna    (NULL) Error: si falla la verificacion y si tiene exito retorna el elemento
 *
 */
void* ll_get(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *pNode = NULL;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {// valido que el indice este dentro del 0 y la cantidad de mi lista
		pNode = getNode(this, index); // busco en la posicion index el nodo y lo guardo en pNode
		if (pNode != NULL) {
			returnAux = pNode->pElement; //le asigno al retorno el elemento de pNode
		}
	}
	return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *pAuxNode;
	if (this != NULL && index >= 0 && index < ll_len(this)) {
		pAuxNode = getNode(this, index);
		if (pAuxNode != NULL) {
			pAuxNode->pElement = pElement;
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index) {
	int returnAux = -1;
	Node *pAuxNode;
	Node *pNode;

	if (this != NULL && index >= 0 && index < this->size) {
		if (index == 0) {
			pAuxNode = getNode(this, index); // si la posicion es cero le paso el primer nodo a pAuxNode
			this->pFirstNode = pAuxNode->pNextNode; // y le asigno a FirstNode el NextNode de pAux
		} else {
			pAuxNode = getNode(this, index); //si la posicion que deseo borrar es mayor de cero, resguardo el node filtrado por index y se lo asigno a pAuxNode
			pNode = getNode(this, index - 1); // guardo en pNode el nodo anterior al filtrado por index
			pNode->pNextNode = pAuxNode->pNextNode; // guardo en pNextNode de pNode la direccion de memoria que contiene pNextNode de pAuxNode
		}
		this->size--;// decremento un lugar en mi lista
		returnAux = 0;
		free(pAuxNode);
	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		for (int i = 0; i < ll_len(this); i++) {
			ll_remove(this, i);
		}
		if (ll_len(this) == 0) {
			returnAux = 0;
		}

	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		ll_clear(this);
		free(this);
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;
	Node *pAuxNode;
	if (this != NULL) {
		for (int i = 0; i < ll_len(this); i++) { // itero hasta la ultima posicion de mi lista
			pAuxNode = getNode(this, i);
			if (pAuxNode != NULL) {
				if (pAuxNode->pElement == pElement) { // si el pElement de pAuxNode es igual al elemento que pase por parametro
					returnAux = i; // le asigno la posicion al return
				}
			}

		}
	}

	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this) {
	int returnAux = -1;
	if (this != NULL) {
		if (ll_len(this) > 0) {
			returnAux = 0;
		} else {
			returnAux = -1;
		}
	}
	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	if (this != NULL && index >= 0 && index <= ll_len(this)) {
		returnAux = addNode(this, index, pElement);
	}
	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {
		returnAux = ll_get(this, index);
		ll_remove(this, index);
	}

	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;
	if (this != NULL) {
		if (ll_indexOf(this, pElement) != -1) {
			returnAux = 1;
		} else {
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1, len;
	void *pAux;
	if (this != NULL && this2 != NULL) {
		returnAux = 0;
		len = ll_len(this2);
		for (int i = 0; i < len; i++) {
			pAux = ll_get(this2, i);
			if (pAux != NULL) {
				if (ll_contains(this, pAux) == 0) {
					returnAux = 0;
					break;
				} else {
					returnAux = 1;
				}
			}
		}
	}
	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 o (si el indice from es menor a 0 o mayor al len de la lista)
 o (si el indice to es menor o igual a from o mayor al len de la lista)
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	void *pAux = NULL;

	if (this != NULL && from >= 0 && from < to && to <= ll_len(this)) {
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL) {
			for (int i = from; i < to; i++) {
				pAux = ll_get(this, i);
				if (pAux != NULL) {
					addNode(cloneArray, i, pAux);
				}

			}
		}
	}

	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;

	if (this != NULL) {
		cloneArray = ll_subList(this, 0, ll_len(this));
	}

	return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	Node *pAuxNode;
	Node *pAuxNext;
	void *pAux;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1)
			&& ll_len(this) > 0) {
		for (int i = 0; i < ll_len(this) - 1; i++) {
			pAuxNode = getNode(this, i);
			for (int j = i + 1; j < ll_len(this); j++) {
				pAuxNext = getNode(this, j);
				if (pAuxNode != NULL && pAuxNext != NULL) {
					if ((order == 1	&& (pFunc(pAuxNode->pElement, pAuxNext->pElement) == 1)) || (order == 0	&& (pFunc(pAuxNode->pElement,pAuxNext->pElement) == -1))) { // dependiendo del criterio lo ordena de una forma u otra
						pAux = pAuxNode->pElement; //hace los switcheos
						pAuxNode->pElement = pAuxNext->pElement;
						pAuxNext->pElement = pAux;
						returnAux = 0;
					}
				}
			}
		}
	}
	return returnAux;

}

/** \brief Itera todos los elementos de la lista y se las pasa a pFunc
 *
 * \param this LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) puntero a la funcion criterio
 * \return Retorno pAux
 *
 */
LinkedList* ll_map(LinkedList *this, void* (*pFunc)(void*)) {
	LinkedList *pAux = NULL;
	void *pAuxElement = NULL;
	int len = ll_len(this); // busco el tamanio de mi lista
	if (this != NULL && len > 0) {
		pAux = ll_newLinkedList(); // le asigno a pAux la nueva lista en memoria dinamica
		if (pAux != NULL) {
			for (int i = 0; i < len; i++) {
				pAuxElement = ll_get(this, i); // recorro toda la lista y cada elemento de mi lista se lo asigno a pAuxElement
				if (pAuxElement != NULL) { // verifico que ese elemento no este vacio
					pAuxElement = pFunc(pAuxElement); // le asigno a pAuxElement el retorno de mi funcion pFunc
					ll_add(pAux, pAuxElement); // le paso a mi funcion ll_add mi lista y pAuxElement
				}

			}
		}
	}
	return pAux;
}


/** \brief Filtra los elementos de la lista
 *
 * \param this LinkedList* puntero a la lista
 * \param pFunc (*pFunc) puntero a la funcion criterio
 * \return Retorna una nueva lista con los elementos que cumplen la condicion
 *
 */
LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void*)) {
	LinkedList *pAux = NULL;
	void *pAuxElement = NULL;
	int len = ll_len(this);
	if (this != NULL && len > 0) {
		pAux = ll_newLinkedList(); // le asigno a pAux una nueva linkedlist
		if (pAux != NULL) { // verifico que no venga nula
			for (int i = 0; i < len; i++) { //itero todos los elementos y guardo uno por uno a pAuxElement
				pAuxElement = ll_get(this, i);
				if (pAuxElement != NULL) {
					if (pFunc(pAuxElement) == 1) {
						ll_add(pAux, pAuxElement);
					}
				}

			}
		}
	}
	return pAux;
}

/** \brief Itera todos los elementos de la lista y los pasa a la funcion *pFunc
 *
 * \param this LinkedList* puntero a la lista
 * \param pFunc (*pFunc) puntero a la funcion criterio
 * \return Retorna el valor acumulado
 *
 */

int ll_count(LinkedList *this, int (*pFunc)(void*)) {
	//LinkedList *pAux = NULL;
	void *pAuxElement = NULL; // creo una variable void para poder pasarselo como parametro a mi pFunc
	int returnAux = 0;
	int len = ll_len(this);
	if (this != NULL && len > 0) {
			for (int i = 0; i < len; i++) {
				pAuxElement = ll_get(this, i);
				if (pAuxElement != NULL) {
					if (pFunc(pAuxElement) == 1) {
						returnAux++;
						//printf("\n%d\n", returnAux);
					}
				}

			}
	}
	return returnAux;
}
