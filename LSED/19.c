#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void deletar_lista();

struct desc *lista;

int main(){
    cria_lista();
    debug();
    deletar_lista();
    debug();
}

void deletar_lista(){
    struct node *aux;
    while(lista->inicio != (struct node *)NULL){
        aux = lista->inicio;
        lista->inicio = lista->inicio->next;
        aux->next = (struct node *)NULL;
        free(aux);
        aux = (struct node *)NULL;
    }
}