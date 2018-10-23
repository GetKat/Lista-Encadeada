#include <stdio.h>
#include <stdlib.h>
#include "node.h"

extern struct node *inicio;

void cria_lista(){
    int data;
    struct node *aux;
    inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = (struct node *)NULL;
        inicio = aux;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = (struct node *)NULL;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}

void cria_lista(struct node **inicio){
    int data;
    struct node *aux;
    *inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = (struct node *)NULL;
        (*inicio) = aux;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = (struct node *)NULL;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}