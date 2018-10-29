#include <stdio.h>
#include <stdlib.h>
#include "node.h"

extern struct desc *lista;

void cria_descritor(){
    lista = (struct desc *)malloc(sizeof(struct desc));
    lista->inicio = (struct node *)NULL;
    lista->fim = lista->inicio;
    lista->count = 0;
}