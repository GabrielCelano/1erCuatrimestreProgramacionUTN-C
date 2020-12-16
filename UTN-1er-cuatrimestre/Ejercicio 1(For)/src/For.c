/*
 ============================================================================
 Name        : For.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int i=0, numero, contador=0;
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	for(i=1;i<=numero;i++)
	{
      if (numero % i == 0){
    	  contador++;
    	  printf("\n%d, Es divisor de %d", i, numero);
      }
	}
    printf("\n La cantidad total de numeros divisores es %d", contador);
}
