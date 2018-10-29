#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "node.h"

void inserir_ordenado(int data);
void inserir_ordenado_hard(int data);
void debug(struct node *aux);

struct node *inicio;

int main(){
    cria_lista();
    debug();
    inserir_ordenado_hard(1);
    debug();
    inserir_ordenado_hard(3);
    debug();
    inserir_ordenado_hard(1);
    debug();
    inserir_ordenado_hard(1);
    debug();
}
//OK!
void inserir_ordenado(int data){
    struct node *aux, *prev;
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = (struct node *)NULL;
        inicio->prev = (struct node *)NULL;
    }
    else{
        if(inicio->data > data){
            inicio->prev = (struct node *)malloc(sizeof(struct node));
            inicio->prev->next = inicio;
            inicio = inicio->prev;
            inicio->data = data;
        }
        else{
            aux = inicio;
            while(aux->next != (struct node *)NULL && aux->data <= data){
                prev = aux;
                aux = aux->next;
            }
            if(aux->data > data){ //inserir entre prev e aux
                prev->next = (struct node *)malloc(sizeof(struct node));
                aux->prev = prev->next;
                prev->next->prev = prev;
                prev->next->next = aux;
                prev->next->data = data;
            }
            else{ //inserir dps de aux
                aux->next = (struct node *)malloc(sizeof(struct node));
                aux->next->prev = aux;
                aux->next->data = data;
                aux->next->next = (struct node *)NULL;
            }
        }
    }
    aux = (struct node *)NULL;
    prev = aux;
}


//faz a mesma coisa usando somente um ponteiro auxiliar
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