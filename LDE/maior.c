#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

int maior();

int main(){
    cria_lista();
    show_content();
    printf("maior: %d\n", maior());
}

int maior(){
    struct node *aux;
    if(inicio == (struct node *)NULL)
        return 0;
    int data = inicio->data;
    aux = inicio;
    while(aux != (struct node *)NULL){
        if(aux->data > data)
            data = aux->data;
        aux = aux->next;
    }
    return data;
}