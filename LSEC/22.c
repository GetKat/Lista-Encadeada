#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void merge_sort(struct node **aux);
struct node *merge(struct node *a, struct node *b);
void split(struct node *inicio, struct node **primeira, struct node **segunda);
void fix(struct node *inicio);
void transform(struct node *inicio);
void ordenar();

struct node *inicio;

int main(){
    cria_lista();
    show_content();
    ordenar();
    debug();
}

void ordenar(){
    transform(inicio);
    merge_sort(&inicio);
    fix(inicio);
}

void merge_sort(struct node **aux){
    struct node *head, *a, *b;
    head = *aux;
    if(head != (struct node *)NULL && head->next != (struct node *)NULL){
        split(head, &a, &b);
        merge_sort(&a);
        merge_sort(&b);

        *aux = merge(a, b);
    }
}

void split(struct node *inicio, struct node **primeira, struct node **segunda){
    struct node *fast, *slow;
    slow = inicio;
    fast = inicio->next;

    while(fast != (struct node *)NULL){
        fast = fast->next;
        if(fast != (struct node *)NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *primeira = inicio;
    *segunda = slow->next;
    slow->next = (struct node *)NULL;
    slow = (struct node *)NULL;
}

void transform(struct node *inicio){
    struct node *aux;
    if(inicio != (struct node *)NULL){
        aux = inicio;
        while(aux->next != inicio && aux->next != (struct node *)NULL)
            aux = aux->next;
        aux->next = (struct node *)NULL;
    }
    aux = (struct node *)NULL;
}

void fix(struct node *inicio){
    struct node *aux;
    aux = inicio;
    while(aux->next != (struct node *)NULL)
        aux = aux->next;
    aux->next = inicio;
}

struct node *merge(struct node *a, struct node *b){
    struct node *result;
    result = (struct node *)NULL;
    if(a == (struct node *)NULL)
        return b;
    if(b == (struct node *)NULL)
        return a;
    if(a->data < b->data){
        result = a;
        result->next = merge(a->next, b);
    }
    else{
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}