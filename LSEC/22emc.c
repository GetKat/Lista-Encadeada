#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void cria_lista();
void ordenar();
void debug();

struct node *inicio;

int main(){
    cria_lista();
    debug();
    ordenar();
    debug();
}

void ordenar(){
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
    transform(inicio);
    merge_sort(&inicio);
    fix(inicio);
}

void debug(){
    //same as show_content()
    struct node *aux;
    aux = inicio;
    if(inicio == (struct node *)NULL)
        printf("Lista vazia!\n");
    else{
        do{
            printf("%d ", aux->data);
            aux = aux->next;
        }while(aux != inicio);
        printf("\n");
        //
        aux = inicio;
            while(aux->next != inicio)
                aux = aux->next;
        printf("ultimo elemento: %d\n", aux->data);
        printf("proximo: %d (inicio == %d)\n", aux->next->data, inicio->data);
        aux = (struct node *)NULL;
    }
}

void cria_lista(void){
    struct node *aux;
    int data;
    inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = aux;
        inicio = aux;
        scanf("%d", &data);
        while(data >= 0){
            aux->next = (struct node *)malloc(sizeof(struct node));
            aux = aux->next;
            aux->data = data;
            aux->next = inicio;
            scanf("%d", &data);
        }
    }
    aux = (struct node *)NULL;
}
