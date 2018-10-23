#include "node.h"
#include <stdio.h>
#include <stdlib.h>

struct node *inicio;

int count_elements();

int main(){
    cria_lista();
    show_content();
    printf("%d elementos\n", count_elements());
}

int count_elements(){
    int count = 0;
    struct node *aux;
    aux = inicio;
    while(aux != (struct node *)NULL){
        count++;
        aux = aux->next;
    }
    aux = (struct node *)NULL;
    return count;
}