#include <iostream>

#define TAM_INICIAL 5

typedef int TipoElemento;
/**************************************
 * DADOS
 **************************************/
typedef struct pilha Pilha;

/**************************************
 * PROTÓTIPOS
 **************************************/
Pilha *pilha_criar();
void pilha_destruir(Pilha **endereco);
bool pilha_empilhar(Pilha *p, TipoElemento elemento);
bool pilha_desempilhar(Pilha *p, TipoElemento *saida);
bool pilha_topo(Pilha *p, TipoElemento *saida);
bool pilha_vazia(Pilha *p);
void pilha_imprimir(Pilha *p);
int pilha_tamanho(Pilha *p);
Pilha *pilha_clone(Pilha *p);
void pilha_inverter(Pilha *p);
bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor);
bool pilha_toString(Pilha *p, char *str);

/**************************************
 * DADOS
 **************************************/
class pilha
{

private:
public:
    TipoElemento *vetor;
    int tamVetor;
    int qtdeElementos;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Pilha *pilha_criar()
{
    Pilha *p;

    p = (Pilha *)malloc(sizeof(Pilha));
    p->vetor = (int *)malloc(TAM_INICIAL * sizeof(int));
    p->tamVetor = TAM_INICIAL;
    p->qtdeElementos = 0;

    return p;
}

void pilha_destruir(Pilha **endereco)
{

    Pilha *b = *endereco;
    free(b->vetor);
    b->vetor = NULL;

    free(b);
    b = NULL;
}
bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{

    if (p == NULL)
    {
        return false;
    }

    p->vetor[p->qtdeElementos] = elemento;
    p->qtdeElementos++;

    return true;
}

bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
    for (int i = 0; i < p->qtdeElementos; i++)
    {
        if (i == p->qtdeElementos - 1)
        {
            *saida = p->vetor[i];
            p->vetor[i] = NULL;
            p->qtdeElementos--;
        }
    }
}

bool pilha_topo(Pilha *p, TipoElemento *saida)
{

    *saida = p->vetor[p->qtdeElementos - 1];

    return true;
}

bool pilha_vazia(Pilha *p)
{
    if (p->qtdeElementos == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void pilha_imprimir(Pilha *p)
{
    for (int i = 0; i < p->qtdeElementos; i++)
    {
        printf("%i ", p->vetor[i]);
    }

    printf("\n");
}

int pilha_tamanho(Pilha *p)
{
    return p->qtdeElementos;
}

Pilha *pilha_clone(Pilha *p)
{
    Pilha *aux;
    aux = (Pilha *)malloc(sizeof(Pilha));
    aux->vetor = (int *)malloc(p->tamVetor * sizeof(int));
    aux->qtdeElementos = p->qtdeElementos;

    for (int i = 0; i < p->qtdeElementos; i++)
    {
        aux->vetor[i] = p->vetor[i];
    }

    return aux;
}

void pilha_inverter(Pilha *p)
{
    Pilha *clone;

    clone = pilha_clone(p);

    int j = pilha_tamanho(p) - 1;

    for (int i = 0; i < clone->qtdeElementos; i++)
    {
        p->vetor[i] = clone->vetor[j];

        j--;
    }
}

bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor)
{
    for (int i = 0; i < tamVetor; i++)
    {
        pilha_empilhar(p, vetor[i]);
    }
}