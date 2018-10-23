#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista_inv_rec(struct node *aux);

struct desc *lista;

int main(){
    cria_lista_inv_rec((struct node *)NULL);
    debug();
}

void cria_lista_inv_rec(struct node *aux){
    int data;
    if(aux == (struct node *)NULL)
        cria_descritor(); 
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = lista->inicio;
        lista->inicio = aux;
        lista->count++;
        if(lista->fim == (struct node *)NULL)
            lista->fim = aux;
        cria_lista_inv_rec(aux);
    }
    aux = (struct node *)NULL;
}