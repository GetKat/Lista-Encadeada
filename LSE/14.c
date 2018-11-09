#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void inserir_ordenado_rec(int data, struct node *prev, struct node *aux);
void cria_lista_ord_rec(struct node *aux);

int main(){
    cria_lista_ord_rec((struct node *)NULL);
    show_content();
}

void cria_lista_ord_rec(struct node *aux){
    int data;
    if(aux == (struct node *)NULL)
        inicio = (struct node *)NULL;
    scanf("%d", &data);
    while(data >= 0){
        inserir_ordenado_rec(data, (struct node *)NULL, inicio);
        cria_lista_ord_rec(inicio);
    }
}

void inserir_ordenado_rec(int data, struct node *prev, struct node *aux){
    //se a lista tiver vazia
    if(inicio == (struct node *)NULL){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = (struct node *)NULL;
    }
    //inserir antes do inicio
    else if(inicio->data > data){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = inicio;
        inicio = aux;
    }
    else{
        if(aux->next != (struct node *)NULL && aux->data <= data){
            prev = aux;
            aux = aux->next;
            inserir_ordenado_rec(data, prev, aux);
        }
        else{
            //inserir dps de aux (fim)
            if(aux->data <= data){
                aux->next = (struct node *)malloc(sizeof(struct node));
                aux = aux->next;
                aux->data = data;
                aux->next = (struct node *)NULL;
            }
            //inserir antes de aux (entre prev e aux)
            else{
                prev->next = (struct node *)malloc(sizeof(struct node));
                prev = prev->next;
                prev->data = data;
                prev->next = aux;
            }
        }     
    }
    aux = (struct node *)NULL;
    prev = aux;
}