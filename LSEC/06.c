#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int count_elements_rec(struct node *aux, int count);

struct node *inicio;

int main(){
    cria_lista();
    debug();
    printf("%d elementos\n", count_elements_rec(inicio, 0));
}

int count_elements_rec(struct node *aux, int count){
    if(inicio == (struct node *)NULL)
        return 0;
    else{
        aux = aux->next;
        count++;
        if(aux != inicio)
            return count_elements_rec(aux, count);
        else
            return count;
    }
}