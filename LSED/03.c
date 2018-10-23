#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void show_content();

struct desc *lista;

int main(){
    cria_lista();
    show_content();
}

void show_content(){
    struct node *aux;
    aux = lista->inicio;
    if(aux == (struct node *)NULL)
        printf("Lista vazia!");
    while(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }
    aux = (struct node *)NULL;
    printf("\n");
}