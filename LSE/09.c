#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void inserir_fim(int data);

int main(){
    cria_lista();
    show_content();
    inserir_fim(10);
    show_content();
}

void inserir_fim(int data){
    struct node *aux;
    aux = inicio;
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = (struct node *)NULL;
    }
    else{
        while(aux->next != (struct node *)NULL)
            aux = aux->next;
        aux->next = (struct node *)malloc(sizeof(struct node));
        aux = aux->next;
        aux->data = data;
        aux->next = (struct node *)NULL;
    }
}