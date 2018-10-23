#pragma once
struct node {
    int data;
    struct node *next;
};

void cria_descritor(void);
void cria_descritor(struct desc **inicio);

void show_content(void);
void show_content(struct desc *inicio);

void debug(void);
void debug(struct desc *inicio);

void cria_lista(void);
void cria_lista(struct desc **inicio);