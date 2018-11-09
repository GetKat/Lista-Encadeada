#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

float media_rec(struct node *aux, int soma, int count);
void media_rec_alt(struct node *aux, int soma, int count);

int main(){
    cria_lista();
    show_content();
    printf("media: %f\n", media_rec(inicio, 0, 0));
    media_rec_alt(inicio, 0, 0);
}

float media_rec(struct node *aux, int soma, int count){
    if(aux != (struct node *)NULL){
        count++;
        soma += aux->data;
        aux = aux->next;
        return media_rec(aux, soma, count);
    }
    else
        if(count)
            return (float) soma / count;
        else
            return 0;
}

void media_rec_alt(struct node *aux, int soma, int count){
    if(aux != (struct node *)NULL){
        count++;
        soma += aux->data;
        aux = aux->next;
        media_rec_alt(aux, soma, count);
    }
    else
        if(count)
            printf("media: %f\n", (float) soma / count);
        else
            printf("Lista vazia! N tem media!\n");
}