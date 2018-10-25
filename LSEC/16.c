#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void deletar_elemento_rec(int data, struct node *prev, struct node *aux);

struct node *inicio;

int main(){
    cria_lista();
    debug();
    deletar_elemento_rec(10, inicio, inicio);
    debug();
}

void deletar_elemento_rec(int data, struct node *prev, struct node *aux){
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!\n");
    else if(inicio->data == data){
        if(inicio->next == inicio){
            inicio->next = (struct node *)NULL;
            free(inicio);
            inicio = (struct node *)NULL;
        }
        else{
            prev = prev->next;
            if(prev->next != inicio)
                deletar_elemento_rec(data, prev, aux);
            else{
                aux = inicio;
                inicio = inicio->next;
                prev->next = inicio;
                aux->next = (struct node *)NULL;
                free(aux);
                aux = (struct node *)NULL;
            }
        }
    }
    else{
        if(aux->next != inicio && aux->data != data){
            prev = aux;
            aux = aux->next;
            deletar_elemento_rec(data, prev, aux);
        }
        else
            if(aux->data == data){
                prev->next = aux->next;
                aux->next = (struct node *)NULL;
                free(aux);
                aux = (struct node *)NULL;
            }
            else{
                printf("Elemento n encontrado!\n");
            }
    }
    aux = (struct node *)NULL;
    prev = aux;
}