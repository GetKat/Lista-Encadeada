#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void unir(int primeiro, struct desc *first, struct desc *second);
void inserir_ordenado(int data);

struct desc *lista;

int main(){
    struct desc *lista1, *lista2;
    cria_lista(&lista1);
    cria_lista(&lista2);

    debug(lista1);
    debug(lista2);

    unir(0, lista1, lista2);
    debug();
}

void unir(int primeiro, struct desc *first, struct desc *second){
    //INSERIR (( INSERIR_ORDENADO_REC() ) AQUI)
    if(primeiro == 0){
        primeiro = 1;
        cria_descritor();
    }
    if(first->inicio != (struct node *)NULL || second->inicio != (struct node *)NULL){
        if(first->inicio != (struct node *)NULL){
            inserir_ordenado(first->inicio->data);
            first->inicio = first->inicio->next;
        }
        if(second->inicio != (struct node *)NULL || second->inicio != (struct node *)NULL){
            inserir_ordenado(second->inicio->data);
            second->inicio = second->inicio->next;
        } 
        unir(primeiro, first, second);
    }

}

void inserir_ordenado(int data){
    struct node *aux, *prev;
    //lista vazia
    if(lista->inicio == (struct node *)NULL){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = (struct node *)NULL;
        lista->inicio = aux;
        lista->fim = lista->inicio;
    }
    //inserir antes do inicio
    else if(lista->inicio->data > data){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = lista->inicio;
        lista->inicio = aux;
    }
    else{
        aux = lista->inicio;
        while(aux->next != (struct node *)NULL && aux->data <= data){
            prev = aux;
            aux = aux->next;
        }
        //inserir no meio (antes de aux)
        if(aux->data > data){
            prev->next = (struct node *)malloc(sizeof(struct node));
            prev = prev->next;
            prev->next = aux;
            prev->data = data;
        }
        //inserir no fim
        else{
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = (struct node *)NULL;
            lista->fim = aux;
        }
    }
    lista->count++;
    aux = (struct node *)NULL;
    prev = aux;
}