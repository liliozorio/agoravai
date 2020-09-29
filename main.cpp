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
    cout << leitura.get_title() << " - " << leitura.get_bestsellers_rank() << endl;
}

void leituraDataSet(Book* lista,int tam)
{
    ifstream arquivo;
    arquivo.open("testeEntrada.txt");
    int i=0;
    if(arquivo.is_open())
    {
        //cout<<"entrei aqui"<< endl;
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

bool compara_string(Book pivo, Book qualquer)
{
    int maiusculo_minisculo = 'a'-'A';
    int tamanho_pivo;
    int tamanho_qualquer;
    for(int i = 0; pivo.get_title()[i] != '\0' && qualquer.get_title()[i] != '\0'; i++) /// Compara letra por letra das strings artistas
    {
        if(pivo.get_title()[i] > 'Z' || qualquer.get_title()[i] > 'Z') /// Vê se pelo menos uma das letras comparadas é maiuscula
        {
            if(pivo.get_title()[i] > 'Z' && qualquer.get_title()[i] > 'Z') /// Se as duas letras das strings comparadas forem maiusculas
            {
                if(pivo.get_title()[i] > qualquer.get_title()[i])
                {
                    return false;
                }
                else if(qualquer.get_title()[i] > pivo.get_title()[i])
                {
                    return true;
                }
            }
            else if(pivo.get_title()[i] > 'Z') /// Se apenas a letra da string pivo for maiuscula
            {
                if(pivo.get_title()[i] > qualquer.get_title()[i] + maiusculo_minisculo)
                {
                    return false;
                }
                else if(qualquer.get_title()[i] + maiusculo_minisculo > pivo.get_title()[i])
                {
                    return true;
                }
            }
            else /// Se apenas a letra da string qualquer for maiuscula
            {
                if(pivo.get_title()[i] + maiusculo_minisculo > qualquer.get_title()[i])
                {
                    return false;
                }
                else if(qualquer.get_title()[i] > pivo.get_title()[i] + maiusculo_minisculo)
                {
                    return true;
                }
            }
        }
        else /// Se as letras comparadas forem as duas minusculas
        {
            if(pivo.get_title()[i] > qualquer.get_title()[i])
            {
                return false;
            }
            else if(qualquer.get_title()[i] > pivo.get_title()[i])
            {
                return true;
            }
        }
    }
    tamanho_pivo = string_size(pivo.get_title());
    tamanho_qualquer = string_size(qualquer.get_title());
    /// as linhas 77 a 84 comparam os tamanhos das strings pois o inicio delas é igual e uma já acabou, logo a mais comprida é colocada depois na ordem alfabetica
    if(tamanho_pivo < tamanho_qualquer)
    {
        return true;
    }
    else if(tamanho_pivo > tamanho_qualquer)
    {
        return false;
    }
    cout << "entrei aqui" << endl;
    return true;

}


///Função para escolher o pivo do metodo QuickSort
int escolhe_pivo(Book *livro, int id_1, int id_2, int id_3)
{
    int i;
    if (compara_string(livro[id_1], livro[id_3]))
    {
        if(compara_string(livro[id_1], livro[id_2]))
        {
            if(compara_string(livro[id_2], livro[id_3]))
            {
                return id_2;
            }
            else
            {
                return id_3;
            }
        }
        else
        {
            return id_1;
        }
    }
    else if(compara_string(livro[id_2], livro[id_1]))
    {
        if(compara_string(livro[id_3], livro[id_2]))
        {
            if(compara_string(livro[id_2], livro[id_3]))
            {
                return id_3;
            }
            else
            {
                return id_1;
            }
        }
    }
    else
    {
        return id_2;
    }
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
    while(true)
    {
        while(compara_string(livro[i],pivo))
        {
            i++;
        }
        while(compara_string (pivo, livro[j]))
        {
            j--;
        }
        if(i >= j)
        {
            break;
        }
        else
        {
            aux = livro[i];
            livro[i] = livro[j];
            livro[j] = aux;
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

int main()
{
    int tamanho=3;
    Book lista[tamanho];
    leituraDataSet(lista,tamanho);
    QuickSort(&lista[0], 0, 2);
    imprimir(lista[0]);
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
