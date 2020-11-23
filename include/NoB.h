#ifndef NOB_H_INCLUDED
#define NOB_H_INCLUDED
#include <vector>
#include "Book.h"

using namespace std;

class NoB
{
  public:
    NoB(){};
    NoB(int tamanho);
    ~NoB();
    int get_n();
    int get_t();
    bool get_folha();
    Book* get_chave_i(int i);
    NoB* get_filho(int i);
    
    void aux_insere(Book *info);
    void overflow(int i, NoB *aux);
    
    void imprime();
    void set_n(int N);
    void set_t(int T);
    void set_folha(bool ehFolha);
    void set_chave_i(int i, Book* novo);
    void set_filho(int i, NoB *novo);

    int acha_posicao(Book* info);
    Book* get_anterior(int i);
    Book* get_proximo(int i);
    void remove(Book* info);
    void remove_folha(int i);
    void remove_nao_folha(int i);
    void preenche(int i);
    void juncao(int i);
    void redistribuicao_anterior(int i);
    void redistribuicao_proximo(int i);
    
  private:
    int t;
    int n;
    Book **key;
    NoB **filhos;
    bool folha;
};

#endif // NOB_H