#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int count_elements();

struct desc *lista;

int main(){
    cria_lista();
    show_content();
    printf("%d elementos\n", count_elements());
}

int count_elements(){
    return lista->count;
}