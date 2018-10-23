#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void deletar_lista();

struct node *inicio;

int main(){
    cria_lista();
    show_content_debug();
    deletar_lista();
    show_content_debug();
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