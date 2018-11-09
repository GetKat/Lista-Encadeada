#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void deletar_elemento(int data);

struct desc *lista;

int main(){
    cria_lista();
    debug();
    deletar_elemento(10);
    debug();
}

void deletar_elemento(int data){
    struct node *aux;
    //lista vazia
    if(lista->inicio == (struct node *)NULL){
        printf("Lista vazia!\n");
    }
    //elemento a ser deletado esta no lista->inicio
    else if(lista->inicio->data == data){
        if(lista->inicio->next == (struct node *)NULL){
            free(lista->inicio);
            lista->inicio = (struct node *)NULL;
            lista->fim = lista->inicio;
            lista->count--;
        }
        else{
            aux = lista->inicio;
            lista->inicio = lista->inicio->next;
            lista->inicio->prev = (struct node *)NULL;
            aux->next = (struct node *)NULL;
            free(aux);
            aux = (struct node *)NULL;
            lista->count--;
        }
    }
    else{
        aux = lista->inicio;
        while(aux->next != (struct node *)NULL && aux->data != data)    
            aux = aux->next;
        if(aux->data == data){
            //elemento no final da lista
            if(aux->next == (struct node *)NULL){
                lista->fim = aux->prev;
                aux->prev->next = aux->next;
                aux->prev = (struct node *)NULL;
                free(aux);
                aux = (struct node *)NULL;
                lista->count--;
            }
            //elemento no meio da lista
            else{
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                aux->prev = (struct node *)NULL;
                aux->next = aux->prev;
                free(aux);
                aux = (struct node *)NULL;
                lista->count--;
            }
        }
        else
            printf("Elemento n encontrado!\n");
    }
}