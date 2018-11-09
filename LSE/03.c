#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void show_content();

int main(){
    cria_lista();
    show_content();
}

void show_content(){
    struct node *aux;
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!");
    aux = inicio;
    while(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}