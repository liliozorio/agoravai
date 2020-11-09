#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <vector>
#include "Author.h"
using namespace std;

#define LINEAR 0
#define DUPLA 1
#define INFINITO -1
//#include "Multiplicacao.h"

class Hash
{
    public:
        Hash(int tamanho);
        ~Hash();
        int hashFunction(int m, int mm, int* i, int data, int tipoHash);
        int SondagemLinear(int chave, int *i);

        int getTamanho();
        bool Cheia(int m);

        void create(Author* Data);

        void insere(Author* data);
        Author* lookup(int indice, Author* data);
        void destroy();
        void imprime();
        int numColisoes = 0;

    private:
        int m;
        vector<Author> tabela;
};

#endif // HASH_H
