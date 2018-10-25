#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista_inv();

struct node *inicio;

int main(){
    cria_lista_inv();
    debug();
}

void cria_lista_inv(){
    struct node *aux, *fim;
    int data;
    inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        fim = (struct node *)malloc(sizeof(struct node));
        fim->data = data;
        fim->next = fim;
        inicio = fim;
        scanf("%d", &data);
        while(data >= 0){
            aux = (struct node *)malloc(sizeof(struct node));
            aux->data = data;
            aux->next = inicio;
            inicio = aux;
            fim->next = inicio;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
    aux = fim;
}