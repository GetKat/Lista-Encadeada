#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void inserir_ordenado(int data);

struct node *inicio;

int main(){
    cria_lista();
    debug();
    inserir_ordenado(1);
    debug();
}

void inserir_ordenado(int data){
    struct node *aux, *prev;
    //lista vazia
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = inicio;
    }
    //inserir antes do inicio
    else if(inicio->data > data){
        //prev aqui representa o final da lista
        do{
            prev = prev->next;
        }while(prev->next != inicio);
        
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = inicio;
        prev = inicio;
        prev->next = aux;
        inicio = aux;
    }
    else{
        aux = inicio;
        prev = aux;
        aux = aux->next;
        while(aux->next != inicio && aux->data <= data){
            prev = aux;
            aux = aux->next;
        }
        //inserir no final
        if(aux->data < data){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = inicio;
        }
        else{
            prev->next = (struct node *)malloc(sizeof(struct node));
            prev = prev->next;
            prev->next = aux;
            prev->data = data;
        }
    }
    aux = (struct node *)NULL;
    prev = aux;
}