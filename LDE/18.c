#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista_rec(struct node *aux);

struct node *inicio;

int main(){
    cria_lista_rec((struct node *)NULL);
    debug();
}

void cria_lista_rec(struct node *aux){
    int data;
    if(aux == (struct node *)NULL)
        inicio = (struct node *)NULL;
    scanf("%d", &data);

    if(data >= 0){
        if(inicio == (struct node *)NULL){
            inicio = (struct node *)malloc(sizeof(struct node));
            inicio->prev = (struct node *)NULL;
            inicio->next = (struct node *)NULL;
            inicio->data = data;
            aux = inicio;
        }
        else{
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux->next->prev = aux;
            aux->next->next = (struct node *)NULL;
            aux->next->data = data;
            aux = aux->next;
        }
        cria_lista_rec(aux);
    }
    aux = (struct node *)NULL;
}