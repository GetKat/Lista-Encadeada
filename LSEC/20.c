#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void apagar_lista_rec(struct node *aux, struct node *fim);

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    apagar_lista_rec(inicio, inicio);
    show_content();
}

void apagar_lista_rec(struct node *aux, struct node *fim){
    if(inicio != (struct node *)NULL){
        if(fim->next != inicio && fim->next != (struct node *)NULL){
            fim = fim->next;
            apagar_lista_rec(aux, fim);
        }
        else{
            fim->next = (struct node *)NULL;
            aux = inicio;
            inicio = inicio->next;
            aux->next = (struct node *)NULL;
            aux = (struct node *)NULL;
            apagar_lista_rec(inicio, fim);
        }
    }
    aux = (struct node *)NULL;
    fim = aux;
}
