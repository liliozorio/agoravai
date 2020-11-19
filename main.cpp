
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
string quickk = "QuickSort";
string mergee = "MergeSort";

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

///Fun��o auxiliar nos testes
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

///Leitura do arquivo de entrada
/*void leituraDataSet(Book* lista,int tam)
{
    ifstream arquivo;
    arquivo.open("arquivos/testeEntrada.txt");

    int i = 0;
    srand(time(NULL));

    if(arquivo.is_open())
    {
        string word, trash, line;
        string linha;
        while(i < tam)
        {
            arquivo.seekg(0);
            int a = rand() % 1087014; ///TAMANHO DO DATASET
            int j = 0;
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
            ///EDI��O
            line = separar(&arquivo);
            lista[i].set_edition(line);
            ///ID
            line = separar(&arquivo);
            if(line == "")
                line = '0';
            lista[i].set_id(std::stof(line));
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
            ///T�TULO
            line = separar(&arquivo);
            lista[i].set_title(line);
            i++;
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
        exit(1);
    }
}*/

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
        aux->contMaisUm();
        autor_ordenado->push_back(aux);
        indice_autor++;
      }
      else
      {
        aux->contMaisUm();
      }
      //cout << "contador: " << aux->get_contador() << endl;
    }
  }
}

void imprime_arvore(NoVP *p, int espaco){
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
}

void leitura_dataset(Book* lista, int tamanho, Hash *h, vector<Author*> * autor_ordenado, ArvoreVP* vp)
{
  ifstream arquivo;
  arquivo.open("arquivos/testeEntrada.txt");
  if(arquivo.is_open())
  {
    string word, trash, line, linha;
    int vet[14];
    for(int i = 0; i<14; i++)
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
      ///EDI��O
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
      ///T�TULO
      line = separar(&arquivo);
      lista[i].set_title(line);
      vp->insercao(lista[i], vp->get_raiz());
    }
    arquivo.close();
  }
  else
  {
    cout << "Erro ao abrir o arquivo";
    exit(1);
  }
}

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

int compara_string(Book pivo, Book qualquer) /// Retorna -1 caso pivo menor e 1 caso pivo maior, retorna 0 caso igual
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

///Fun��o auxiliar do QuickSort
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

///Fun��o para igualar dois vetores de livros
void igual(Book livro1[], Book livro2[], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        livro1[i] = livro2[i];
    }
}

///Fun��o auxiliar no MergeSort
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

///M�todo MergeSort
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

///M�todo MergeSort
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

        for (int i = 0; i < N; i++)
        {
            getline(entrada, n);
            tamanho[i] = std::stoi(n);

            Book *lista = new Book[tamanho[i]];
            Book *lista2 = new Book[tamanho[i]];
            
            //leituraDataSet(lista, tamanho[i]);
            leitura_dataset(lista, tamanho[i], authors, &autor_ordenado, &vp);
                      
            igual(lista2, lista, tamanho[i]);

            numComparacoes = 0;
            numCopias = 0;

            int tamOrdenado=autor_ordenado.size();
            
            MergeSortInt(autor_ordenado[0], 0, tamOrdenado-1);

            for(int i=0; i < tamOrdenado; i++)
            {
              cout << "Cod: " << autor_ordenado[i]->get_codigo() << " - Cont: " << autor_ordenado[i]->get_contador() << endl;
            }

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
