#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista_rec(struct node *aux);

struct desc *lista;

int main(){
    cria_lista_rec((struct node *)NULL);
    debug();
}

void cria_lista_rec(struct node *aux){
    int data;
    if(aux == (struct node *)NULL)
        cria_descritor();
    scanf("%d", &data);
    if(data >= 0){
        if(lista->inicio == (struct node *)NULL){
            aux = (struct node *)malloc(sizeof(struct node));
            lista->inicio = aux;
        }
        else{
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
        }
        aux->data = data;
        aux->next = (struct node *)NULL;
        lista->count++;
        lista->fim = aux;
        cria_lista_rec(aux);
    }
    aux = (struct node *)NULL;
}