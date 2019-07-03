#include "../include/lista_encadeada.h"
#include "../include/indexador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int esta_vazia_Lista(Lista *lista)
{
    return lista->primeiro == NULL;
}

Celula *cria_Celula_vazia()
{
    Celula *celulaVazia = (Celula *)malloc(sizeof(Celula));
    celulaVazia->prox = NULL;

    return celulaVazia;
}

int existe_palavra(Palavra *x, Lista *lista)
{
    if (esta_vazia_Lista(lista))
    {
        return 0;
    }
    Celula *atual = lista->primeiro;

    while (atual != NULL)
    {
        if (get_string(x) == get_string(atual))
        {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

int indice_Palavra(Palavra *x, Lista *lista)
{
    if (esta_vazia_Lista(lista))
    {
        printf("Lista vazia.\n");
        return -1;
    }
    Celula *atual = lista->primeiro;

    int i = 0;
    while (atual != NULL)
    {
        printf("%i <- oi\n", strcmp(get_string(x), get_string(atual)));
        if (strcmp(get_string(x), get_string(atual)) == 0)
        {
            printf("achei\n");
            return i;
        }
        atual = atual->prox;
        i++;
    }

    return -1;
}

void libera_Celula(Celula *celula)
{
    libera_Palavra(celula->palavra);
}
*/
void imprime_Lista(Lista *lista)
{
    Celula *aux = lista->primeiro;
    while (aux != NULL)
    {
        imprime_Palavra(aux->palavra);
        aux = aux->prox;
    }
}

void libera_Celula(Celula *cel)
{
    libera_Palavra(cel->palavra);
    free(cel);
}

void libera_Lista(Lista *lista)
{
    Celula *ant = NULL;
    Celula *aux = lista->primeiro;
    while (aux != NULL)
    {
        ant = aux;
        aux = aux->prox;
        libera_Celula(ant);
    }
    free(lista->nomeArquivo);
    free(lista);
}

Lista *cria_Lista()
{
    Lista *nova = malloc(sizeof(Lista));
    nova->primeiro = NULL;
    nova->ultimo = NULL;
    nova->nomeArquivo = (char *)malloc(sizeof(char) * 80);
    return nova;
}

// modularizar essa bagaceira
void insere_Lista(Palavra *x, Lista *l)
{
    Celula *nova = malloc(sizeof(Celula));
    nova->palavra = x; //passa o endereço
    nova->prox = NULL;
    if (l->primeiro == NULL)
    {
        l->primeiro = nova;
        l->ultimo = nova;
        return;
    }
    Celula *aux = l->primeiro;
    while (aux->prox != NULL && strcasecmp(get_string(aux->palavra), get_string(x)))
    {
        aux = aux->prox;
    }
    if (!strcasecmp(get_string(aux->palavra), get_string(x)))
    {
        insere_Ocorrencias(get_posicoes(aux->palavra), get_posicoes(x)->ultimo->ocorreu);
        aux->palavra->ocorrencias->qtd++;
        libera_Celula(nova);
        return;
    }
    l->ultimo->prox = nova;
    l->ultimo = nova;
    return;
}

Palavra *busca_Lista(char *strat, Lista *l)
{
    Celula *aux = l->primeiro;
    while (aux != NULL && strcasecmp(get_string(aux->palavra), strat))
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        return NULL;
    }
    if (!strcasecmp(get_string(aux->palavra), strat))
    {
        return aux->palavra;
    }
    return NULL;
}
