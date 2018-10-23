#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista_inv();

struct desc *lista;

int main(){
    cria_lista_inv();
    show_content();
}

void cria_lista_inv(){
    struct node *aux;
    int data;
    cria_descritor();
    scanf("%d", &data);
    while(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = lista->inicio;
        lista->inicio = aux;
        lista->count++;
        if(lista->fim == (struct node *)NULL)
            lista->fim = aux;
        scanf("%d", &data);
    }
    aux = (struct node *)NULL;
}