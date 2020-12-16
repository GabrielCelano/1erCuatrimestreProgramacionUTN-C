/*
 ============================================================================
 Name        : Realizar.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void) {
	setbuf(stdout, NULL);
	char i;
	char rta;
	int flaga=0;
	int flagb=0;


        do{
        printf("A) Saludar.\n");
        //BRINDAR
        printf("B) Brindar.\n");
        //DESPEDIRSE
        printf("C) Despedirse.\n");
        //SALIR
        printf("D) Salir.\n");
        __fpurge(stdin);
        scanf("%c",&i);

		switch(i){
		case 'a':
			flaga=1;
			printf("Hola\n");
			printf("\n");
	        break;
		case 'b':
			if(flaga==0){
			 printf("Debe saludar antes de brindar\n");
			 printf("\n");
			 break;
			}
			flagb=1;
			printf("Chin chin\n");
			printf("\n");
			break;
		case 'c':
			if(flaga==0){
				printf("Debe saludar antes de brindar");
				printf("\n");
				break;
			}
			else if(flagb==0){
				printf("Debe brindar antes de despedirse");
				printf("\n");
				break;
			}
			printf("Hasta luego\n");
			printf("\n");
			break;
		case 'd':
			printf("Esta seguro que desea salir(s/n)?\n");
			__fpurge(stdin);
			scanf("%c",&rta);
			break;
		}
      }while(!(rta=='s'||rta=='S'));
    printf("Adios");
	return EXIT_SUCCESS;
}
