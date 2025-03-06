#include "nodo.h"
#include <stdlib.h>
#include <stdio.h>

nodo* crear_nodo(int dato){
    nodo *n = (nodo*) malloc(sizeof(nodo));
    n->dato= dato;
    n->sig = NULL;
    return n;
}


void borrar_nodo(nodo* n){
    if(n->sig=NULL){
        free(n);
    }
}


void print_nodo(nodo* n){
    printf("Info: %d\n", n->dato);
    printf("Dirección del nodo sig %p\n", n->sig);
}
