#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void inserir_fim_rec(int data, struct node *aux);

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    inserir_fim_rec(10, inicio);
    debug();
}

void inserir_fim_rec(int data, struct node *aux){
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = inicio;
    }
    else{
        aux = aux->next;
        if(aux->next != inicio){
            aux = aux->next;
            inserir_fim_rec(data, aux);
        }
        else{
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = inicio;
        }
    }
    aux = (struct node *)NULL;
}