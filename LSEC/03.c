#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void show_content();

struct node *inicio;

int main(){
    cria_lista();
    show_content();
}

void show_content(){
    struct node *aux;
    aux = inicio;
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!");
    else
        do{
            printf("%d ", aux->data);
            aux = aux->next;
        }while(aux != inicio);
    aux = (struct node *)NULL;
    printf("\n");
}