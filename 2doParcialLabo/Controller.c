#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"
#include "eArticulo.h"


int controller_loadFromText(char *path, LinkedList *pArrayList) {
	FILE* f;
    int retorno = -1;
    if(path!=NULL && pArrayList!=NULL)
    {
        strcat(path,".csv");
        //printf("\n%s\n", path);
        f=fopen(path,"r");
        //printf("\n%p\n", f);
        if(f!=NULL){
            parser_FromText(f,pArrayList);
            fclose(f);
            retorno=0;
        }
    }
    return retorno;
}

/*
int controller_loadFromBinary(char* path , LinkedList* pArrayList)
{
    FILE* f;
    int retorno=0;

    if(path!=NULL && pArrayList!=NULL){
        f = fopen(path,"rb");
        if(f!=NULL){
            parser_FromBinary(f,pArrayList);
            fclose(f);
            retorno=1;
        }else{
            retorno=0;
        }

    }


    return retorno;
}
*/

int controller_sort(LinkedList* pArrayList)
{
    int retorno = -1;
    if(pArrayList!=NULL){
        ll_sort(pArrayList,compareByName,1);
        retorno=0;
    }
    return retorno;
}
int controller_List(LinkedList* pArrayList, eRubro* listR)
{
    eArticulo* aux;
    int retorno = -1;
    int len;
    if(pArrayList!=NULL){
        len=ll_len(pArrayList); // busco el tamanio de mi lista y la guardo en len
        //printf("\n%d\n", len);
        //system("cls");
        printf("\n                                            %s\n", "LISTA DE ARTICULOS:");
        printf("\n%2s %35s %10s       %3s %35s\n","ID", "ARTICULOS", "MEDIDA", "PRECIO", "RUBRO");
        for(int i=0;i<len;i++){
            aux=(eArticulo*)ll_get(pArrayList,i);
            printArticulo(aux, listR);
            retorno=0;
        }
    }

    return retorno;
}
