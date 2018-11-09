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
    struct node *aux;
    int soma = 0;
    if(lista->inicio == (struct node *)NULL)
        return 0;
    aux = lista->inicio;
    while(aux != (struct node *)NULL){
        soma += aux->data;
        aux = aux->next;
    }
    return (float) soma / lista->count;
}