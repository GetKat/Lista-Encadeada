#include <stdio.h>
#include <stdlib.h>
#include "node.h"

extern struct desc *lista;

void show_content(){
    struct node *aux;
    aux = lista->inicio;
    if(lista->inicio == (struct node *)NULL)
        printf("Lista vazia!");
    while(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void debug(){
    struct node *aux;

    printf("Lista direta:\n");
    if(lista->inicio == (struct node *)NULL)
        printf("Lista vazia!");  
    aux = lista->inicio;
    while(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");

    printf("Lista inversa:\n");
    if(lista->fim == (struct node *)NULL)
        printf("Lista vazia!");
    aux = lista->fim;
    while(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        aux = aux->prev;
    }
    printf("\n");

    printf("Numero de elementos: %d\n", lista->count);
}