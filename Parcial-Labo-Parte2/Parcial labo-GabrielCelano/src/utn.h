#ifndef UTN_H_
#define UTN_H_

#define TAMT 5
#define TAMS 20

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
#endif /* UTN_H_ */
