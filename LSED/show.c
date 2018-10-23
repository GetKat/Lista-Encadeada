#include <stdio.h>
#include <stdlib.h>
#include "node.h"

extern struct desc *lista;

void show_content(void){
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

void show_content(struct desc *lista){
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

void debug(void){
    printf("Contents:\n");
    show_content();
    printf("%d elementos\n", lista->count);
    if(lista->fim != (struct node *)NULL)
        printf("ultimo elemento: %d\n", lista->fim->data);
}

void debug(struct desc *lista){
    printf("Contents:\n");
    show_content(lista);
    printf("%d elementos\n", lista->count);
    if(lista->fim != (struct node *)NULL)
        printf("ultimo elemento: %d\n", lista->fim->data);
}
