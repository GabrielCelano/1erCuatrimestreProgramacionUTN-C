#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "eArticulo.h"


#endif // CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_loadFromBinary(char* path , LinkedList* pArrayList);
int controller_sort(LinkedList* pArrayList);
int controller_List(LinkedList* pArrayList, eRubro* listR);
