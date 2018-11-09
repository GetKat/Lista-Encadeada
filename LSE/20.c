#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void deletar_lista_rec();

int main(){
    cria_lista();
    deletar_lista_rec();
    show_content();
}

void deletar_lista_rec(){
    struct node *aux;
    if(inicio != (struct node *)NULL){
        aux = inicio;
        inicio = inicio->next;
        aux->next = (struct node *)NULL;
        free(aux);
        aux = (struct node *)NULL;
        deletar_lista_rec();
    }
}