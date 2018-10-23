#pragma once

struct node {
    int data;
    struct node *next;
};

struct desc {
    int count;
    struct node *inicio, *fim;
};

void cria_descritor(void);
void cria_descritor(struct desc **lista);

void show_content(void);
void show_content(struct desc *lista);

void debug(void);
void debug(struct desc *lista);

void cria_lista(void);
void cria_lista(struct desc **lista);