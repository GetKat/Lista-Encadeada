#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void cria_lista();

int main(){
    cria_lista();
    show_content();
}

void cria_lista(){
    struct node *aux;
    int data;

    inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = (struct node *)NULL;
        aux = inicio;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = (struct node *)NULL;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}