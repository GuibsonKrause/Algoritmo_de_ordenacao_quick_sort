#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fabricante
{
	char nome[50];
	char nacionalidade[50];
	int ano;
}Fabricante;

//======================================ASSINATURAS DAS FUNCOES===================================================
int Comparacao (Fabricante vet1, Fabricante vet2);
void swap (Fabricante *vet3, int i, int f);
int part (Fabricante *vet3, int inicio, int f);
void quick_Sort (Fabricante *vet3, int ini, int f);
void escrVetor(Fabricante *Fabricante, int n);

//======================================FUNCAO PRINCIPAL=========================================================
int main() 
{
	Fabricante  vet3[6];

	strcpy(vet3[0].nome, "Fiat");
	strcpy(vet3[0].nacionalidade, "Brasil");
	vet3[0].ano = 2000;

	strcpy(vet3[1].nome, "Fiat");
	strcpy(vet3[1].nacionalidade, "Brasil");
	vet3[1].ano = 1999;

	strcpy(vet3[2].nome, "Fox");
	strcpy(vet3[2].nacionalidade, "Colombia");
	vet3[2].ano = 1998;

	strcpy(vet3[3].nome, "Toyota");
	strcpy(vet3[3].nacionalidade, "Japao");
	vet3[3].ano = 1997;

	strcpy(vet3[4].nome, "Wolskwagen");
	strcpy(vet3[4].nacionalidade, "Coreia");
	vet3[4].ano = 1996;

	strcpy(vet3[5].nome, "Mazda");
	strcpy(vet3[5].nacionalidade, "Paraguai");
	vet3[5].ano = 1995;
	
	quick_Sort (vet3, 0, 6);
	escrVetor (vet3, 6);
	return 0;
}

int Comparacao (Fabricante vet1, Fabricante vet2)
{
	if(strcmp(vet1.nome, vet2.nome) == -1)
		{
			return(1);
		}
		if (strcmp(vet1.nome, vet2.nome) == 0)
		{
			if(strcmp(vet1.nacionalidade, vet2.nacionalidade) == -1)
			{
				return(1);
			}
			if (strcmp(vet1.nacionalidade, vet2.nacionalidade) == 0)
			{
				if (vet1.ano < vet2.ano)
				{
					return(1);
				}
				else
				{
					return(0);
				}
			}
			else
			{
				return(0);
			}
		}
		else
		{
			return(0);
		}
}

void swap (Fabricante *vet3, int i, int f)
{
	Fabricante auxiliar;
	auxiliar = vet3[i];
	vet3[i] = vet3[f];
	vet3 [f] = auxiliar;
}

int part (Fabricante *vet3, int inicio, int f1)
{
	Fabricante p[1];
	p[0] = vet3[inicio];
	int i = inicio + 1, f = f1;
	while(i <= f)
	{
		if(Comparacao(vet3[i], p[0]))
		{
			i++;
		}	
		else if(Comparacao(p[0], vet3[f]))
		{
			f--;
		}
		else
		{
			swap(vet3, i, f);
			i++;
			f--;
		}
	}
	vet3[inicio] = vet3[f];
	vet3[f] = p[0];
	return(f);
}

void quick_Sort (Fabricante *vet3, int ini, int f1)
{
	int meio;
	if(ini < f1)
	{
		meio = part(vet3, ini, f1);
		quick_Sort(vet3, ini, meio);
		quick_Sort(vet3, meio + 1, f1);
	}
}

void escrVetor(Fabricante *Fabricante, int n)
{
	int i;
	for (i = 0; i < n; i++){
		printf("\n %s\n %s\n %d \n\n", Fabricante[i].nome, Fabricante[i].nacionalidade, Fabricante[i].ano);
	}
}
