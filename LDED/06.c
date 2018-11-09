#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int count_elements_rec();

struct desc *lista;

int main(){
    cria_lista();
    show_content();
    printf("%d elementos\n", count_elements_rec());
}

int count_elements_rec(){
    return lista->count;
}