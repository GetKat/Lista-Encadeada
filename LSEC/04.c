#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void show_content_rec(struct node *aux);

struct node *inicio;

int main(){
    cria_lista();
    show_content_rec(inicio);
}

void show_content_rec(struct node *aux){
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!\n");
    else{
        printf("%d ", aux->data);
        aux = aux->next;
        if(aux != inicio)
               show_content_rec(aux);
        else   
            printf("\n");
    }
    aux = (struct node *)NULL;
}