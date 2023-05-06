#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de célula
typedef struct celula
{
    int dado;
    struct celula *prox; // ponteiro para a próxima célula
} celula;

// Função para remover a célula seguinte à célula apontada por p
int remove_depois(celula *p)
{
    celula *remover = p->prox; // ponteiro para a célula a ser removida

    if (remover == NULL) // se não há célula seguinte, retorna 0
        return 0;

    p->prox = remover->prox; // a célula anterior a remover agora aponta para a célula seguinte a remover
    int valor = remover->dado; // guarda o valor armazenado na célula a ser removida
    free(remover); // libera a memória alocada para a célula removida
    remover = NULL; // define o ponteiro como nulo, evitando que seja acessado novamente acidentalmente
    return valor; // retorna o valor armazenado na célula removida
}

// Função para remover a primeira ocorrência de um elemento x na lista
void remove_elemento(celula *le, int x)
{
    celula *p = le->prox; // ponteiro para a primeira célula da lista
    celula *ant = le; // ponteiro para a célula anterior a p
    while (p != NULL && p->dado != x) // procura a célula com o elemento x
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) // se a célula com o elemento x não foi encontrada, retorna
        return;

    ant->prox = p->prox; // a célula anterior a p agora aponta para a célula seguinte a p
    free(p); // libera a memória alocada para p
    p = NULL; // define o ponteiro como nulo, evitando que seja acessado novamente acidentalmente
}

// Função para remover todas as ocorrências de um elemento x na lista
void remove_todos_elementos(celula *le, int x)
{
    celula *p = le->prox; // ponteiro para a primeira célula da lista
    celula *ant = le; // ponteiro para a célula anterior a p
    while (p != NULL) // percorre a lista
    {
        if (p->dado == x) // se a célula atual tem o elemento x
        {
            ant->prox = p->prox; // a célula anterior a p agora aponta para a célula seguinte a p
            celula *remover = p; // ponteiro para a célula a ser removida
            p = p->prox; // p agora aponta para a célula seguinte a p
            free(remover); // libera a memória alocada para a célula a ser removida
            remover = NULL; // define o ponteiro como nulo, evitando que seja acessado novamente acidentalmente
        }
        else
        {
            ant = p;
            p = p->prox;
        }
    }
}
