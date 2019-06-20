#include "../include/ListaEncadeada.h"
#include "../include/Indexador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esta_vazia_Lista(Lista *lista)
{
    return lista->cabeca == NULL;
}

Celula *cria_Celula_vazia()
{
    Celula *celulaVazia = (Celula *)malloc(sizeof(Celula));
    celulaVazia->prox = NULL;

    return celulaVazia;
}

// int QuantidadeLista(Lista *lista)
// {
//     return (lista->tamanho);
// }

int existe_palavra(Palavra *x, Lista *lista)
{
    if (EstaVazio(lista))
    {
        return 0;
    }
    Celula *atual = lista->cabeca;

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
    if (EstaVazio(lista))
    {
        printf("Lista vazia.\n");
        return -1;
    }
    Celula *atual = lista->cabeca;

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

void insere_Lista_antigo(Palavra *x, Lista *lista)
{
    int i = 0, indice_palavra = indice_palavra(x, lista);
    printf("Inserindo...\n");
    if (indice_palavra == -1) // Palavra não existe na lista
    {
        printf("Palavra NAO existe na lista\n");
        lista->ultimo->prox = (Celula *)malloc(sizeof(Celula));
        lista->ultimo = lista->ultimo->prox;
        lista->ultimo->palavra = x;
        lista->ultimo->prox = NULL;
        // lista->tamanho++;
    }
    else // Palavra existe na lista
    {
        printf("Palavra existe na lista\n");
        Celula *atual = lista->cabeca;
        for (i = 1; i < indice_palavra; i++) // Buscando posição da célula da palavra
        {
            atual = atual->prox;
        }
        atual->palavra->ocorrencias++;
        realloc(atual->palavra->posicoes, get_ocorrencias(atual) + 1);
        /* atual->palavra->posicoes ... */
    }
}

void retira_Lista(int x, Lista *lista, int *cartaRetirada)
{
    Celula *atual, *anterior;

    anterior = lista->cabeca;
    for (atual = lista->cabeca; atual != NULL; atual = atual->prox)
    {
        // if ((Valor(Carta(atual)) == Valor(x)) && (Naipe(Carta(atual)) == Naipe(x)))
        // {
        //     *cartaRetirada = Carta(atual);
        //     anterior->prox = atual->prox;
        //     free(atual);
        // lista->tamanho--;
        //     return;
        // }
        anterior = atual;
    }
    // *cartaRetirada = CartaVazia();
}

void imprime_lista(Lista *lista)
{
    Celula *aux = lista->cabeca;
    while (aux != NULL)
    {
        imprime_Palavra(aux->palavra);
        aux = aux->prox;
    }
}

void destroi_Celula(Celula *celula)
{
    destroi_Palavra(celula->palavra);
}

void destroi_Lista(Lista *lista)
{
    Celula *anterior, *atual;

    atual = lista->cabeca;
    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->prox;
        destroi_Celula(anterior);
    }

    // lista->tamanho = -1;
}

//vam ve se essa parte aqui de baixo vamo
Lista *cria_Lista()
{
    Lista *nova = malloc(sizeof(Lista));
    nova->cabeca = NULL;
    nova->ultimo = NULL;
    return nova;
}

void insere_Lista(Palavra *x, Lista *l)
{
    Celula *nova = malloc(sizeof(Celula));
    nova->palavra = malloc(sizeof(Palavra));
    nova->palavra->string = malloc(sizeof(char) * strlen(x->string) + 1);
    strcpy(nova->palavra->string, x->string);
    nova->palavra->ocorrencias = x->ocorrencias;
    nova->prox = NULL;
    if (l->cabeca == NULL)
    {
        l->cabeca = nova;
        l->ultimo = nova;
        return;
    }
    else
    {
        Celula *aux = l->cabeca;
        while (aux != NULL)
        {
            if (!strcasecmp(x->string, aux->palavra->string))
            {
                printf("PALAVRA JÁ EXISTE\n");
                aux->palavra->ocorrencias++;
                free(nova->palavra->string);
                free(nova->palavra);
                free(nova);
                return;
            }
            aux = aux->prox;
        }
        l->ultimo->prox = nova;
    }
}
