#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "eArticulo.h"
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

int saveAsText(char* path , LinkedList* pArrayList)
{
    FILE* f;
    eArticulo* this;
    int len, i, retorno, auxId, auxPrecio, auxRubroId;
    char auxArticulo[50];
    char auxMedida[20];

    if(path!=NULL && pArrayList!=NULL){
        len=ll_len(pArrayList);
       if(fopen(path,"r")!=NULL){
             f=fopen(path,"w");
       }else{
           f=fopen(path,"w");
        }
        if(f!=NULL){
            for(i=0;i<len;i++){
                this=(eArticulo*)ll_get(pArrayList,i);
                if(this!=NULL){
                    eArticulo_getId(this,&auxId);
                    eArticulo_getPrecio(this, &auxPrecio);
                    eArticulo_getMedida(this, auxMedida);
                    eArticulo_getRubroId(this, &auxRubroId);
                    eArticulo_getArticulo(this, auxArticulo);
                    fprintf(f,"%d,%s,%s,%d,%d\n",auxId, auxArticulo, auxMedida, auxPrecio, auxRubroId);
                }
            }
            fclose(f);
            if(i==len){
            	retorno=1;
            }
        }else{
        	retorno=0;
        }

    }

    return retorno;
}

/*
int saveAsBinary(char* path , LinkedList* pArrayList)
{
    FILE* f;
    int retorno=0;
    int i;
    int len= ll_len(pArrayList);
    eArticulo* this;
    if(path != NULL && pArrayList!= NULL){
       if(fopen(path,"rb")!=NULL){
             f=fopen(path,"wb");
        }else{
            f=fopen(path,"wb");
        }
        if(f!=NULL){
                for(i=0;i<len;i++){
                    this=ll_get(pArrayList,i);
                    if(this!= NULL)
                        fwrite(this,sizeof(eArticulo),1,f);
                        }
                if(i==len){
                    retorno=1;
                    fclose(f);
                }else{
                    retorno=0;
                }
            }
    }

    return retorno;
}
*/
