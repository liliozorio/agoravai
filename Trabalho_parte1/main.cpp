#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <utility>
#include "Book.h"

using namespace std;

#define _GLIBCXX_USE_C99 1

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

int main()
{
    Book *lista_livros;
    map<string,string> authors;
    map<string,string> categories;
    map<string,string> formats;
    map<string,string> places;
    ///LE OS AUTORES E ARMAZENA EM UM HASHMAP
    ifstream arquivo;
    arquivo.open("authors.csv");
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
    arquivo.open("categories.csv");
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
    arquivo.open("formats.csv");
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
    arquivo.open("places.csv");
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
    arquivo.open("dataset.csv");
    if(arquivo.is_open())
    {
        string line;
        getline(arquivo,line);
        while(!arquivo.eof())
        {
            Book livro;
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
                livro.set_authours(authors.find(line));
                getline(arquivo,line,',');
                tamanho_line = string_size(line);
            }
            line[tamanho_line-1] = '\0';
            livro.set_authours(authors.find(line));
            getline(arquivo,line,',');
            livro.set_bestseller_rank(std::stoi(line));
            getline(arquivo,line,',');
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
                livro.set_categories(categories.find(line));
                getline(arquivo,line,',');
                tamanho_line = string_size(line);
            }
            line[tamanho_line-1]='\0';
            livro.set_categories(line);
            getline(arquivo,line,',');
            livro.set_description(line); ///TEM DESCRIPTION QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR
            getline(arquivo,line,',');
            livro.set_dimention_x(std::stof(line));
            getline(arquivo,line,',');
            livro.set_dimention_y(std::stof(line));
            getline(arquivo,line,',');
            livro.set_dimention_z(std::stof(line));
            getline(arquivo,line,',');
            livro.set_edition(line); ///TEM EDITION QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR
            getline(arquivo,line,',');
            livro.set_edition_statement(line); ///TEM EDITION_STATEMENT QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR
            getline(arquivo,line,',');
            livro.set_for_ages(line);
            getline(arquivo,line,',');
            livro.set_format(formats.find(line));
            getline(arquivo,line,',');
            livro.set_id(std::stoi(line));
            getline(arquivo,line,',');
            livro.set_illustrations_note(line); ///TEM ILLUSTRATIONS_NOTE QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR
            getline(arquivo,line,',');
            livro.set_imprint(line); ///TEM IMPRINT QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR
            getline(arquivo,line,',');
            livro.set_index_date(line);
            getline(arquivo,line,',');
            livro.set_isbn10(line);
            getline(arquivo,line,',');
            livro.set_isbn13(line);
            getline(arquivo,line,',');
            livro.set_lang(line);
            getline(arquivo,line,',');
            livro.set_publication_date(line);
            getline(arquivo,line,',');
            livro.set_publication_place(places.find(line));
            getline(arquivo,line,',');
            livro.set_rating_avg(std::stof(line));
            getline(arquivo,line,',');
            livro.set_rating_count(std::stoi(line));
            getline(arquivo,line,',');
            livro.set_title(line); ///TEM TITLE QUE CONTEM VIRGULA LOGO TEREMOS QUE PENSAR COMO FAZER PARA PEGAR ELA POR COMPLETO SEM PARTIR
            getline(arquivo,line,',');
            livro.set_url(line);
            getline(arquivo,line,',');
            livro.set_weight(std::stof(line));
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
        //exit(1);
    }
    return 0;
}
