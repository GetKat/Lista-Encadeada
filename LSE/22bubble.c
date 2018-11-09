#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void ordenar();
void cria_lista();
void show_content();
void show_content();

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    ordenar();
    show_content();
}

void ordenar(){
    struct node *aux_j, *aux_i;
    void bubble_j(){
        if(aux_j != (struct node *)NULL){
            if(aux_i->data > aux_j->data){
                int temp = aux_i->data;
                aux_i->data = aux_j->data;
                aux_j->data = temp;
            }
            aux_j = aux_j->next;
            bubble_j();
        }
    }
    void bubble_i(){
        if(aux_i != (struct node *)NULL){
            aux_j = aux_i->next;
            bubble_j();
            aux_i = aux_i->next;
            bubble_i();
        }
    }
    aux_i = inicio;
    bubble_i();
}

void cria_lista(){
    struct node *aux;
    int data;

    inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        inicio = (struct node *)malloc(sizeof(struct node));
        inicio->data = data;
        inicio->next = (struct node *)NULL;
        aux = inicio;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = (struct node *)NULL;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}

void show_content(){
    struct node *aux;
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!");
    aux = inicio;
    while(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}