#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void unir(struct node *first, struct node *second);
void unir_deletar(struct node **first, struct node **second);

int main(){
    struct node *first, *second;
    cria_lista_2(&first);
    cria_lista_2(&second);
    printf("Primeira:\n");
    show_content_2(first);
    printf("Segunda:\n");
    show_content_2(second);

    printf("Principal:\n");
    show_content();
    //unir(first, second);
    unir_deletar(&first, &second);
    printf("Principal unida:\n");
    show_content();
    printf("Primeira:\n");
    show_content_2(first);
    printf("Segunda:\n");
    show_content_2(second);
}

void unir(struct node *first, struct node *second){
    void inserir_ordenado_hard(int data){
        struct node *aux;
        //lista vazia
        if(inicio == (struct node *)NULL){
            inicio = (struct node *)malloc(sizeof(struct node));
            inicio->data = data;
            inicio->next = (struct node *)NULL;
            inicio->prev = (struct node *)NULL; 
        }
        // inserir antes do inicio
        else if(inicio->data > data){
            inicio->prev = (struct node *)malloc(sizeof(struct node));
            inicio->prev->next = inicio;
            inicio->prev->data = data;
            inicio->prev->prev = (struct node *)NULL;
            inicio = inicio->prev;
        }
        else{
            aux = inicio;
            while(aux->next != (struct node *)NULL && aux->data <= data)
                aux = aux->next;
            //inserir antes de aux
            if(aux->data > data){
                aux->prev->next = (struct node *)malloc(sizeof(struct node));
                aux->prev->next->prev = aux->prev;
                aux->prev->next->next = aux;
                aux->prev->next->data = data;
                aux->prev = aux->prev->next;
            }
            //inserir dps de aux 
            else{ // (aux->data <= data)
                aux->next = (struct node *)malloc(sizeof(struct node));
                aux->next->prev = aux;
                aux->next->next = (struct node *)NULL;
                aux->next->data = data;
            }
        }
        aux = (struct node *)NULL;
    }
    struct node *aux;
    inicio = (struct node *)NULL;
    aux = first;
    while(aux != (struct node *)NULL){
        inserir_ordenado_hard(aux->data);
        aux = aux->next;
    }
    aux = second;
    while(aux != (struct node *)NULL){
        inserir_ordenado_hard(aux->data);
        aux = aux->next;
    }
    aux = (struct node *)NULL;
}

void unir_deletar(struct node **first, struct node **second){
    void inserir_ordenado_hard(int data){
        struct node *aux;
        //lista vazia
        if(inicio == (struct node *)NULL){
            inicio = (struct node *)malloc(sizeof(struct node));
            inicio->data = data;
            inicio->next = (struct node *)NULL;
            inicio->prev = (struct node *)NULL; 
        }
        // inserir antes do inicio
        else if(inicio->data > data){
            inicio->prev = (struct node *)malloc(sizeof(struct node));
            inicio->prev->next = inicio;
            inicio->prev->data = data;
            inicio->prev->prev = (struct node *)NULL;
            inicio = inicio->prev;
        }
        else{
            aux = inicio;
            while(aux->next != (struct node *)NULL && aux->data <= data)
                aux = aux->next;
            //inserir antes de aux
            if(aux->data > data){
                aux->prev->next = (struct node *)malloc(sizeof(struct node));
                aux->prev->next->prev = aux->prev;
                aux->prev->next->next = aux;
                aux->prev->next->data = data;
                aux->prev = aux->prev->next;
            }
            //inserir dps de aux 
            else{ // (aux->data <= data)
                aux->next = (struct node *)malloc(sizeof(struct node));
                aux->next->prev = aux;
                aux->next->next = (struct node *)NULL;
                aux->next->data = data;
            }
        }
        aux = (struct node *)NULL;
    }
    struct node *aux;
    inicio = (struct node *)NULL;
    while(*first != (struct node *)NULL){
        aux = *first;
        inserir_ordenado_hard(aux->data);
        *first = (*first)->next;
        aux->next = (struct node *)NULL;
        free(aux);
        aux = (struct node *)NULL;
    }
    while(*second != (struct node *)NULL){
        aux = *second;
        inserir_ordenado_hard(aux->data);
        *second = (*second)->next;
        aux->next = (struct node *)NULL;
        free(aux);
        aux = (struct node *)NULL;
    }
    aux = (struct node *)NULL;
}