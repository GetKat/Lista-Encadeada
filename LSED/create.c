#include <stdio.h>
#include <stdlib.h>
#include "node.h"

extern struct desc *lista;

void cria_lista(){
    int data;
    struct node *aux;
    cria_descritor();
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = (struct node *)NULL;
        lista->inicio = aux;
        lista->fim = aux;
        lista->count++;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = (struct node *)NULL;
            lista->fim = aux;
            lista->count++;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}

void cria_lista(struct desc **lista){
    int data;
    struct node *aux;
    cria_descritor(lista);
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = (struct node *)NULL;
        (*lista)->inicio = aux;
        (*lista)->fim = aux;
        (*lista)->count++;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = (struct node *)NULL;
            (*lista)->fim = aux;
            (*lista)->count++;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}