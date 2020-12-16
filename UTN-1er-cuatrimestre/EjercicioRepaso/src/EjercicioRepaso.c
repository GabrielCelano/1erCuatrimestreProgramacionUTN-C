/*
 ============================================================================
 Name        : EjercicioRepaso.c
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
	int edad = 0;
	int temp = 0;
	int contf=0;
	int contm=0;
	int contedad=0;
	int acuedad=0;
	float prome=0;
	int flag=0;
	int acut=0;
	int acunf;
	char sexo;
	int i;
	char ini;

	for (i = 0; i < 5; i++){
		// NOMBRE
		printf("Ingresar inicial de su nombre: \n ");
		__fpurge(stdin);
		scanf("%c", &ini);
		while (!isalpha(ini)) {
			printf("Inicial no valida. Por favor ingresar de nuevo: \n");
			__fpurge(stdin);
			scanf("%c", &ini);
		}

		//SEXO
		printf("Ingresar sexo(f/m): \n");
		__fpurge(stdin);
		scanf("%c", &sexo);
		while (!(sexo=='f'||sexo=='m')){
			printf("Sexo ingresado incorrecto. Por favor ingresar de nuevo(f/m): \n");
			__fpurge(stdin);
			scanf("%c", &sexo);
		}

		//EDAD
		printf("Ingresar edad: \n");
		__fpurge(stdin);
		scanf("%d" ,&edad);
		while(edad < 1){
			printf("Edad ingresado incorrecta. Volver a ingresar: \n");
            __fpurge(stdin);
			scanf("%d" ,&edad);
		}

		//TEMPERATURA
		printf("Ingresar temperatura: \n");
		__fpurge(stdin);
		scanf("%d", &temp);
		while(temp < 35 || temp > 38){
			printf("Temperatura ingresada incorrecta. Por favor ingresar de nuevo: \n");
			__fpurge(stdin);
			scanf("%d", &temp);
		}

		// Cantidad cada sexo
		if(sexo=='f'){
            contf++;
            if(flag==0){
            	flag=1;
            	acut=temp;
            	acunf=ini;
            }
            else if(flag==1&&temp>acut){
            	acut=temp;
            	acunf=ini;
            }
		}
		else if(sexo=='m'){
			contm++;
		}

		// Edad promedio
		contedad++;
		acuedad=acuedad+edad;
		prome=(float)acuedad/contedad;
	}

	printf("Se ingresaron %d hombres y %d mujeres.\n", contm,contf);
	printf("La edad promedio es de: %d\n", prome);
	printf("La mujer con mas temperatura es: %c\n",acunf);
}
