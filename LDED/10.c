#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void inserir_fim_rec(int data);

struct desc *lista;

int main(){
    cria_lista();
    show_content();
    inserir_fim_rec(10);
    debug();
    inserir_fim_rec(10);
    debug();
}

void inserir_fim_rec(int data){
    struct node *aux;
    if(lista->inicio == (struct node *)NULL){
        aux = lista->inicio;
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = (struct node *)NULL;
        aux->prev = (struct node *)NULL;
        lista->inicio = aux;
        lista->fim = lista->inicio;
    }
    else{
        aux = lista->fim;
        aux->next = (struct node *)malloc(sizeof(struct node));
        aux->next->data = data;
        aux->next->next = (struct node *)NULL;
        aux->next->prev = aux;
        lista->fim = aux->next;
    }
    lista->count++;
    aux = (struct node *)NULL;
}