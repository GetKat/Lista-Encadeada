#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista_ord();

struct desc *lista;

int main(){
    cria_lista_ord();
    show_content();
}

void cria_lista_ord(){
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
            else{
                aux->next = (struct node *)malloc(sizeof(struct node));
                aux = aux->next;
                aux->data = data;
                aux->next = (struct node *)NULL;
                lista->fim = aux;
            }
        }
        aux = (struct node *)NULL;
        prev = aux;
    }
    int data;
    cria_descritor();
    scanf("%d", &data);
    while(data >= 0){
        inserir_ordenado(data);
        scanf("%d", &data);
    }
}