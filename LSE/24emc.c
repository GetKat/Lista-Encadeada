#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *inicio, *a, *b;

void unir_ordenado_rec();
void cria_lista(struct node **inicio);
void show_content(struct node *aux);

struct node *inicio, *a, *b;

int main(){
    cria_lista(&a);
    cria_lista(&b);
    unir_ordenado_rec();
    show_content(inicio);
}

void unir_ordenado_rec(){
    void unir(struct node *aux){
        void inserir_ordenado_rec(int data, struct node *prev, struct node *aux){
            //se a lista tiver vazia
            if(inicio == (struct node *)NULL){
                inicio = (struct node *)malloc(sizeof(struct node));
                inicio->data = data;
                inicio->next = (struct node *)NULL;
            }
            //inserir antes do inicio
            else if(inicio->data > data){
                aux = (struct node *)malloc(sizeof(struct node));
                aux->data = data;
                aux->next = inicio;
                inicio = aux;
            }
            else{
                if(aux->next != (struct node *)NULL && aux->data <= data){
                    prev = aux;
                    aux = aux->next;
                    inserir_ordenado_rec(data, prev, aux);
                }
                else{
                    //inserir dps de aux (fim)
                    if(aux->data <= data){
                        aux->next = (struct node *)malloc(sizeof(struct node));
                        aux = aux->next;
                        aux->data = data;
                        aux->next = (struct node *)NULL;
                    }
                    //inserir antes de aux (entre prev e aux)
                    else{
                        prev->next = (struct node *)malloc(sizeof(struct node));
                        prev = prev->next;
                        prev->data = data;
                        prev->next = aux;
                    }
                }     
            }
            aux = (struct node *)NULL;
            prev = aux;
        }
        if(aux != (struct node *)NULL){
            inserir_ordenado_rec(aux->data, (struct node *)NULL, inicio);
            aux = aux->next;
            unir(aux);
        }
    }
    unir(a);
    unir(b);
}

void cria_lista(struct node **inicio){
    int data;
    struct node *aux;
    *inicio = (struct node *)NULL;
    scanf("%d", &data);
    if(data >= 0){
        aux = (struct node *)malloc(sizeof(struct node));
        aux->data = data;
        aux->next = (struct node *)NULL;
        (*inicio) = aux;
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

void show_content(struct node *aux){
    if(aux == (struct node *)NULL)
        printf("Lista vazia!");
    while(aux != (struct node *)NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

