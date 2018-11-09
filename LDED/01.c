#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista_inv();

struct desc *lista;

int main(){
    cria_lista_inv();
    debug();
}

void cria_lista_inv(){
    struct node *aux;
    int data;
    cria_descritor();
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = (struct node *)NULL;
        aux->prev = aux->next;
        lista->inicio = aux;
        lista->fim = lista->inicio;
        lista->count++;
        scanf("%d", &data);
        while(data >= 0){
            // aux = (struct node *)malloc(sizeof(struct node));
            // aux->data = data;
            // aux->next = lista->inicio;
            // aux->next->prev = aux;
            // aux->prev = (struct node *)NULL;
            // lista->inicio = aux;
            aux->prev = (struct node *)malloc(sizeof(struct node));
            aux->prev->next = aux;
            aux->prev->prev = (struct node *)NULL;
            aux->prev->data = data;
            aux = aux->prev;
            lista->inicio = aux;
            lista->count++;
            scanf("%d", &data);
        }
    }
}