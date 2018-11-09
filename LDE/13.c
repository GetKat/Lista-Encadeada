#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista_ord();
void inserir_ordenado(int data);
struct node *inicio;

int main(){
    cria_lista_ord();
    show_content();
}

void cria_lista_ord(){
    int data;
    inicio = (struct node *)NULL;
    scanf("%d", &data);
    while(data >= 0){
        inserir_ordenado(data);
        scanf("%d", &data);
    }

}

void inserir_ordenado(int data){   
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
        inicio = inicio->prev;
        inicio->data = data;
    }
    else{
        aux = inicio;
        while(aux->next != (struct node *)NULL && aux->data <= data)
            aux = aux->next;
        //inserir antes de aux
        if(aux->data > data){
            aux->prev->next = (struct node *)malloc(sizeof(struct node));
            aux->prev->next->next = aux;
            aux->prev->next->data = data;
            aux->prev->next->prev = aux->prev;
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