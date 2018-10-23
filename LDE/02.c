#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct node *inicio;

void cria_lista_inv_rec(struct node *aux);

int main(){
    cria_lista_inv_rec((struct node *)NULL);
    show_content_debug();
}

void cria_lista_inv_rec(struct node *aux){
    int data;
    if(aux == (struct node *)NULL)
        inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        if(inicio != (struct node *)NULL)
            inicio->prev = aux;
        aux->next = inicio;
        aux->data = data;
        aux->prev = (struct node *)NULL;
        inicio = aux;
        cria_lista_inv_rec(aux);   
    }
    aux = (struct node *)NULL;
}