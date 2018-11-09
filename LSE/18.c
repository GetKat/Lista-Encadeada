#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void cria_lista_rec(struct node *aux);

int main(){
    cria_lista_rec((struct node *)NULL);
    show_content();
}

void cria_lista_rec(struct node *aux){ 
    int data;
    if(aux == (struct node *)NULL)
        inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        if(inicio == (struct node *)NULL){
            inicio = (struct node *)malloc(sizeof(struct node));
            inicio->data = data;
            inicio->next = (struct node *)NULL;
            aux = inicio;
        }
        else{
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = (struct node *)NULL;
        }
       cria_lista_rec(aux);
    }
    aux = (struct node *)NULL;
}