#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista();

struct node *inicio;

int main(){
    cria_lista();
    show_content_debug();
}

void cria_lista(){
    struct node *aux;
    int data;
    inicio = (struct node *)NULL;
    scanf("%d", &data);

    if(data >= 0){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->prev = (struct node *)NULL;
        inicio->next = (struct node *)NULL;
        inicio->data = data;
        aux = inicio;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux->next->prev = aux;
            aux->next->next = (struct node *)NULL;
            aux->next->data = data;
            aux = aux->next;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}