#include <iostream>

#define _GLIBCXX_USE_C99 1

#include <string>
#include <fstream>
#include <map>
#include <utility>
#include "Book.h"
#include "Book.cpp"

using namespace std;



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
    string line, trash;
    getline(*arquivo,trash,'"');
    getline(*arquivo,line,'"');
    getline(*arquivo,trash,',');
    getline(*arquivo,trash,'"');
    return line;
}

void leituraDataSet()
{
    Book *leituraDS;
    leituraDS = new Book;
    ifstream arquivo;
    arquivo.open("arquivos/dataset.csv");
    if(arquivo.is_open())
    {
        string word, trash, line;
        getline(arquivo,line);
        while(!arquivo.eof())
        {
            ///AUTOR
            getline(arquivo,line,',');
            getline(arquivo,trash,'"');
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
                leituraDS->set_authours(line);
                getline(arquivo,line,',');
                tamanho_line = string_size(line);
            }
            line[tamanho_line-1] = '\0';
            leituraDS->set_authours(line);
            ///RANK BESTSELLERS
            line = separar(&arquivo);
            leituraDS->set_bestseller_rank(std::stoi(line));
            ///CATEGORIAS
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
                leituraDS->set_categories(line);
                line = separar(&arquivo);
                tamanho_line = string_size(line);
            }
            /*///AUTOR
            getline(arquivo,line,',');
            getline(arquivo,trash,'"');
            leituraDS->set_authours(line);
            ///RANK BESTSELLERS
            line = separar(&arquivo);
            leituraDS->set_bestseller_rank(std::stof(line));
            ///CATEGORIAS
            line = separar(&arquivo);
            leituraDS->set_categories(line);*/
            ///DESCRIÇÃO
            line = separar(&arquivo);
            leituraDS->set_description(line);
            ///DIMENSÃO X
            line = separar(&arquivo);
            leituraDS->set_dimention_x(std::stof(line));
            ///DIMENSÃO Y
            line = separar(&arquivo);
            leituraDS->set_dimention_y(std::stof(line));
            ///DIMENSÃO Z
            line = separar(&arquivo);
            leituraDS->set_dimention_z(std::stof(line));
            ///EDIÇÃO
            line = separar(&arquivo);
            leituraDS->set_edition(line);
            ///EDITION STATEMENT
            line = separar(&arquivo);
            leituraDS->set_edition_statement(line);
            ///IDADE
            line = separar(&arquivo);
            leituraDS->set_for_ages(line);
            ///FORMATO
            line = separar(&arquivo);
            leituraDS->set_format(line);
            ///ID
            line = separar(&arquivo);
            leituraDS->set_id(std::stof(line));
            ///NOTAS
            line = separar(&arquivo);
            leituraDS->set_illustrations_note(line);
            ///IMPRESSÃO
            line = separar(&arquivo);
            leituraDS->set_imprint(line);
            ///INDEX DATE
            line = separar(&arquivo);
            leituraDS->set_index_date(line);
            ///ISBN-10
            line = separar(&arquivo);
            leituraDS->set_isbn10(line);
            ///ISBN-13
            line = separar(&arquivo);
            leituraDS->set_isbn13(line);
            ///LINGUAGEM
            line = separar(&arquivo);
            leituraDS->set_lang(line);
            ///DATA DE PUBLICAÇÃO
            line = separar(&arquivo);
            leituraDS->set_publication_date(line);
            ///LOCAL DE PUBLICAÇÃO
            line = separar(&arquivo);
            leituraDS->set_publication_place(line);
            ///RATING-AVG
            line = separar(&arquivo);
            leituraDS->set_rating_avg(std::stof(line));
            ///RATING-COUNT
            line = separar(&arquivo);
            leituraDS->set_rating_count(std::stof(line));
            ///TÍTULO
            line = separar(&arquivo);
            leituraDS->set_title(line);
            ///URL
            line = separar(&arquivo);
            leituraDS->set_url(line);
            ///PESO
            line = separar(&arquivo);
            leituraDS->set_weight(std::stof(line));
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
    }
    return 0;
}
