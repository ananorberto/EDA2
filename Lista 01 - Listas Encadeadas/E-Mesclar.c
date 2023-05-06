 #include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3)
{
    celula *p1 = l1->prox;
    celula *p2 = l2->prox;
    celula *p3 = l3;

    for (; p1 != NULL && p2 != NULL; p3 = p3->prox)
    {
        if (p1->dado <= p2->dado) // Se l1 for menor ou igual a l2
        {
            p3->prox = p1; // l3 aponta para l1
            p1 = p1->prox; // avança p1 para l1
        }
        else
        {
            p3->prox = p2; // l3 aponta para l2
            p2 = p2->prox; // avança p2 para l2
        }
        p3 = p3->prox; // avança p3 para l3
    }

    p3->prox = (p1 != NULL) ? p1 : p2;

    l1->prox = NULL;
    l2->prox = NULL;
}

