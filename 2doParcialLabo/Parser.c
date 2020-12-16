#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eArticulo.h"
#include "utn.h"
#include "Parser.h"


int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    char buffer[5][50];
    int cant,retorno=0;
    eArticulo* pAux;

    if(pFile!=NULL && pArrayList!=NULL)
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
        while(!feof(pFile)){
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            //printf("%5s %20s %12s %10s %10s\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            pAux=eArticulo_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            if(pAux!=NULL){
                ll_add(pArrayList,pAux);
                retorno=1;
            }
            if(cant < 5){
                if(feof(pFile)){
                    break;
                }else{
                    retorno=0;
                    break;
                }
            }
        }
    }
    return retorno;
}

/*
int parser_FromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int retorno=0,cant=0;
    eArticulo* new;
    if(pFile!=NULL && pArrayList!= NULL){
        while(!feof(pFile)){
            new=eArticulo_new();
           cant = fread(new,sizeof(eArticulo),1,pFile);
            if(new!=NULL){
                if(eArticulo_isValid(new)==1){
                    ll_add(pArrayList,new);
                    retorno=1;
                }else{
                    eArticulo_delete(new);
                }
            }
            if(cant<1){
                if(feof(pFile)){
                break;
                }else{
                    retorno=0;
                    break;
                }
            }
        }
    }

    return retorno;
}
*/
