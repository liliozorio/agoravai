#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <utility>
#include <random>
#include <chrono>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <vector> 
#include <boost/algorithm/string.hpp>
#include "Book.h"
#include "Author.h"
#include "Hash.h"
#include "ArvoreVP.h"
#include "NoVP.h"


using namespace std;

#define MENOR -1
#define IGUAL 0
#define MAIOR 1
#define INFINITO -1

int numComparacoes = 0;
int numCopias = 0;

/// Retorna -1 caso pivo menor e 1 caso pivo maior, retorna 0 caso igual
int compara_string(Book pivo, Book qualquer) 
{
    int tamanho_pivo;
    int tamanho_qualquer;
    int maiusculo_minusculo = 'a' - 'A';

    numComparacoes++;

    for(int i=0; pivo.get_title()[i] != '\0' && qualquer.get_title()[i] != '\0'; i++)
    {
        if(pivo.get_title()[i] > 'Z' && qualquer.get_title()[i] > 'Z') /// Ve se os dois s�o minusculos
        {
            if(pivo.get_title()[i] > qualquer.get_title()[i])
            {
                return MAIOR;
            }
            else if(qualquer.get_title()[i] > pivo.get_title()[i])
            {
                return MENOR;
            }
        }
        else if(pivo.get_title()[i] < 'a' && qualquer.get_title()[i] < 'a') /// ve se os dois s�o maiusculos
        {
            if(pivo.get_title()[i] > qualquer.get_title()[i])
            {
                return MAIOR;
            }
            else if(qualquer.get_title()[i] > pivo.get_title()[i])
            {
                return MENOR;
            }
        }
        else if(pivo.get_title()[i] < 'a') /// ve letra do pivo maiuscula, se for a letra do qualquer eh minuscula
        {
            if(pivo.get_title()[i]+maiusculo_minusculo > qualquer.get_title()[i])
            {
                return MAIOR;
            }
            else if(qualquer.get_title()[i] > pivo.get_title()[i]+maiusculo_minusculo)
            {
                return MENOR;
            }
        }
        else /// letra do qualquer maiuscula e a letra do pivo eh minuscula
        {
            if(pivo.get_title()[i] > qualquer.get_title()[i]+maiusculo_minusculo)
            {
                return MAIOR;
            }
            else if(qualquer.get_title()[i]+maiusculo_minusculo > pivo.get_title()[i])
            {
                return MENOR;
            }
        }
    }

    tamanho_pivo = string_size(pivo.get_title());
    tamanho_qualquer = string_size(qualquer.get_title());

    if(tamanho_pivo < tamanho_qualquer)
    {
        return MENOR;
    }
    else if(tamanho_pivo > tamanho_qualquer)
    {
        return MAIOR;
    }
    else
    {
        return IGUAL;
    }
}

///Funcao para escolher o pivo do metodo QuickSort
int escolhe_pivo(Book *livro, int id_1, int id_2, int id_3)
{
    int compara_1_2 = compara_string(livro[id_1],livro[id_2]);
    int compara_1_3 = compara_string(livro[id_1],livro[id_3]);
    int compara_2_3 = compara_string(livro[id_2],livro[id_3]);

    if(compara_1_2 == 0 || compara_1_3 == 0 || compara_2_3 == 0)
    {
        if(compara_1_2 == 0)
        {
            return id_1;
        }
        else if(compara_1_3 == 0)
        {
            return id_1;
        }
        else
        {
            return id_2;
        }
    }
    if ((compara_1_2 == -1 && compara_2_3 == -1) || (compara_2_3 == 1 && compara_1_2 == 1))
    {
        return id_2;
    }
    if ((compara_1_2 == 1 && compara_1_3 == -1) || (compara_1_3 == 1 && compara_1_2 == -1))
    {
        return id_1;
    }
    return id_3;
}

///Função auxiliar do QuickSort
int Particionamento(Book *livro, int esquerda, int direita)
{
    int meio;
    int pivo_indice = 0;
    meio = (esquerda + direita)/2;
    pivo_indice = escolhe_pivo(livro, esquerda, meio, direita);
    Book pivo = livro[pivo_indice];

    int i = esquerda;
    int j = direita;
    Book aux;
    while(i<=j)
    {
        while(compara_string(livro[i], pivo) == -1)
        {
            i++;
        }
        while(compara_string (livro[j], pivo) == 1)
        {
            j--;
        }
        if(i <= j)
        {
            aux = livro[i];
            livro[i] = livro[j];
            livro[j] = aux;
            i++;
            j--;
            numCopias++;
        }
        else
        {
            break;
        }
    }
    return i;
}

///Metodo QuickSort
void QuickSort(Book *livro, int esquerda, int direita)
{
    if(direita - esquerda > 0)
    {
        int particao = Particionamento(livro, esquerda, direita);
        QuickSort(livro, esquerda, particao-1);
        QuickSort(livro, particao, direita);
    }
}

///Função para igualar dois vetores de livros
void igual(Book livro1[], Book livro2[], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        livro1[i] = livro2[i];
    }
}

///Função auxiliar no MergeSort
void MergeTripleSort(Book *Livro, int primeiro, int meio, int ultimo)
{
    int x, y;
    int a = meio - primeiro +1;
    int b = ultimo - meio;
    Book *Primeiro = new Book[a];
    Book *Segundo = new Book[b];

    for(int x = 0; x < a; x++)
    {
        Primeiro[x] = Livro[primeiro+x];
    }
    for(int y = 0; y < b; y++)
    {
        Segundo[y] = Livro[meio+1+y];
    }
    x = 0;
    y = 0;
    int z = primeiro;

    while(x < a && y < b)
    {
        if(compara_string(Primeiro[x],Segundo[y]) == -1 || compara_string(Primeiro[x],Segundo[y]) == 0)
        {
            Livro[z] = Primeiro[x];
            x++;
            numCopias++;
        }
        else
        {
            Livro[z] = Segundo[y];
            y++;
            numCopias++;
        }
        z++;
    }
    while(x < a)
    {
        Livro[z] = Primeiro[x];
        x++;
        z++;
        numCopias++;
    }
    while(y < b)
    {
        Livro[z] = Segundo[y];
        y++;
        z++;
        numCopias++;
    }
    delete [] Primeiro;
    delete [] Segundo;
}

///Metodo MergeSort
void MergeSort(Book *Livro, int primeiro, int ultimo)
{
    int media;
    if(primeiro < ultimo)
    {
        media = primeiro + (ultimo - primeiro)/2;
        MergeSort(Livro, primeiro, media);
        MergeSort(Livro, media+1, ultimo);
        MergeTripleSort(Livro, primeiro, media, ultimo);
    }
}

///Auxiliar MergeSort para inteiro
void MergeTripleSortInt(Author *autor_ordenado, int primeiro, int meio, int ultimo)
{
    int x, y, z;
    int a = meio - primeiro +1;
    int b = ultimo - meio;
    Author *Primeiro = new Author[a];
    Author *Segundo  = new Author[b];
    for(int x = 0; x < a; x++)
    {
        Primeiro[x] = autor_ordenado[primeiro+x];
    }
    for(int y = 0; y < b; y++)
    {
        Segundo[y] = autor_ordenado[meio+1+y];
    }

    x = 0;
    y = 0;
    z = primeiro;

    while(x < a && y < b)
    {
        if(Primeiro[x].get_contador() > Segundo[y].get_contador())
        {
            autor_ordenado[z] = Primeiro[x];
            x++;
            numCopias++;
        }
        else
        {
            autor_ordenado[z] = Segundo[y];
            y++;
            numCopias++;
        }
        z++;
    }
    while(x < a)
    {
        autor_ordenado[z] = Primeiro[x];
        x++;
        z++;
        numCopias++;
    }
    while(y < b)
    {
        autor_ordenado[z] = Segundo[y];
        y++;
        z++;
        numCopias++;
    }
    
    delete [] Primeiro;
    delete [] Segundo;
}

///Metodo MergeSort para inteiro
void MergeSortInt(Author *autor_ordenado, int primeiro, int ultimo)
{
    int media;
    if(primeiro < ultimo)
    {
        media = primeiro + (ultimo - primeiro)/2;
        MergeSortInt(autor_ordenado, primeiro, media);
        MergeSortInt(autor_ordenado, media+1, ultimo);
        MergeTripleSortInt(autor_ordenado, primeiro, media, ultimo);
    }
}
