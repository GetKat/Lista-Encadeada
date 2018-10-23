#include "node.h"
#include <stdio.h>
#include <stdlib.h>

extern struct node *inicio;

void cria_lista(){
    struct node *aux;
    int data;
    inicio = (struct node *)NULL;
    scanf("%d", &data);

    if(data >= 0){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->prev = (struct node *)NULL;
        inicio->next = (struct node *)NULL;
        inicio->data = data;
        aux = inicio;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux->next->prev = aux;
            aux->next->next = (struct node *)NULL;
            aux->next->data = data;
            aux = aux->next;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}

void cria_lista(struct node **inicio){
    struct node *aux;
    int data;
    scanf("%d", &data);
    *inicio = (struct node *)NULL;
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->prev = (struct node *)NULL;
        aux->next = (struct node *)NULL;
        *inicio = aux;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux->next->prev = aux;
            aux->next->next = (struct node *)NULL;
            aux->next->data = data;
            aux = aux->next;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}