#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int count_elements();

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    printf("%d elementos\n", count_elements());
}

int count_elements(){
    struct node *aux;
    int count = 0;
    aux = inicio;
    if(inicio != (struct node *)NULL)
        do{ 
            aux = aux->next;
            count++;
        }while(aux != inicio);
    aux = (struct node *)NULL;
    return count;
}