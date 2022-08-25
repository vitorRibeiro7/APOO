#include "iostream"

#define TAM_INICIAL 10
typedef int TipoElemento;
/**************************************
 * DADOS
 **************************************/
class Fila
{
private:
	TipoElemento *vetor;
	int tamVetor;
	int inicio;
	int fim;
	int qtdeElementos;

public:
	Fila()
	{
		this->vetor = new TipoElemento[TAM_INICIAL];
		this->tamVetor = TAM_INICIAL;
		this->inicio = 0;
		this->fim = 0;
		this->qtdeElementos = 0;
	}

	void destruir()
	{
		delete (this->vetor);
		this->vetor = NULL;
		this->tamVetor = NULL;
		this->inicio = NULL;
		this->fim = NULL;
		this->qtdeElementos = NULL;
	}

	void inserir(TipoElemento elemento)
	{

		this->vetor[this->qtdeElementos] = elemento;
		this->qtdeElementos++;

		if (this->qtdeElementos > 0)
		{
			this->fim++;
		}
	}

	bool remover()
	{
		int *aux = new TipoElemento[this->qtdeElementos];

		for (int i = 0; i < this->qtdeElementos; i++)
		{
			aux[i] = this->vetor[i];
		}

		for (int i = 0; i < this->qtdeElementos; i++)
		{
			this->vetor[i] = 0;
		}

		int j = 1;

		for (int i = 0; i < this->qtdeElementos; i++)
		{
			this->vetor[i] = aux[j];
			j++;
		}

		if (this->qtdeElementos > 0)
		{
			this->fim--;
		}

		if (this->qtdeElementos == 0)
		{
			return false;
		}

		this->qtdeElementos--;

		return true;
	}

	int primeiro()
	{
		return this->vetor[0];
	}

	bool vazia()
	{
		if (this->qtdeElementos == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int tamanho()
	{
		return this->qtdeElementos;
	}

	void imprimir()
	{
		for (int i = 0; i < this->qtdeElementos; i++)
		{
			printf("[");
			printf("%i", this->vetor[i]);
			printf("] ");
		}

		printf("\n");
	}
};

int main()
{

	Fila teste;

	teste.inserir(1);
	teste.inserir(2);
	teste.inserir(3);
	teste.inserir(4);
	teste.inserir(5);
	teste.inserir(6);
	teste.inserir(7);

	teste.imprimir();

	teste.remover();

	teste.imprimir();

	return 0;
}