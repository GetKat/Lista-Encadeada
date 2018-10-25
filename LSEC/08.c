#include <stdio.h>
#include <stdlib.h>
#include "node.h"

float media_rec(struct node *aux, int soma, int count);

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    printf("media_rec: %f\n", media_rec(inicio, 0, 0));
}

float media_rec(struct node *aux, int soma, int count){
    if(inicio == (struct node *)NULL)
        return 0;
    soma += aux->data;
    count++;
    aux = aux->next;
    if(aux != inicio)
        return media_rec(aux, soma, count);
    else
        return (float) soma / count;
}