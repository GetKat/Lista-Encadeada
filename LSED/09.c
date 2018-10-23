#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void inserir_fim(int data);

struct desc *lista;

int main(){
    cria_lista();
    show_content();
    inserir_fim(10);
    show_content();
}

void inserir_fim(int data){
    if(lista->inicio == (struct node *)NULL){
        lista->inicio = (struct node *)malloc(sizeof(struct node));
        lista->inicio->data = data;
        lista->inicio->next = (struct node *)NULL;
        lista->fim = lista->inicio;
    }
    else{
        lista->fim->next = (struct node *)malloc(sizeof(struct node));
        lista->fim = lista->fim->next;
        lista->fim->data = data;
        lista->fim->next = (struct node *)NULL;
    }
}