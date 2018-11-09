#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void show_content_rec(struct node *aux);

struct desc *lista;

int main(){
    cria_lista();
    show_content_rec(lista->inicio);
}

void show_content_rec(struct node *aux){
    if(lista->inicio == (struct node *)NULL)
        printf("Lista vazia!");
    if(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        aux = aux->next;
        show_content_rec(aux);
    }
    else
        printf("\n");
}