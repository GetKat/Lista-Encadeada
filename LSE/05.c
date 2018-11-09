#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

int count_elements();

int main(){
    cria_lista();
    show_content();
    printf("%d elementos\n", count_elements());
}

int count_elements(){
    struct node *aux;
    int count = 0;
    aux = inicio;
    while(aux != (struct node *)NULL){
        count++;
        aux = aux->next;
    }
    return count;
}