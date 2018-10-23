#include <stdio.h>
#include <stdlib.h>
#include "node.h"

extern struct node *inicio;

void show(){
    struct node *aux;
    aux = inicio;
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!");
    while(aux != (struct node *)NULL){
        printf("%d ");
        aux = aux->next;
    }
    printf("\n");
}

void show(struct node *aux){
    if(aux == (struct node *)NULL)
        printf("Lista vazia!");
    while(aux != (struct node *)NULL){
        printf("%d ");
        aux = aux->next;
    }
    printf("\n");
}