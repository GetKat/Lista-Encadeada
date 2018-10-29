#pragma once

struct node {
    int data;
    struct node *next, *prev;
};

struct desc {
    struct node *inicio, *fim;
    int count;
};

void show_content();

void cria_lista();

void cria_descritor();

void debug();