#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void cria_lista_ord_rec(struct node *aux);

struct desc *lista;

int main(){
    cria_lista_ord_rec((struct node *)NULL);
    show_content();
}

void cria_lista_ord_rec(struct node *aux){
    void inserir_ordenado_rec(int data, struct node *prev, struct node *aux){
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
            if(aux->next != (struct node *)NULL && aux->data <= data){
                prev = aux;
                aux = aux->next;
                inserir_ordenado_rec(data, prev, aux);
            }
            else{
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
        }
        aux = (struct node *)NULL;
        prev = aux;
    }
    int data;
    if(aux == (struct node *)NULL)
        cria_descritor();
    scanf("%d", &data);
    if(data >= 0){
        inserir_ordenado_rec(data, (struct node *)NULL, lista->inicio);
        aux = lista->inicio;
        cria_lista_ord_rec(aux);
    }
}