#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void unir_rec(struct node *aux, struct node *first, struct node *second);

int main(){
    struct node *first, *second;
    cria_lista(&first);
    cria_lista(&second);
    printf("Primeira:\n");
    debug(first);
    printf("Segunda:\n");
    debug(second);
    unir_rec((struct node *)NULL, first, second);
    debug();
}

void unir_rec(struct node *aux, struct node *first, struct node *second){
    if(aux = (struct node *)NULL)
        inicio = (struct node *)NULL;
    if(first != (struct node *)NULL || second != (struct node *)NULL){
        if(first != (struct node *)NULL){
            aux = first;
            inserir_ordenado_hard(aux->data);
            first = first->next;
        }
        if(second != (struct node *)NULL){
            aux = second;
            inserir_ordenado_hard(aux->data);
            second = second->next;
        }
        unir_rec(aux, first, second);
    }
    aux = (struct node *)NULL;
}

void inserir_ordenado_hard(int data){
    struct node *aux;
    //lista vazia
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = (struct node *)NULL;
        inicio->prev = (struct node *)NULL; 
    }
    // inserir antes do inicio
    else if(inicio->data > data){
        inicio->prev = (struct node *)malloc(sizeof(struct node));
        inicio->prev->next = inicio;
        inicio->prev->data = data;
        inicio->prev->prev = (struct node *)NULL;
        inicio = inicio->prev;
    }
    else{
        aux = inicio;
        while(aux->next != (struct node *)NULL && aux->data <= data)
            aux = aux->next;
        //inserir antes de aux
        if(aux->data > data){
            aux->prev->next = (struct node *)malloc(sizeof(struct node));
            aux->prev->next->prev = aux->prev;
            aux->prev->next->next = aux;
            aux->prev->next->data = data;
            aux->prev = aux->prev->next;
        }
        //inserir dps de aux 
        else{ // (aux->data <= data)
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux->next->prev = aux;
            aux->next->next = (struct node *)NULL;
            aux->next->data = data;
        }
    }
    aux = (struct node *)NULL;
}