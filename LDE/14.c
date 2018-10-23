#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista_ord_rec(struct node *aux);

struct node *inicio;

int main(){
    cria_lista_ord_rec((struct node *)NULL);
    show_content();
}

void cria_lista_ord_rec(struct node *aux){
    void inserir_ordenado_rec(int data, struct node *aux){
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
            if(aux->next != (struct node *)NULL && aux->data <= data){   
                aux = aux->next;
                inserir_ordenado_rec(data, aux);
            }
            else{
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
        }
        aux = (struct node *)NULL;
    }
    int data;
    if(aux == (struct node *)NULL)
        inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        inserir_ordenado_rec(data, inicio);
        cria_lista_ord_rec(inicio);
    }
}