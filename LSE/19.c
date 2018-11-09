#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void deletar_lista();

int main(){
    cria_lista();
    deletar_lista();
    show_content();
}

void deletar_lista(){
    struct node *aux;
    while(inicio != (struct node *)NULL){
        aux = inicio;
        inicio = inicio->next;
        aux->next = (struct node *)NULL;
        free(aux);
        aux = (struct node *)NULL;
    }
}