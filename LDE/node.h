#pragma once

struct node {
    int data;
    struct node *next, *prev;
};

void show_content();
void show_content_2(struct node *aux);
void show_content_debug();
void show_content_debug_2(struct node *aux);

void cria_lista();
void cria_lista_2(struct node **inicio);