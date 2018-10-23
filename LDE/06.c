#include "node.h"
#include <stdio.h>
#include <stdlib.h>

struct node *inicio;

int count_elements_rec(struct node *aux);
int count_elements_rec_2(struct node *aux, int count);

int main(){
    cria_lista();
    show_content();
    printf("%d %d elemento(s)\n", count_elements_rec(inicio), count_elements_rec_2(inicio, 0));
}

int count_elements_rec(struct node *aux){
    if(aux != (struct node *)NULL){
        aux = aux->next;
        return count_elements_rec(aux) + 1;
    }
    else   
        return 0;
}

int count_elements_rec_2(struct node *aux, int count){
    if(aux != (struct node *)NULL){
        aux = aux->next;
        count_elements_rec_2(aux, count + 1);
    }
    else   
        return count;
}