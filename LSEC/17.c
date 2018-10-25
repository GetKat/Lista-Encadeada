#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista();

struct node *inicio;

int main(){
    cria_lista();
    debug();
}

void cria_lista(){
    struct node *aux;
    int data;
    inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = aux;
        inicio = aux;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = inicio;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}
