#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void merge_sort(struct node **aux);
void split(struct node *inicio, struct node **primeira, struct node **segunda);
struct node *merge(struct node *first, struct node *second);

struct desc *lista;

int main(){
    cria_lista();
    show_content();
    merge_sort(&lista->inicio);
    show_content();
}

void merge_sort(struct node **aux){
    struct node *lista1, *lista2, *head;
    head = *aux;
    if(head != (struct node *)NULL && head->next != (struct node *)NULL){
        split(head, &lista1, &lista2);
        merge_sort(&lista1);
        merge_sort(&lista2);

        *aux = merge(lista1, lista2);
    }
}

struct node *merge(struct node *first, struct node *second){
    struct node *result;
    result = (struct node *)NULL;
    if(first == (struct node *)NULL)
        return second;
    if(second == (struct node *)NULL)
        return first;
    if(first->data <= second->data){
        result = first;
        result->next = merge(first->next, second);
    }
    else{
        result = second;
        result->next = merge(first, second->next);
    }
    return result;
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