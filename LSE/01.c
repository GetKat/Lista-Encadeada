#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void cria_lista_inv();

int main(){
    cria_lista_inv();
    show_content();
}

void cria_lista_inv(){
    struct node *aux;
    int data;

    inicio = (struct node *)NULL;
    scanf("%d", &data);
    while(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = inicio;
        inicio = aux;
        scanf("%d", &data);
    }
    aux = (struct node *)NULL;
}