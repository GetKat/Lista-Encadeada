#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

int count_elements_rec(struct node *aux, int count);
int count_elements_rec_2(struct node *aux);

int main(){
    cria_lista();
    show_content();
    printf("%d elementos\n", count_elements_rec(inicio, 0));
    printf("%d elementos\n", count_elements_rec_2(inicio));
}

int count_elements_rec(struct node *aux, int count){
    if(aux != (struct node *)NULL){
        count++;
        aux = aux->next;
        return count_elements_rec(aux, count);
    }
    else
        return count;
}

int count_elements_rec_2(struct node *aux){
    if(aux != (struct node *)NULL)
        return count_elements_rec_2(aux->next) + 1;
    else
        return 0;
    //one liner:
    // return aux == (struct node *)NULL ? 0 : count_elements_rec_2(aux->next) + 1;
}