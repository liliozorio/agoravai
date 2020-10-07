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
#include "Book.h"

using namespace std;
int numComparacoes = 0;
int numCopias = 0;

///RETORNA O TAMANHO DA STRING
int string_size(string s)
{
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}
string separar(ifstream* arquivo)
{
    string line;
    getline(*arquivo,line,'"');
    getline(*arquivo,line,'"');
    return line;
}
void imprimir(Book leitura)
{
    cout << leitura.get_title() << " - " << leitura.get_bestsellers_rank() << " - " << leitura.get_categories() << endl;
}
void leituraDataSet(Book* lista,int tam)
{
    srand(time(NULL));
    ifstream arquivo;
    arquivo.open("testeEntrada.txt");
    int i=0;
    if(arquivo.is_open())
    {
        string word, trash, line;
        string linha;

        while(i < tam)
        {
            arquivo.seekg(0);
            int a = rand() % 14; ///TAMANHO DO DATASET
            cout<<a<<endl;
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
            ///EDIÇÃO
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
            ///TÍTULO
            line = separar(&arquivo);
            lista[i].set_title(line);
            i++;
        }

        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
        //exit(1);
    }
}
int compara_string(Book pivo, Book qualquer) /// Retorna -1 caso pivo menor e 1 caso pivo maior, retorna 0 caso igual
{
    int tamanho_pivo;
    int tamanho_qualquer;
    int maiusculo_minusculo = 'a' - 'A';
    numComparacoes++;
    for(int i=0; pivo.get_title()[i] != '\0' && qualquer.get_title()[i] != '\0'; i++)
    {
        if(pivo.get_title()[i] > 'Z' && qualquer.get_title()[i] > 'Z') /// Ve se os dois são minusculos
        {
            if(pivo.get_title()[i] > qualquer.get_title()[i])
            {
                return 1;
            }
            else if(qualquer.get_title()[i] > pivo.get_title()[i])
            {
                return -1;
            }
        }
        else if(pivo.get_title()[i] < 'a' && qualquer.get_title()[i] < 'a') /// ve se os dois são maiusculos
        {
            if(pivo.get_title()[i] > qualquer.get_title()[i])
            {
                return 1;
            }
            else if(qualquer.get_title()[i] > pivo.get_title()[i])
            {
                return -1;
            }
        }
        else if(pivo.get_title()[i] < 'a') /// ve letra do pivo maiuscula, se for a letra do qualquer é minuscula
        {
            if(pivo.get_title()[i]+maiusculo_minusculo > qualquer.get_title()[i])
            {
                return 1;
            }
            else if(qualquer.get_title()[i] > pivo.get_title()[i]+maiusculo_minusculo)
            {
                return -1;
            }
        }
        else /// letra do qualquer maiuscula e a letra do pivo é minuscula
        {
            if(pivo.get_title()[i] > qualquer.get_title()[i]+maiusculo_minusculo)
            {
                return 1;
            }
            else if(qualquer.get_title()[i]+maiusculo_minusculo > pivo.get_title()[i])
            {
                return -1;
            }
        }
    }
    tamanho_pivo=string_size(pivo.get_title());
    tamanho_qualquer=string_size(qualquer.get_title());
    if(tamanho_pivo<tamanho_qualquer)
    {
        return -1;
    }
    else if(tamanho_pivo>tamanho_qualquer)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
///Função para escolher o pivo do metodo QuickSort
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
        while(compara_string(livro[i],pivo)==-1)
        {
            i++;
        }
        while(compara_string (livro[j],pivo)== 1)
        {
            j--;
        }
        if(i <= j)
        {
          aux = livro[i];
            livro[i] = livro[j];
            livro[j] = aux;
            numCopias++;
            i++;
            j--;
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
        QuickSort(livro, particao+1, direita);
    }
}
void igual(Book livro1[], Book livro2[], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        livro1[i] = livro2[i];
    }

}
void MergeTripleSort(Book *Livro, int primeiro, int meio, int ultimo){
    int x, y;
    int a = meio - primeiro +1;
    int b = ultimo - meio;
    Book Primeiro[a], Segundo[b];

    for(int x = 0; x < a; x++){
        Primeiro[x] = Livro[primeiro+x];
    }
    for(int y = 0; y < b; y++){
        Segundo[y] = Livro[meio+1+y];
    }
    x = 0;
    y = 0;
    int z = primeiro;

    while(x < a && y < b){
        if(compara_string(Primeiro[x],Segundo[y]) == -1 || compara_string(Primeiro[x],Segundo[y]) == 0){
            Livro[z] = Primeiro[x];
            x++;
            numCopias++;
        }
        else{
            Livro[z] = Segundo[y];
            y++;
            numCopias++;
        }
        z++;
    }
    while(x < a){
        Livro[z] = Primeiro[x];
        x++; z++;
        numCopias++;
    }
    while(y < b){
        Livro[z] = Segundo[y];
        y++; z++;
        numCopias++;
    }
}
void MergeSort(Book *Livro, int primeiro, int ultimo){
    int media;
    if(primeiro < ultimo){
       media = primeiro + (ultimo - primeiro)/2;
       MergeSort(Livro, primeiro, media);
       MergeSort(Livro, media+1, ultimo);
       MergeTripleSort(Livro, primeiro, media, ultimo);
    }
}
int main()
{
    int N = 0;
    ifstream entrada;
    entrada.open("entrada.txt");
    if(entrada.is_open())
    {
        string n;
        getline(entrada, n);
        N = std::stoi(n);
        int tamanho[N];
        for (int i=0; i<N; i++)
        {
            getline(entrada, n);
            tamanho[i] = std::stoi(n);

            Book lista[tamanho[i]];
            Book lista2[tamanho[i]];
            leituraDataSet(lista, tamanho[i]);
            igual(lista2, lista, tamanho[i]);

            QuickSort(lista, 0, tamanho[i] - 1);

            for(int j=0; j<tamanho[i]; j++)
            {
              imprimir(lista[j]);
            }
            cout << "________________________" << endl;
            MergeSort(lista2, 0, tamanho[i]-1);
            for(int j=0; j<tamanho[i]; j++)
            {
              imprimir(lista2[j]);
            }
            cout << "________________________" << endl;
        }
    }
    else
    {
        cout << "Poxa, que pena, nao abriu" << endl;
    }
    return 0;
}
