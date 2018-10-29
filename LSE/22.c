#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void ordenar_rec(struct node *hold, struct node *aux, struct node *it);
void deletar_lista(struct node **inicio);

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    ordenar_rec((struct node *)NULL, inicio, (struct node *)NULL);
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

void ordenar_rec(struct node *hold, struct node *aux, struct node *it){
    if(aux != (struct node *)NULL){
        inserir_fim(&hold, aux->data);
        aux = aux->next;
        ordenar_rec(hold, aux, it);
    }
    else{
        if(it == (struct node *)NULL){
            deletar_lista(&inicio);
            it = hold;
            ordenar_rec(hold, aux, it);
        }
        else{        
            if(it->next != (struct node *)NULL){
                inserir_ordenado(it->data);
                it = it->next;
                ordenar_rec(hold, aux, it);
            }
            else{
                inserir_ordenado(it->data);
                deletar_lista(&hold);
                aux = (struct node *)NULL;
                hold = aux;
            }
        }
    }
}