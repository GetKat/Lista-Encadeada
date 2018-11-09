#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void deletar_elemento_rec(int data, struct node *prev, struct node *aux);

int main(){
    cria_lista();
    show_content();
    deletar_elemento_rec(10, (struct node *)NULL, inicio);
    show_content();
}

void deletar_elemento_rec(int data, struct node *prev, struct node *aux){
    struct node *aux, *prev;
    if(inicio == (struct node *)NULL)
        printf("Lista vazia! N consigo remover elemento!\n");
    else{
        //elemento a ser deletado esta no inicio
        if(inicio->data == data){
            aux = inicio;
            inicio = inicio->next;
            aux->next = (struct node *)NULL;
            free(aux);
            aux = (struct node *)NULL;
        }
        else{
            aux = inicio;
            while(aux->next != (struct node *)NULL && aux->data != data){
                prev = aux;
                aux = aux->next;
            }
            if(aux->data == data){
                prev->next = aux->next;
                aux->next = (struct node *)NULL;
                free(aux);
                aux = (struct node *)NULL;
            }
            else
                printf("Elemento n encontrado!\n");
        }
    }
    aux = (struct node *)NULL;
    prev = aux;
}