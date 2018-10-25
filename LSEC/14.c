#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void inserir_ordenado_rec(int data, struct node *prev, struct node *aux);
void cria_lista_ord_rec(struct node *aux);

struct node *inicio;

int main(){
    cria_lista_ord_rec((struct node *)NULL);
    debug();
}

void cria_lista_ord_rec(struct node *aux){
    //INSERIR inserir_ordenado() AQ
    int data;
    if(aux == (struct node *)NULL)
        inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        inserir_ordenado_rec(data, inicio, inicio);
        cria_lista_ord_rec(inicio);
    }
}

void inserir_ordenado_rec(int data, struct node *prev, struct node *aux){
    //lista vazia
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = inicio;
    }
    //inserir antes do inicio
    else if(inicio->data > data){
        prev = prev->next;
        if(prev->next != inicio)
            inserir_ordenado_rec(data, prev, aux);
        else{
            aux = (struct node *)malloc(sizeof(struct node));
            aux->data = data;
            aux->next = inicio;
            prev->next = aux;
            inicio = aux;
        }
    }
    else{
        prev = aux;
        aux = aux->next;
        if(aux->next != inicio && aux->data <= data){
            prev = aux;
            aux = aux->next;
            inserir_ordenado_rec(data, prev, aux);
        }
        else
            //inserir no final
            if(aux->data < data){
                aux->next = (struct node *)malloc(sizeof(struct node));
                aux = aux->next;
                aux->data = data;
                aux->next = inicio;
            }
            //inserir no meio (entre prev e aux)
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