#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <vector>
#include "Author.h"
using namespace std;

#define LINEAR 0
#define DUPLA 1
#define INFINITO -1

class Hash
{
    public:
        Hash(int tamanho);
        ~Hash();

        int get_tamanho();
        //bool Cheia(int m);

        void create(Author* Data);
        void insere(Author* data);
        Author* lookup(int indice);
        void destroy();

        int sondagem_linear(int chave, int *i);

        void imprime();

        int numColisoes = 0;

    private:
        int m;
        vector<Author> tabela;
};

#endif // HASH_H
