#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void delete_element_rec(int data, struct node *prev, struct node *aux);

struct desc *lista;

int main(){
    cria_lista();
    show_content();
    delete_element_rec(10, (struct node *)NULL, lista->inicio);
    debug();
}

void delete_element_rec(int data, struct node *prev, struct node *aux){
    if(lista->inicio == (struct node *)NULL)
        printf("Lista vazia!\n");
    //deletando o inicio
    else if(lista->inicio->data == data){
        if(lista->inicio->next == (struct node *)NULL)
            lista->fim = (struct node *)NULL;
        aux = lista->inicio;
        lista->inicio = lista->inicio->next;
        aux->next = (struct node *)NULL;
        free(aux);
        aux = (struct node *)NULL;
        lista->count--;
    }
    else
        if(aux->data != data && aux->next != (struct node *)NULL){
            prev = aux;
            aux = aux->next;
            delete_element_rec(data, prev, aux);
        }
        else
            if(aux->data == data){
                prev->next = aux->next;
                if(aux->next == (struct node *)NULL)
                    lista->fim = prev;
                aux->next = (struct node *)NULL;
                free(aux);
                aux = (struct node *)NULL;
                lista->count--;
            }
            else
                printf("elemento n encontrado!\n");
}