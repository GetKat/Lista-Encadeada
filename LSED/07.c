#include <stdio.h>
#include <stdlib.h>
#include "node.h"

float media();

struct desc *lista;

int main(){
    cria_lista();
    show_content();
    printf("media: %f\n", media());
}

float media(){
    int soma = 0;
    struct node *aux;
    if(lista->count == 0)
        return 0;
    aux = lista->inicio;
    while(aux != (struct node *)NULL){
        soma += aux->data;
        aux = aux->next;
    }
    aux = (struct node *)NULL;
    return (float) soma/lista->count; 
}