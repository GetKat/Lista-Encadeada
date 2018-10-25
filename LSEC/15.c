#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void deletar_elemento(int data);

struct node *inicio;

int main(){
    cria_lista();
    debug();
    deletar_elemento(10);
    debug();
}

void deletar_elemento(int data){
    struct node *aux, *prev;
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!\n");
    else if(inicio->data == data){
        if(inicio->next == inicio){
            inicio->next = (struct node *)NULL;
            free(inicio);
            inicio = (struct node *)NULL;
        }
        else{
            prev = inicio;
            //tirando o elemento do inicio eu preciso fazer fim->next = novo_inicio ;)
            do{
                prev = prev->next;
            }while(prev->next != inicio);
            aux = inicio;
            inicio = inicio->next;
            prev->next = inicio;
            aux->next = (struct node *)NULL;
            free(aux);
            aux = (struct node *)NULL;
        }
    }
    else{
        aux = inicio;
        while(aux->next != inicio && aux->data != data){
            prev = aux;
            aux = aux->next;
        }
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