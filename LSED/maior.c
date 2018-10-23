#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int maior();

struct desc *lista;

int main(){
    cria_lista();
    show_content();
    printf("maior: %d\n", maior());
}

int maior(){
    int maior_data;
    struct node *aux;
    if(lista->count == 0)
        return 0;
    aux = lista->inicio;
    maior_data = lista->inicio->data;
    while(aux != (struct node *)NULL){
        if(aux->data > maior_data)
            maior_data = aux->data;
        aux = aux->next;
    }
    aux = (struct node *)NULL;
    return maior_data;
}