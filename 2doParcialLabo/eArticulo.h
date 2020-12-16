#ifndef EARTICULO_H_INCLUDED
#define EARTICULO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[50];
}eRubro;

typedef struct
{
    int id;
    char articulo[50];
    char medida[20];
    int precio;
    int rubroId;
}eArticulo;

#endif // EARTICULO_H_INCLUDED
//void eArticulo_delete(eArticulo* this);

//SETTERS Y GETTERS
/** \brief Setea un nuevo valor de ID
 *
 * \param Puntero a la estructura eArticulo
 * \param Int ID
 * \return retorna validacion 1 todoOk y 0 error
 *
 */
int eArticulo_setId(eArticulo* this,int id);

/** \brief Busca el valor de ID
 *
 * \param Puntero a la estructura eArticulo
 * \param INT
 * \return retorna validacion 1 todoOk y 0 error
 *
 */
int eArticulo_getId(eArticulo* this,int* id);

/** \brief Setea un nuevo valor en Articulo
 *
 * \param Puntero a la estructura eArticulo
 * \param Puntero CHAR
 * \return retorna validacion 1 todoOk y 0 error
 *
 */
int eArticulo_setArticulo(eArticulo* this,char* auxNombre);

/** \brief Busca el valor de Articulo
 *
 * \param Puntero a la estructura eArticulo
 * \param Puntero CHAR
 * \return retorna validacion 1 todoOk y 0 error
 *
 */
int eArticulo_getArticulo(eArticulo* this,char* auxNombre);

/** \brief Setea el nuevo valor de Articulo
 *
 * \param Puntero a la estructura eArticulo
 * \param INT
 * \return retorna validacion 1 todoOk y 0 error
 *
 */
int eArticulo_setPrecio(eArticulo* this,int auxPrecio);

/** \brief Busca el valor de precio
 *
 * \param Puntero a la estructura eArticulo
 * \param Puntero INT
 * \return retorna validacion 1 todoOk y 0 error
 *
 */
int eArticulo_getPrecio(eArticulo* this,int* auxPrecio);

/** \brief Setea el nuevo valor de medida
 *
 * \param this Puntero a la estructura eArticulo
 * \param Puntero CHAR
 * \return retorna validacion 1 todoOk y 0 error
 *
 */
int eArticulo_setMedida(eArticulo* this,char* auxMedida);

/** \brief Busca el valor de medida
 *
 * \param this Puntero a la estructura eArticulo
 * \param Puntero CHAR
 * \return retorna validacion 1 todoOk y 0 error
 *
 */
int eArticulo_getMedida(eArticulo* this,char* auxMedida);

/** \brief Setero el nuevo valor de rubroId
 *
 * \param this Puntero a la lista
 * \param INT
 * \return retorna validacion 1 todoOk y 0 error
 *
 */
int eArticulo_setRubroId(eArticulo* this,int auxRubroId);

/** \brief Busco el valor de rubroId
 *
 * \param this Puntero a la lista
 * \param Puntero INT
 * \return retorna validacion 1 todoOk y 0 error
 *
 */
int eArticulo_getRubroId(eArticulo *this, int *auxRubroId);
eArticulo* eArticulo_new();

/** \brief Seteo los nuevos valores para cada campo de mi estructura
 *
 * \param CHAR* puntero a idStr
 * \param CHAR* puntero a nombreArticuloStr
 * \param CHAR* puntero a precioStr
 * \param CHAR* puntero a medidaStr
 * \param CHAR* puntero a rubroId
 */
eArticulo* eArticulo_newParametros(char* idStr,char* nombreArticuloStr, char* precioStr, char* medidaStr, char* rubroId);


/** \brief Valido que los seteas cumplan su condicion
 *
 * \param pAux eArticulo* puntero a lista
 * \return Retorna 0 si esta todo OK, -1 si es error
 *
 */
int eArticulo_isValid(eArticulo* pAux);

/** \brief Menu principal
 * \return Retorna el valor de la seleccion del menu
 */
int menu();

/** \brief Menu de informes
 * \return Retorna el valor de la seleccion del menu
 */
int menuInformes();

/** \brief Imprimo el articulo pasado por parametro
 *
 * \param this eArticulo* puntero a la lista
 * \param listR eRubro* puntero a la estructura eRubro
 * \return Retorna 0 si esta todo OK, -1 si es error
 */
int printArticulo(eArticulo* this, eRubro* listR);

/** \brief Comparo dos articulos para ordenarlos
 *
 * \param void* Puntero a eArt1
 * \param void* Puntero a eArt2
 * \return Retorna 1 si artB es menor a artA, -1 si artA es menor a artB y 0 si son iguales
 */
int compareByName(void* eArt1, void* eArt2);

/** \brief Realiza el calculo a criterio
 *
 * \param void* puntero a pAux
 * \return Retorna la nueva lista
 *
 */
void* eArticulo_llmap(void* pAux);

/** \brief Filtra que tipo de rubro es
 *
 * \param void* puntero a pAux
 * \return Retorna que rubro es
 *
 */
int eArticulo_filterRubro(void* pAux);

/** \brief Hardcodeo los rubros
 *
 * \param listR eRubro* puntero a la estructura
 * \param int len tamanio del hardcodeo
 * \return void
 *
 */
void harcodearRubros(eRubro* listR, int len);

/*
void listarRubros(eRubro* listR, int len);
void printRubro(eRubro* listR, int i);
*/

/** \brief Filtro los articulos por criterio
 *
 * \param void* pAux puntero
 * \return retorno 1 si se cumple el criterio, retorno 0 si no se cumple
 *
 */
int eArticulo_filterPrecioArticulo(void* pAux);

/** \brief Filtro los precios por criterio
 *
 * \param void* pAux puntero
 * \return retorno 1 si se cumple el criterio, retorno 0 si no se cumple
 *
 */
int eArticulo_filterRubro1(void* pAux);
