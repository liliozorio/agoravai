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
#include "ArvoreB.h"

using namespace std;

///Retorna o tamanho da string
int string_size(string s)
{
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}

///Funcao para separar os parametros
string separar(ifstream* arquivo)
{
    string line;
    getline(*arquivo,line,'"');
    getline(*arquivo,line,'"');
    return line;
}

/// Separa string de autores
void separaAutores(string line, Hash *h, vector<Author*> *autor_ordenado)
{
  vector<string> autor;
  boost::split(autor, line, boost::is_any_of(","));
  static int indice_autor = 0;
  for(int i = 0; i < autor.size(); i++)
  {
    Author* aux;
    aux = h->lookup(std::stoi(autor[i]));
    
    if(aux != NULL)
    {
      if(aux->get_contador() == 0)
      {
        aux->cont_mais_um();
        autor_ordenado->push_back(aux);
        indice_autor++;
      }
      else
      {
        aux->cont_mais_um();
      }
    }
  }
}

///Função auxiliar nos testes
void imprimir(Book leitura)
{
    cout << leitura.get_title() << " - " << leitura.get_bestsellers_rank() << " - " << leitura.get_categories() << endl;
}

///Leitura do arquivo authos.csv
void leituraAuthor(Hash* autor, int tam)
{
    ifstream arquivoAuthors;
    arquivoAuthors.open("arquivos/authors.txt");
    int i = 0;
    
    while(i < tam)
    {
      Author autorAux2;
      autor->create(&autorAux2);
      i++;
    }
    if(arquivoAuthors.is_open())
    {
        i = 0;
        string word, trash, line;
        string linha;
        while(i < tam)
        {
            Author autorAux;
            ///CODIGo
            line = separar(&arquivoAuthors);
            if(line == "")
                line = '0';
            //cout << line << endl;
            int aux=std::stoi(line);
            autorAux.set_codigo(aux);
            
            ///NOME
            line = separar(&arquivoAuthors);
            //cout << line << endl;
            autorAux.set_nome(line);
            ///inserindo na hash
            
            autor->insere(&autorAux);
            i++;
        }
    }
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

/// Função de leitura para arquivo 
void leitura_dataset(Book* lista, int tamanho, Hash *h, vector<Author*> * autor_ordenado, ArvoreVP* vp, ArvoreB* b)
{
  ifstream arquivo;
  arquivo.open("arquivos/testeEntrada.txt");
  if(arquivo.is_open())
  {
    string word, trash, line, linha;
    int vet[14];
    for(int i = 0; i < 14; i++)
    {
      vet[i] = i;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(&vet[0], &vet[14], std::default_random_engine(seed));
    for(int i = 0; i < tamanho; i++)
    {
      int a = vet[i];
      int j = 0;
      arquivo.seekg(0);
      while(j < a)
      {
        getline(arquivo, line);
        j++;
      }
      ///AUTOR
      getline(arquivo,line,'"');
      getline(arquivo,line,'[');
      getline(arquivo,line,']');
      getline(arquivo,trash,'"');
      lista[i].set_authours(line);
      cout<< "Oi: " << line << " - " << lista[i].get_authors() << endl;
      separaAutores(line, h, autor_ordenado);
      ///RANK BESTSELLERS
      line = separar(&arquivo);
      if(line == "")
        line = '0';
      lista[i].set_bestseller_rank(std::stoi(line));
      ///CATEGORIAS
      getline(arquivo,line,'"');
      getline(arquivo,line,'[');
      getline(arquivo,line,']');
      getline(arquivo,trash,'"');
      lista[i].set_categories(line);
      ///EDICAO
      line = separar(&arquivo);
      lista[i].set_edition(line);
      ///ID
      line = separar(&arquivo);
      if(line == "")
        line = '0';
      lista[i].set_id(std::stol(line));
      ///ISBN-10
      line = separar(&arquivo);
      lista[i].set_isbn10(line);
      ///ISBN-13
      line = separar(&arquivo);
      lista[i].set_isbn13(line);
      ///RATING-AVG
      line = separar(&arquivo);
      if(line == "")
        line = '0';
      lista[i].set_rating_avg(std::stof(line));
      ///RATING-COUNT
      line = separar(&arquivo);
      if(line == "")
        line = '0';
      lista[i].set_rating_count(std::stoi(line));
      ///TITULO
      line = separar(&arquivo);
      lista[i].set_title(line);
    }
    arquivo.close();
  }
  else
  {
    cout << "Erro ao abrir o arquivo";
    exit(1);
  }
}

/// Insere livros na arvore B
void insercao_b(Book *lista, ArvoreB *b, int tamanho)
{
  for(int i = 0; i < tamanho; i++)
  {
    b->insercao(&lista[i]);
  }
}

/// Insere livros na arvore vermelha e preta
void insercao_vp(Book *lista, ArvoreVP *vp, int tamanho)
{
  for(int i = 0; i < tamanho; i++)
  {
    vp->insercao(lista[i], vp->get_raiz());
  }
}

/// busca livro na arvore B
void busca_b(Book *info, ArvoreB *b, int tamanho)
{
  for(int i = 0; i < tamanho; i++)
  {
    b->busca(&info[i], b->get_raiz());
  }
}

/// busca livro na arvore vermelha e preta
void busca_vp(Book *info, ArvoreVP *vp, int tamanho)
{
  for(int i = 0; i < tamanho; i++)
  {
    vp->busca(info[i], vp->get_raiz());
  }
}
