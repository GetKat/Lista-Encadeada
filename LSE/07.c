#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *inicio;

float media();
void media_alt();

int main(){
    cria_lista();
    show_content();
    printf("media: %f\n", media());
    media_alt();
}

float media(){
    struct node *aux;
    int count = 0;
    int soma = 0;
    aux = inicio;
    while(aux != (struct node *)NULL){
        count++;
        soma += aux->data;
        aux = aux->next;
    }
    if(count)
        return (float) soma / count;
    else
        return 0;
}

//Alternativa: fazer uma funcao que MOSTRE a media dos elementos ao invez de RETORNAR

void media_alt(){
    struct node *aux;
    int count = 0;
    int soma = 0;
    aux = inicio;
    while(aux != (struct node *)NULL){
        count++;
        soma += aux->data;
        aux = aux->next;
    }
    if(!count)
        printf("Lista vazia! N tem media!\n");
    else
        printf("media: %f\n", (float) soma / count);
}