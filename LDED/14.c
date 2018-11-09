#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void inserir_ordenado_rec(int data, struct node *aux);
void cria_lista_ord_rec(struct node *aux);

struct desc *lista;

int main(){
    cria_lista_ord_rec((struct node *)NULL);
    debug();
}

void inserir_ordenado_rec(int data, struct node *aux){
    //lista vazia
    if(lista->inicio == (struct node *)NULL){
        lista->inicio = (struct node *)malloc(sizeof(struct node));
        lista->inicio->data = data;
        lista->inicio->next = (struct node *)NULL;
        lista->inicio->prev = (struct node *)NULL;
        lista->fim = lista->inicio;
        lista->count++;
    }
    // inserir antes do lista->inicio
    else if(lista->inicio->data > data){
        lista->inicio->prev = (struct node *)malloc(sizeof(struct node));
        lista->inicio->prev->next = lista->inicio;
        lista->inicio->prev->data = data;
        lista->inicio->prev->prev = (struct node *)NULL;
        lista->inicio = lista->inicio->prev;
        lista->count++;
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
                lista->count++;
            }
            //inserir dps de aux 
            else{ // (aux->data <= data)
                aux->next = (struct node *)malloc(sizeof(struct node));
                aux->next->prev = aux;
                aux->next->next = (struct node *)NULL;
                aux->next->data = data;
                lista->fim = aux->next;
                lista->count++;
            }
        }
    }
    aux = (struct node *)NULL;
}

void cria_lista_ord_rec(struct node *aux){
    int data;
    if(aux == (struct node *)NULL)
        cria_descritor();
    scanf("%d", &data);
    if(data >= 0){
        inserir_ordenado_rec(data, lista->inicio);
        cria_lista_ord_rec(lista->inicio);
    }
}