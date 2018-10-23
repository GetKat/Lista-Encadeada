#include <stdio.h>
#include <stdlib.h>
#include "node.h"

float media();

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    printf("media: %f\n", media());
}

float media(){
    struct node *aux;
    int soma = 0, count = 0;
    if(inicio == (struct node *)NULL)
        return 0;
    aux = inicio;
    while(aux != (struct node *)NULL){
        soma += aux->data;
        count++;
        aux = aux->next;
    }
    return (float) soma/count;
}