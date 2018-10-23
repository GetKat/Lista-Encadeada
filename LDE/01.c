#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct node *inicio;

void cria_lista_inv();

int main(){
    cria_lista_inv();
    show_content();
}

void cria_lista_inv(){
    int data;
    struct node *aux;
    inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = (struct node *)NULL;
        aux->prev = (struct node *)NULL;
        inicio = aux;
        scanf("%d", &data);
        while(data >= 0){
            aux = (struct node *)malloc(sizeof(struct node));
            aux->data = data;
            aux->prev = (struct node *)NULL;
            aux->next = inicio;
            inicio->prev = aux;
            inicio = aux;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}