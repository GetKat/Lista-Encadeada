#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void deletar_lista();

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    deletar_lista();
    show_content();
}

void deletar_lista(){
    struct node *aux, *fim;
    aux = inicio;
    if(inicio != (struct node *)NULL){
        fim = inicio;
        while(fim->next != inicio)
            fim = fim->next;
        fim->next = (struct node *)NULL;
        aux = inicio;
        while(inicio != (struct node *)NULL){
            aux = inicio;
            inicio = inicio->next;
            aux->next = (struct node *)NULL;
            free(aux);
            aux = (struct node *)NULL;
        }
    }
    aux = (struct node *)NULL;
    fim = aux;
}