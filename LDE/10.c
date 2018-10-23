#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void inserir_fim_rec(int data, struct node *aux);

struct node *inicio;

int main(){
    cria_lista();
    show_content_debug();
    inserir_fim_rec(10, inicio);
    show_content_debug();
}

void inserir_fim_rec(int data, struct node *aux){
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = (struct node *)NULL;
        inicio->prev = (struct node *)NULL;
    }
    else{
        if(aux->next != (struct node *)NULL){
            aux = aux->next;
            inserir_fim_rec(data, aux);
        }
        else{
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux->next->next = (struct node *)NULL;
            aux->next->data = data;
            aux->next->prev = aux;
        }
    }
    aux = (struct node *)NULL;
}