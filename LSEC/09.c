#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void inserir_fim(int data);

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    inserir_fim(10);
    debug();
}

void inserir_fim(int data){
    struct node *aux;
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = inicio;
    }
    else{
        aux = inicio;
        aux = aux->next;
        while(aux->next != inicio)
            aux = aux->next;
        aux->next = (struct node *)malloc(sizeof(struct node));
        aux = aux->next;
        aux->data = data;
        aux->next = inicio;
    }
    aux = (struct node *)NULL;
}