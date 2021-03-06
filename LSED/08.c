#include <stdio.h>
#include <stdlib.h>
#include "node.h"

float media_rec(struct node *aux, int soma);

struct desc *lista;

int main(){
    cria_lista();
    show_content();
    printf("media_rec: %f\n", media_rec(lista->inicio, 0));
}

float media_rec(struct node *aux, int soma){
    if(lista->count == 0)
        return 0;
    if(aux != (struct node *)NULL){
        soma += aux->data;
        aux = aux->next;
        return media_rec(aux, soma);
    }
    else{
        aux = (struct node *)NULL;
        return (float) soma/lista->count; 
    }
}