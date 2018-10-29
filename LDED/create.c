#include <stdio.h>
#include <stdlib.h>
#include "node.h"

extern struct desc *lista;

void cria_lista(){
    struct node *aux;
    int data;
    cria_descritor();
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->prev = (struct node *)NULL;
        aux->next = aux->prev;
        lista->inicio = aux;
        lista->fim = lista->inicio;
        lista->count++;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux->next->prev = aux;
            aux->next->data = data;
            aux->next->next = (struct node *)NULL;
            aux = aux->next;
            lista->fim = aux;
            lista->count++;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}