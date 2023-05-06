#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x)
{
    celula *new = (celula *)malloc(sizeof(celula));
    new->dado = x;
    new->prox = le->prox;
    le->prox = new;
}

void insere_antes(celula *le, int x, int y)
{
    celula *p = le->prox;
    celula *ant = le;
    while (p != NULL && p->dado != y)
    {
        ant = p;
        p = p->prox;
    }
    celula *new = (celula *)malloc(sizeof(celula));

    new->dado = x;
    new->prox = p;
    ant->prox = new;
}
