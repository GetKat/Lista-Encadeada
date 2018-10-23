#include "node.h"
#include <stdio.h>
#include <stdlib.h>

extern struct desc *lista;

void cria_descritor(){
    lista = (struct desc *)malloc(sizeof(struct desc));
    lista->inicio = (struct node *)NULL;
    lista->fim = (struct node *)NULL;
    lista->count = 0;
}

void cria_descritor(struct desc **lista){
    (*lista) = (struct desc *)malloc(sizeof(struct desc));
    (*lista)->inicio = (struct node *)NULL;
    (*lista)->fim = (struct node *)NULL;
    (*lista)->count = 0;
}