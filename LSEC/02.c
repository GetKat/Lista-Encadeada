#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista_inv_rec(struct node *aux, struct node *fim);

struct node *inicio;

int main(){
    cria_lista_inv_rec((struct node *)NULL, (struct node *)NULL);
    debug();
}

void cria_lista_inv_rec(struct node *aux, struct node *fim){
    int data;
    if(aux == (struct node *)NULL)
        inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        if(fim == (struct node *)NULL){
            fim = (struct node *)malloc(sizeof(struct node));
            fim->data = data;
            fim->next = fim;
            inicio = fim;
            aux = fim;
        }
        else{
            aux = (struct node *)malloc(sizeof(struct node));
            aux->data = data;
            aux->next = inicio;
            inicio = aux;
            fim->next = inicio;
        }
        cria_lista_inv_rec(aux, fim);
    }
    aux = (struct node *)NULL;
    aux = fim;
}