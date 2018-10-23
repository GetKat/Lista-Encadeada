#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

int maior_rec(struct node *aux, int maior);

int main(){
    cria_lista();
    show_content();
    printf("maior: %d\n", maior_rec(inicio, 0));
}

int maior_rec(struct node *aux, int maior){
    if(aux != (struct node *)NULL){
        if(aux == inicio)
            maior = aux->data;
        if(aux->data > maior)
            maior = aux->data;
        maior_rec(aux->next, maior);
    }
    else   
        return maior;
}