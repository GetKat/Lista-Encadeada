#include <stdio.h>
#include <stdlib.h>
#include "ptr.h"

struct ptr *inicio;

void cria_lista_inv_rec(struct ptr *aux);
void show_content();
void show_content_rec(struct ptr *aux);

int main(){
    cria_lista_inv_rec((struct ptr *) NULL);
    show_content();
    show_content_rec(inicio);
}

void cria_lista_inv_rec(struct ptr *aux){
    int valor;
    if(aux == (struct ptr *) NULL)
        inicio = (struct ptr *) NULL;
    scanf("%d", &valor);
    if(valor >= 0){
        aux = (struct ptr *) malloc(sizeof(struct ptr *));
        aux->valor = valor;
        aux->prox = inicio;
        inicio = aux;
        cria_lista_inv_rec(aux);
    }
    aux = (struct ptr *) NULL;
}

void show_content(){
    struct ptr *aux;
    aux = inicio;

    if(inicio == (struct ptr *) NULL)
        printf("Lista vazia!");
    while(aux != (struct ptr *) NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    aux = (struct ptr *) NULL;
    printf("\n");
}

void show_content_rec(struct ptr *aux){
    if(inicio == (struct ptr *) NULL)
        printf("Lista vazia!");
    else if(aux != (struct ptr *) NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
        show_content_rec(aux);
    }
}