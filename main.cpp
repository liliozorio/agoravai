#include <iostream>

#define _GLIBCXX_USE_C99 1

#include <string>
#include <fstream>
#include <map>
#include <utility>
#include "Book.h"

#define n 60000
#define CHEIA 0
#define VAZIA 1
#define BESTSELLERS 2
#define CATEGORIES 3
#define DESCRIPTION 4
#define DIMENSION_X 5
#define DIMENSION_Y 6
#define DIMENSION_Z 7
#define EDITION 8
#define EDITION_STATEMENT 9
#define FOR_AGES 10
#define FORMAT 11
#define ID 12
#define ILLUSTRATIONS 13
#define IMPRINT 14
#define INDEX_DATE 15
#define ISBN10 16
#define ISBN13 17
#define LANG 18
#define PUBLICATION_DATE 19
#define PUBLICATION_PLACE 20
#define RATING_AVG 21
#define RATING_COUNT 22
#define TITLE 23
#define URL 24
#define WEIGHT 25

using namespace std;
void MergeTripleSort(int Lista[], int primeiro, int meio, int ultimo){
    int x, y;
    int a = meio - primeiro +1;
    int b = ultimo - meio;
    int Primeiro[a], Segundo[b];

    for(int x = 0; x < a; x++){
        Primeiro[x] = Lista[primeiro+x];
    }
    for(int y = 0; y < b; y++){
        Segundo[y] = Lista[meio+1+y];
    }
    x = 0;
    y = 0;
    int z = primeiro;

    while(x < a && y < b){
        if(Primeiro[x] <= Segundo[y]){
            Lista[z] = Primeiro[x];
            x++;
        }
        else{
            Lista[z] = Segundo[y];
            y++;
        }
        z++;
    }
    while(x < a){
        Lista[z] = Primeiro[x];
        x++; z++;
    }
    while(y < b){
        Lista[z] = Segundo[y];
        y++; z++;
    }
}



void MergeSort(int Lista[], int primeiro, int ultimo){
    int media;
    if(primeiro < ultimo){
       media = primeiro + (ultimo - primeiro)/2;
       MergeSort(Lista, primeiro, media);
       MergeSort(Lista, media+1, ultimo);
       MergeTripleSort(Lista, primeiro, media, ultimo);
    }


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
    int tamanho_line;
    string separar, trash, line;
    getline(*arquivo,line,'"');
    getline(*arquivo,line,'"');
    return line;
}

void imprimir(Book leitura)
{
    cout << leitura.get_authors() << " - " << leitura.get_bestsellers_rank() << endl;
}

void leituraDataSet(Book* lista,int tam)
{
    ifstream arquivo;
    arquivo.open("testeEntrada.txt");
    int i=0;
    if(arquivo.is_open())
    {
        cout<<"entrei aqui"<< endl;
        string word, trash, line;
        string linha;
        while(i<tam)
        {
            ///AUTOR
            getline(arquivo,line,'"');
            getline(arquivo,line,'[');
            getline(arquivo,line,']');
            getline(arquivo,trash,'"');
            cout<<line<<endl;
            lista[i].set_authours(line);
            ///RANK BESTSELLERS
            line = separar(&arquivo);
            cout<<line<<endl;
            lista[i].set_bestseller_rank(std::stoi(line));
            ///CATEGORIAS
            getline(arquivo,line,'"');
            getline(arquivo,line,'[');
            getline(arquivo,line,']');
            getline(arquivo,trash,'"');
            cout<<line<<endl;
            lista[i].set_categories(line);
            ///EDIÇÃO
            line = separar(&arquivo);
            cout<<line<<endl;
            lista[i].set_edition(line);
            ///ID
            line = separar(&arquivo);
            cout<<line<<endl;
            lista[i].set_id(std::stof(line));
            ///ISBN-10
            line = separar(&arquivo);
            cout<<line<<endl;
            lista[i].set_isbn10(line);
            ///ISBN-13
            line = separar(&arquivo);
            cout<<line<<endl;
            lista[i].set_isbn13(line);
            ///RATING-AVG
            line = separar(&arquivo);
            cout<<line<<endl;
            lista[i].set_rating_avg(std::stof(line));
            ///RATING-COUNT
            line = separar(&arquivo);
            cout<<line<<endl;
            lista[i].set_rating_count(std::stoi(line));
            ///TÍTULO
            line = separar(&arquivo);
            cout<<line<<endl;
            lista[i].set_title(line);
            //imprimir(lista[i]);
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


int main()
{
    int tamanho=3;
    Book lista[tamanho];
    leituraDataSet(lista,tamanho);
    /*
    Book *lista_livros;
    map<string,string> authors;
    map<string,string> categories;
    map<string,string> formats;
    map<string,string> places;
    ///LE OS AUTORES E ARMAZENA EM UM HASHMAP
    ifstream arquivo;
    arquivo.open("arquivos/authors.csv");
    if(arquivo.is_open())
    {
        string line;
        string key;
        getline(arquivo,line);
        while(!arquivo.eof())
        {
            getline(arquivo,key,',');
            getline(arquivo,line,',');
            authors.insert(key,line);
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
        //exit(1);
    }
    ///LE AS CATEGORIAS E ARMAZENA EM UM HASHMAP
    ///TEM CATEGORIES QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR
    arquivo.open("arquivos/categories.csv");
    if(arquivo.is_open())
    {
        string line;
        string key;
        getline(arquivo,line);
        while(!arquivo.eof())
        {
            getline(arquivo,key,',');
            getline(arquivo,line,',');
            categories.insert(key,line);
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    //        exit(1);
    }
    ///LE OS FORMATOS E ARMAZENA EM UM HASHMAP
    arquivo.open("arquivos/formats.csv");
    if(arquivo.is_open())
    {
        string line;
        string key;
        getline(arquivo,line);
        while(!arquivo.eof())
        {
            getline(arquivo,key,',');
            getline(arquivo,line,',');
            formats.insert(key,line);
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    //        exit(1);
    }
    ///LE OS LUGARES E ARMAZENA EM UM HASHMAP
    ///TEM PLACES QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR
    arquivo.open("arquivos/places.csv");
    if(arquivo.is_open())
    {
        string line;
        string key;
        getline(arquivo,line);
        while(!arquivo.eof())
        {
            getline(arquivo,key,',');
            getline(arquivo,line,',');
            places.insert(key,line);
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    //        exit(1);
    }
    arquivo.open("arquivos/dataset.csv");
    if(arquivo.is_open())
    {
        string line;
        Book livro;
        getline(arquivo,line);
        while(!arquivo.eof())
        {
            getline(arquivo,line,',');
            int tamanho_line;
            tamanho_line = string_size(line);
            while(line[tamanho_line-1]!=']')
            {
                if(line[0]=='[')
                {
                    for(int i=1;i<tamanho_line;i++)
                    {
                        line[i-1]=line[i];
                    }
                }
                livro.set_authours(line);
                getline(arquivo,line,',');
                tamanho_line = string_size(line);
            }
            line[tamanho_line-1] = '\0';
            livro.set_authours(line);
            line = separar(&arquivo);
            livro.set_bestseller_rank(std::stoi(line));
            line = separar(&arquivo);
            tamanho_line = string_size(line);

            while(line[tamanho_line-1]!=']')
            {
                if(line[0]=='[')
                {
                    for(int i=1;i<tamanho_line;i++)
                    {
                        line[i-1]=line[i];
                    }
                }
                livro.set_categories(line);
                line = separar(&arquivo);
                tamanho_line = string_size(line);
            }
            line[tamanho_line-1]='\0';
            livro.set_categories(line);

            line = separar(&arquivo);
            livro.set_description(line); ///TEM DESCRIPTION QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR

            line = separar(&arquivo);
            livro.set_dimention_x(std::stof(line));

            line = separar(&arquivo);
            livro.set_dimention_y(std::stof(line));

            line = separar(&arquivo);
            livro.set_dimention_z(std::stof(line));

            line = separar(&arquivo);
            livro.set_edition(line); ///TEM EDITION QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR

            line = separar(&arquivo);
            livro.set_edition_statement(line); ///TEM EDITION_STATEMENT QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR

            line = separar(&arquivo);
            livro.set_for_ages(line);

            line = separar(&arquivo);
            livro.set_format(line);

            line = separar(&arquivo);
            livro.set_id(std::stoi(line));

            line = separar(&arquivo);
            livro.set_illustrations_note(line); ///TEM ILLUSTRATIONS_NOTE QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR

            line = separar(&arquivo);
            livro.set_imprint(line); ///TEM IMPRINT QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR

            line = separar(&arquivo);
            livro.set_index_date(line);

            line = separar(&arquivo);
            livro.set_isbn10(line);

            line = separar(&arquivo);
            livro.set_isbn13(line);

            line = separar(&arquivo);
            livro.set_lang(line);

            line = separar(&arquivo);
            livro.set_publication_date(line);

            line = separar(&arquivo);
            livro.set_publication_place(line);

            line = separar(&arquivo);
            livro.set_rating_avg(std::stof(line));

            line = separar(&arquivo);
            livro.set_rating_count(std::stoi(line));

            line = separar(&arquivo);
            livro.set_title(line); ///TEM TITLE QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR

            line = separar(&arquivo);
            livro.set_url(line);

            line = separar(&arquivo);
            livro.set_weight(std::stof(line));
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
        //exit(1);
    }*/
    return 0;
}
