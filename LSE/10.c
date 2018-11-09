#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void inserir_fim_rec(struct node *aux, int data);

int main(){
    cria_lista();
    show_content();
    inserir_fim_rec(inicio, 10);
    show_content();
}

void inserir_fim_rec(struct node *aux, int data){
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = (struct node *)NULL;
    }
    else
        if(aux->next != (struct node *)NULL)
            inserir_fim_rec(aux->next, data);
        else{
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = (struct node *)NULL;
        }
}