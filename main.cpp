
/********************************************************
 * Henrique Colonese Echternacht             - 201835028
 * Lívia Pereira Ozório                      - 201835011
 * Regina Sarah Monferrari Amorim de Paula   - 201835007
 *******************************************************/
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
#include "Leitura.h"
#include "Ordenacao.h"
#include "Book.h"
#include "Author.h"
#include "Hash.h"
#include "ArvoreVP.h"
#include "NoVP.h"
#include "ArvoreB.h"

using namespace std;

#define MENOR -1
#define IGUAL 0
#define MAIOR 1
#define INFINITO -1

//int numComparacoes = 0;
//int numCopias = 0;
string quickk = "QuickSort";
string mergee = "MergeSort";

string arvore_b_2 = "Arvore B (2)";
string arvore_b_10 = "Arvore B (10)";
string arvore_vp = "Arvore Vermelha e Preta";


///Escrita no arquivo de saida
void Escrita(ofstream* Saida, string tipo_arvore, double tempo_processamento, int comparacoes, int copias, int tamanho)
{
        *Saida << tipo_arvore << endl;
        *Saida << "Tamanho: " << tamanho << endl;
        *Saida << "Tempo de Processamento: " << tempo_processamento << endl;
        *Saida << "Numero de Comparacoes: " << comparacoes << endl;
        *Saida << "Numero de Copias: " << copias << endl << endl;
}

void Escrita_parte2(ofstream* Saida, vector<Author*> autor, int m)
{
        *Saida << "PARTE 2" << endl;
        *Saida << "M = " << m << endl;
        for(int i = 0; i < m; i++)
        {
          *Saida << "Nome Autor: " << autor[i]->get_nome()  << " Frequencia: " << autor[i]->get_contador() << endl;
        }
        //cout << endl << endl;
}



int main()
{
    int N = 0;
    int M = 703200;
    int m = 1;
    ifstream entrada;
    ofstream saida;
    Hash* authors = new Hash(M);
    leituraAuthor(authors, M);
    //authors->imprime();
    entrada.open("arquivos/entrada.txt");
    saida.open("arquivos/saida.txt");

    if(entrada.is_open())
    {
        string n;
        getline(entrada, n);
        N = std::stoi(n);
        int tamanho[N];
        vector<Author*> autor_ordenado;
        ArvoreVP vp;
        ArvoreB b_2(2);
        ArvoreB b_10(10);
       
        for (int i = 0; i < N; i++)
        {
            getline(entrada, n);
            tamanho[i] = std::stoi(n);

            Book *lista = new Book[tamanho[i]];

            Book *lista2 = new Book[tamanho[i]];
            leitura_dataset(lista, tamanho[i], authors, &autor_ordenado);

            igual(lista2, lista, tamanho[i]);

            numComparacoes = 0;
            numCopias = 0;

            int tamOrdenado=autor_ordenado.size();
            ///PARTE 2
            MergeSortInt(autor_ordenado[0], 0, tamOrdenado-1);

            Escrita_parte2(&saida, autor_ordenado, m);

            ///PARTE 3
            saida << endl << "PARTE3" << endl << endl;
            auto start = std::chrono::steady_clock::now();
            insercao_b(lista, &b_2, tamanho[i]);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end-start;

            Escrita(&saida, arvore_b_2, elapsed_seconds.count(), b_2.num_comparacoes, b_2.num_copias, tamanho[i]);

            start = std::chrono::steady_clock::now();
            insercao_b(lista, &b_10, tamanho[i]);
            end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_sec = end-start;

            Escrita(&saida, arvore_b_10, elapsed_sec.count(), b_10.num_comparacoes, b_10.num_copias, tamanho[i]);
            
            start = std::chrono::steady_clock::now();
            insercao_vp(lista, &vp, tamanho[i]);
            end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_second = end-start;

            Escrita(&saida, arvore_vp, elapsed_second.count(), vp.num_comparacoes, vp.num_copias, tamanho[i]);
            
            
            delete[] lista;
            delete[] lista2;     
        }
        saida.close();
        cout << "A ordenacao foi finalizada!" << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo" << endl;
    }
    return 0;
}
