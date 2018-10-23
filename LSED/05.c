#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int count();

struct desc *lista;

int main(){
    cria_lista();
    printf("%d elementos\n", count());
}

int count(){
    return lista->count;
}