#include <stdio.h>
#include <stdlib.h>
#include "ptr.h"

struct ptr *inicio;

void cria_lista_inv();
void show_content();
float media_rec(struct ptr *aux, int count, int soma);

int main(){
    cria_lista_inv();
    show_content();
    printf("media = %f\n", media_rec(inicio, 0, 0));
}

float media_rec(struct ptr *aux, int count, int soma){
    int valor;
    if(inicio == (struct ptr *) NULL)
        return 0;
    if(aux != (struct ptr *) NULL){
        valor = aux->valor;
        aux = aux->prox;
        return media_rec(aux, count + 1, soma + valor);
    }
    else{
        aux = (struct ptr *) NULL;
        return (float) soma/count;
    }
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