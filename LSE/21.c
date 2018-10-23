#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void ordenar();

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    ordenar();
    show_content();
}

void ordenar(){
    int temp;
    struct node *aux, *it;
    aux = inicio;
    while(aux != (struct node *)NULL){
        it = aux->next;
        while(it != (struct node *)NULL){
            if(aux->data > it->data){
                temp = aux->data;
                aux->data = it->data;
                it->data = temp;
            }
            it = it->next;
        }
        aux = aux->next;
    }
}