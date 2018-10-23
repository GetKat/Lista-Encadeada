#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int maior_rec(struct node *aux, int maior_data);

struct desc *lista;

int main(){
    cria_lista();
    show_content();
    printf("maior: %d\n", maior_rec(lista->inicio, 0));
}

int maior_rec(struct node *aux, int maior_data){
    if(lista->count == 0)
        return 0;
    if(aux != (struct node *)NULL){
        if(aux->data > maior_data)
            maior_data = aux->data;
        aux = aux->next;
        maior_rec(aux, maior_data);
        aux = (struct node *)NULL;
    }
    else   
        return maior_data;
}