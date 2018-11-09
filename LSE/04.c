#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void show_content_rec(struct node *aux);

int main(){
    cria_lista();
    show_content_rec(inicio);
}

void show_content_rec(struct node *aux){
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!");
    if(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        aux = aux->next;
        show_content_rec(aux);
    }
    else
        printf("\n");
}