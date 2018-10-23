#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void inserir_fim(int data);

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    inserir_fim(10);
    show_content();
}

void inserir_fim(int data){
    struct node *aux;
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = (struct node *)NULL;
        inicio->prev = (struct node *)NULL;
    }
    else{
        aux = inicio;
        while(aux->next != (struct node *)NULL){
            aux = aux->next;
        }
        aux->next = (struct node *)malloc(sizeof(struct node));
        aux->next->next = (struct node *)NULL;
        aux->next->data = data;
        aux->next->prev = aux;
    }
    aux = (struct node *)NULL;
}