#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void deletar_elemento(int data);

struct node *inicio;

int main(){
    int data = 5;
    cria_lista();
    debug();
    deletar_elemento(data);
    debug();
}

void deletar_elemento(int data){
    struct node *aux;
    //lista vazia
    if(inicio == (struct node *)NULL){
        printf("Lista vazia!\n");
    }
    //elemento a ser deletado esta no inicio
    else if(inicio->data == data){
        if(inicio->next == (struct node *)NULL){
            free(inicio);
            inicio = (struct node *)NULL;
        }
        else{
            aux = inicio;
            inicio = inicio->next;
            inicio->prev = (struct node *)NULL;
            aux->next = (struct node *)NULL;
            free(aux);
            aux = (struct node *)NULL;
        }
    }
    else{
        aux = inicio;
        while(aux->next != (struct node *)NULL && aux->data != data)    
            aux = aux->next;
        if(aux->data == data){
            //elemento no final da lista
            if(aux->next == (struct node *)NULL){
                aux->prev->next = aux->next;
                aux->prev = (struct node *)NULL;
                free(aux);
                aux = (struct node *)NULL;
            }
            //elemento no meio da lista
            else{
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                aux->prev = (struct node *)NULL;
                aux->next = aux->prev;
                free(aux);
                aux = (struct node *)NULL;
            }
        }
        else
            printf("Elemento n encontrado!\n");
    }
}