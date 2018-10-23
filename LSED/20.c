#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void deletar_lista_rec();

struct desc *lista;

int main(){
    cria_lista();
    debug();
    deletar_lista_rec();
    debug();
}

void deletar_lista_rec(){
    struct node *aux;
    if(lista->inicio != (struct node *)NULL){
        aux = lista->inicio;
        lista->inicio = lista->inicio->next;
        aux->next = (struct node *)NULL;
        free(aux);
        aux = (struct node *)NULL;
        deletar_lista_rec();
    }
}