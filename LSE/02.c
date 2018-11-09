#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void cria_lista_inv_rec(struct node *aux);

int main(){
    cria_lista_inv_rec((struct node *)NULL);
    show_content();
}

void cria_lista_inv_rec(struct node *aux){
    int data;
    if(aux == (struct node *)NULL)
        inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = inicio;
        inicio = aux;
        cria_lista_inv_rec(aux);
    }
    aux = (struct node *)NULL;
}