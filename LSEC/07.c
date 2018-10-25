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
    int count = 0, soma = 0;
    aux = inicio;
    if(inicio == (struct node *)NULL)
        return 0;
    count++;
    soma += aux->data;
    aux = aux->next;
    while(aux != inicio){
        count++;
        soma += aux->data;
        aux = aux->next;
    }
    aux = (struct node *)NULL;
    return (float) soma / count;
}