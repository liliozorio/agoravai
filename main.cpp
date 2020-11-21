
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


///Escrita no arquivo de saida
void Escrita(ofstream* Saida, string tipo_ordena, double tempo_processamento, int tamanho)
{
    cout << tipo_ordena << endl;
        *Saida << tipo_ordena << endl;
        *Saida << "Tamanho: " << tamanho << endl;
        *Saida << "Tempo de Processamento: " << tempo_processamento << endl;
        *Saida << "Numero de Comparacoes: " << numComparacoes << endl;
        *Saida << "Numero de Copias: " << numCopias << endl << endl;
}



/*void imprime_arvore(NoVP *p, int espaco){
    if (p == nullptr)
      return;
    espaco = espaco + 1;
    imprime_arvore(p->get_direito(), espaco);
    for (int i = 1; i < espaco; i++)
    {
        cout<<"\t";
    }

    cout<<p->get_info().get_id() << "::" << p->get_cor() <<"\n";
    imprime_arvore(p->get_esquerdo(), espaco);
}*/


int main()
{
    int N = 0;

    ifstream entrada;
    ofstream saida;

    Hash* authors = new Hash(500);
    leituraAuthor(authors, 500);
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
        ArvoreB b(2);
        
        for (int i = 0; i < N; i++)
        {
            getline(entrada, n);
            tamanho[i] = std::stoi(n);

            Book *lista = new Book[tamanho[i]];
            Book *lista2 = new Book[tamanho[i]];
            
            //leituraDataSet(lista, tamanho[i]);
            leitura_dataset(lista, tamanho[i], authors, &autor_ordenado, &vp, &b);
                      
            igual(lista2, lista, tamanho[i]);

            numComparacoes = 0;
            numCopias = 0;

            int tamOrdenado=autor_ordenado.size();
            
            MergeSortInt(autor_ordenado[0], 0, tamOrdenado-1);

            for(int i=0; i < tamOrdenado; i++)
            {
              cout << "Cod: " << autor_ordenado[i]->get_codigo() << " - Cont: " << autor_ordenado[i]->get_contador() << endl;
            }
            cout << "è aqui?" << endl;
            vp.~ArvoreVP();
            delete[] lista;
            delete[] lista2;
/*********************************************************            
            auto start = std::chrono::steady_clock::now();
            QuickSort(lista, 0, tamanho[i] - 1);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end-start;

            Escrita(&saida, quickk, elapsed_seconds.count(), tamanho[i]);

            numComparacoes = 0;
            numCopias = 0;

            start = std::chrono::steady_clock::now();
            MergeSort(lista2, 0, tamanho[i]-1);
            end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_second = end-start;

            Escrita(&saida, mergee, elapsed_second.count(), tamanho[i]);

            start = std::chrono::steady_clock::now();
            Escrita(&saida, mergee, elapsed_sec.count(), tamanho[i]);

            end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_sec = end-start;
***************************************************************/      
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
