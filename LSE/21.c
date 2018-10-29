#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void ordenar();
void deletar_lista(struct node **inicio);

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    ordenar();
    show_content();
}

void deletar_lista(struct node **inicio){
    struct node *aux;
    while((*inicio) != (struct node *)NULL){
        aux = (*inicio);
        (*inicio) = (*inicio)->next;
        aux->next = (struct node *)NULL;
        free(aux);
        aux = (struct node *)NULL;
    }
}

void inserir_ordenado(int data){
    struct node *aux, *prev;
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = (struct node *)NULL;
    }
    else if(inicio->data > data){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = inicio;
        inicio = aux;
    }
    else{
        aux = inicio;
        while(aux->next != (struct node *)NULL && aux->data <= data){
            prev = aux;
            aux = aux->next;
        }
        //inserir no final
        if(aux->data < data){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = (struct node *)NULL;
        }
        //inserir entre aux e prev
        else{
            prev->next = (struct node *)malloc(sizeof(struct node));
            prev = prev->next;
            prev->data = data;
            prev->next = aux;
        }
    }
    aux = (struct node *)NULL;
    aux = prev;
}

void inserir_fim(struct node **inicio, int data){
    struct node *aux;
    if(*inicio == (struct node *)NULL){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = (struct node *)NULL;
        *inicio = aux;
    }
    else{
        aux = *inicio;
        while(aux->next != (struct node *)NULL)
            aux = aux->next;
        aux->next = (struct node *)malloc(sizeof(struct node));
        aux = aux->next;
        aux->data = data;
        aux->next = (struct node *)NULL;
    }
    aux = (struct node *)NULL;
}

void ordenar(){
    struct node *hold, *aux;

    hold = (struct node *)NULL;

#if 0
    struct node *it = inicio;
    if(it != (struct node *)NULL){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = it->data;
        aux->next = (struct node *)NULL;
        hold = aux;
        it = it->next;
        while(it != (struct node *)NULL){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = it->data;
            aux->next = (struct node *)NULL;
            it = it->next;
        }
    }
    it = (struct node *)NULL;
#else
    aux = inicio;
    while(aux != (struct node *)NULL){
        inserir_fim(&hold, aux->data);
        aux = aux->next;
    }
#endif

    deletar_lista(&inicio);
    aux = hold;
    while(aux != (struct node *)NULL){
        inserir_ordenado(aux->data);
        aux = aux->next;
    }
    deletar_lista(&hold);
    aux = (struct node *)NULL;
    hold = aux;
}