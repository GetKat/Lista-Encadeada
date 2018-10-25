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
            aux = (struct node *)malloc(sizeof(struct node));
            aux->data = data;
            aux->next = aux;
            inicio = aux;
        }
        else{
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = inicio;
        }
        cria_lista_rec(aux);
    }
    aux = (struct node *)NULL;
}
