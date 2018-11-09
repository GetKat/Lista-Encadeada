#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void deletar_elemento(int data);

int main(){
    cria_lista();
    show_content();
    deletar_elemento(10);
    show_content();
}

void deletar_elemento(int data){
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