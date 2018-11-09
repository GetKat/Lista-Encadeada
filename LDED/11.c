#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void inserir_ordenado(int data);

struct desc *lista;

int main(){
    cria_lista();
    show_content();
    inserir_ordenado(10);
    debug();
    inserir_ordenado(15);
    debug();
}

void inserir_ordenado(int data){
    struct node *aux;
    //lista vazia
    if(lista->inicio == (struct node *)NULL){
        lista->inicio = (struct node *)malloc(sizeof(struct node));
        lista->inicio->data = data;
        lista->inicio->next = (struct node *)NULL;
        lista->inicio->prev = (struct node *)NULL; 
        lista->fim = lista->inicio;
    }
    // inserir antes do lista->inicio
    else if(lista->inicio->data > data){
        lista->inicio->prev = (struct node *)malloc(sizeof(struct node));
        lista->inicio->prev->next = lista->inicio;
        lista->inicio->prev->data = data;
        lista->inicio->prev->prev = (struct node *)NULL;
        lista->inicio = lista->inicio->prev;
    }
    else{
        aux = lista->inicio;
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
            lista->fim = aux->next;
        }
    }
    lista->count++;
    aux = (struct node *)NULL;
}