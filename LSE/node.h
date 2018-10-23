#pragma once
struct node {
    int data;
    struct node *next;
};

void cria_descritor(void);
void cria_descritor(struct node **inicio);

void show_content(void);
void show_content(struct node *inicio);

void debug(void);
void debug(struct node *inicio);

void cria_lista(void);
void cria_lista(struct node **inicio);