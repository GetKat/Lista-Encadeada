#pragma once

struct node {
    int data;
    struct node *next, *prev;
};

void show_content();
void show_content(struct node *aux);

void debug();
void debug(struct node *aux);

void cria_lista();
void cria_lista(struct node **inicio);