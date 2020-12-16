#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

static int esNumerica(char *cadena, int limite);
static int getInt(int *pResultado);
static int esFlotante(char *cadena);
static int getFloat(float *pResultado);
static int getString(char *cadena, int longitud);
static int esNombre(char *cadena, int longitud);
static int getNombre(char *pResultado, int longitud);

/**
 * @brief
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return
 */
int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {
	int retorno = -1;
	char buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			__fpurge(stdin);
			scanf("%c", &buffer);
			if (buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char *cadena, int longitud) {
	int retorno = -1;
	char bufferString[4096]; // *****************************

	if (cadena != NULL && longitud > 0) {

		__fpurge(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int *pResultado) {
	int retorno = -1;
	char bufferString[50];
	if (pResultado != NULL && getString(bufferString, sizeof(bufferString)) == 0
			&& esNumerica(bufferString, sizeof(bufferString))) {
		retorno = 0;
		*pResultado = atoi(bufferString);

	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char *cadena, int limite) {
	int retorno = -1; // ERROR
	int i;
	if (cadena != NULL && limite > 0) {
		retorno = 1; // VERDADERO
		for (i = 0; i < limite && cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int bufferInt;
	do {
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0 && bufferInt >= minimo
				&& bufferInt <= maximo) {
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s", mensajeError);
		reintentos--;
	} while (reintentos >= 0);

	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {
		if (getString(buffer, sizeof(buffer)) == 0 && esFlotante(buffer)) {
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char *cadena) {
	int i = 0;
	int retorno = 1;
	int contadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '-' || cadena[i] == '+')) {
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				if (cadena[i] == '.' && contadorPuntos == 0) {
					contadorPuntos++;
				} else {
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {
	float bufferFloat;
	int retorno = -1;
	while (reintentos >= 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0) {
			if (bufferFloat >= minimo && bufferFloat <= maximo) {
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char *pResultado, int longitud) {
	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL) {
		if (getString(buffer, sizeof(buffer)) == 0
				&& esNombre(buffer, sizeof(buffer))
				&& strnlen(buffer, sizeof(buffer)) < longitud) {

			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char *cadena, int longitud) {
	int i = 0;
	int retorno = 1;

	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char *pResultado, int longitud, char *mensaje,
		char *mensajeError, int reintentos) {
	char bufferString[4096];
	int retorno = -1;
	while (reintentos >= 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getNombre(bufferString, sizeof(bufferString)) == 0
				&& strnlen(bufferString, sizeof(bufferString)) < longitud) {
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int utn_getCadena(char *pAux, int limite, int reintentos, char *msj,
		char *msjError) {
	int retorno = -1;
	char auxString[limite];
	if (pAux != NULL && limite > 0 && reintentos >= 0) {
		do {
			reintentos--;
			printf("%s", msj);
			if (getCadena(auxString, limite) == 0 && isLetras(auxString) == 0) {
				strncpy(pAux, auxString, limite);
				retorno = 0;
				break;
			} else
				printf("%s", msjError);
		} while (reintentos >= 0);
	}
	return retorno;
}

int isLetras(char *pAux) {
	int retorno = -1;
	int i = 0;
	if (pAux != NULL) {
		do {
			if ((*(pAux + i) < 65 || *(pAux + i) > 90)
					&& (*(pAux + i) < 97 || *(pAux + i) > 122)) {
				break;
			}
			i++;
		} while (i < strlen(pAux));
		if (i == strlen(pAux)) {
			retorno = 0;
		}
	}
	return retorno;
}

int getCadena(char *pAux, int limite) {
	char auxString[2000];
	int retorno = -1;
	if (pAux != NULL && limite > 0) {
		__fpurge(stdin);
		fgets(auxString, sizeof(auxString), stdin);
		if (auxString[strlen(auxString) - 1] == '\n') {
			auxString[strlen(auxString) - 1] = '\0';
		}
		if (strlen(auxString) <= limite) {
			strncpy(pAux, auxString, limite);
			retorno = 0;
		}
	}
	return retorno;
}

char preguntarSiEstaSeguro(char *msg, char *msgerror) {
	char confirma;

	if (msg != NULL && msgerror != NULL) {
		printf("%s", msg);
		__fpurge(stdin);
		scanf("%c", &confirma);
		confirma = tolower(confirma);

		while (confirma != 's' && confirma != 'n') {
			printf("%s", msgerror);
			__fpurge(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);
		}
	}
	return confirma;
}