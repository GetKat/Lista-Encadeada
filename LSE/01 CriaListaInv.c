#include <stdio.h>
#include <stdlib.h>
#include "ptr.h"

struct ptr *inicio;

void cria_lista_inv();
void show_content();

int main(){
    cria_lista_inv();
    show_content();
}

void cria_lista_inv(){
    int valor;
    struct ptr *aux;
    inicio = (struct ptr *) NULL;

    scanf("%d", &valor);
    while(valor >= 0){
        aux = (struct ptr *) malloc(sizeof(struct ptr));
        aux->valor = valor;
        aux->prox = inicio;
        inicio = aux;
        scanf("%d", &valor);
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