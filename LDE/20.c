#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void deletar_lista_rec();

struct node *inicio;

int main(){
    cria_lista();
    show_content_debug();
    deletar_lista_rec();
    show_content_debug();
}

void deletar_lista_rec(){
    struct node *aux;
    if(inicio != (struct node *)NULL){
        aux = inicio;
        inicio = inicio->next;
        aux->next = (struct node *)NULL;
        aux->prev = aux->next;
        free(aux);
        aux = (struct node *)NULL;
        deletar_lista_rec();
    }
}