#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

void inserir_ordenado(struct node *novo);
void inserir_ordenado_alt(int data);

/*
Forma alternativa de fazer o inserir_ordenado, mais informacoes: https://www.youtube.com/watch?v=0ZEX_l0DFK0
*/

int main(){
    cria_lista();
    show_content();
    // struct node *aux = (struct node *)malloc(sizeof(struct node));
    // aux->data = 10;
    // inserir_ordenado(aux);
    inserir_ordenado_alt(10);
    show_content();
}


//as duas fazem a mesma coisa, uma pega o valor a ser inserido na lista, a outra pega o no inteiro a ser inserido
void inserir_ordenado(struct node *aux){
    struct node **tracer = &inicio;
    while((*tracer) != (struct node *)NULL && (*tracer)->data <= aux->data)
        tracer = &(*tracer)->next;
    aux->next = *tracer;
    *tracer = aux;
    aux = (struct node *)NULL;
}

void inserir_ordenado_alt(int data){
    struct node *aux = (struct node *)malloc(sizeof(struct node));
    aux->data = data;

    struct node **tracer = &inicio;
    while((*tracer) != (struct node *)NULL && (*tracer)->data <= aux->data)
        tracer = &(*tracer)->next;
    aux->next = *tracer;
    *tracer = aux;
    aux = (struct node *)NULL;
}