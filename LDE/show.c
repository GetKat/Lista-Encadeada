#include "node.h"
#include <stdio.h>
#include <stdlib.h>

extern struct node *inicio;

void show_content(){
    struct node *aux;
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!");  
    aux = inicio;
    while(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void show_content(struct node *aux){
    if(aux == (struct node *)NULL)
        printf("Lista vazia!"); 
    while(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void debug(){
    struct node *aux, *last = (struct node *)NULL;
    printf("Lista direta:\n");
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!");  
    aux = inicio;
    while(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        last = aux;
        aux = aux->next;
    }
    printf("\n");
    printf("Lista inversa:\n");
    while(last != (struct node *)NULL){
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

void debug(struct node *aux){
    struct node *last = (struct node *)NULL;
    printf("Lista direta:\n");
    if(aux == (struct node *)NULL)
        printf("Lista vazia!");
    while(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        last = aux;
        aux = aux->next;
    }
    printf("\n");
    printf("Lista inversa:\n");
    while(last != (struct node *)NULL){
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}