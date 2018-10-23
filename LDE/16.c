#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void deletar_elemento_rec(int data, struct node *aux);

struct node *inicio;

int main(){
    int data = 5;
    cria_lista();
    show_content();
    deletar_elemento_rec(data, inicio);
    show_content();
}

void deletar_elemento_rec(int data, struct node *aux){
    //lista vazia
    if(inicio == (struct node *)NULL){
        printf("Lista vazia!\n");
    }
    //elemento a ser deletado esta no inicio
    else if(inicio->data == data){
        aux = inicio;
        inicio = inicio->next;
        inicio->prev = (struct node *)NULL;
        aux->next = (struct node *)NULL;
        free(aux);
        aux = (struct node *)NULL;
    }
    else{
        if(aux->next != (struct node *)NULL && aux->data != data){
            aux = aux->next;
            deletar_elemento_rec(data, aux);
        }
        else{
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
}