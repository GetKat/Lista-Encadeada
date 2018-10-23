#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <conio.h>

float media_rec(struct node *aux, int count, int soma);
float media(struct node *aux, int cont, float soma);

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    printf("media_rec: %f\n", media_rec(inicio, 0, 0));
    getch();
}

float media_rec(struct node *aux, int count, int soma){
    if(inicio == (struct node *)NULL)
        return 0;
    if(aux != (struct node *)NULL){
        soma += aux->data;
        count++;
        aux = aux->next;
        return media_rec(aux, count, soma);
    }
    else
        return (float) soma/count; 
}