#include <stdio.h>
#include <stdlib.h>
#include "node.h"

extern struct node *inicio;

void show_content(void){
    struct node *aux;
    aux = inicio;
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!");
    else
        do{
            printf("%d ", aux->data);
            aux = aux->next;
        }while(aux != inicio);
    aux = (struct node *)NULL;
    printf("\n");
}

void debug(){
    //same as show_content()
    struct node *aux;
    aux = inicio;
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!\n");
    else{
        do{
            printf("%d ", aux->data);
            aux = aux->next;
        }while(aux != inicio);
        printf("\n");
        //
        aux = inicio;
            while(aux->next != inicio)
                aux = aux->next;
        printf("ultimo elemento: %d\n", aux->data);
        printf("proximo: %d (inicio == %d)\n", aux->next->data, inicio->data);
        aux = (struct node *)NULL;
    }
}