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
    int getN();
    int getT();
    bool getFolha();
    Book* getChaveI(int i);
    NoB* getFilho(int i);
    
    void auxInsere(Book *info);
    void overflow(int i, NoB *aux);
    
    void imprime();
    void setN(int N);
    void setT(int T);
    void setFolha(bool ehFolha);
    void setChaveI(int i, Book* novo);
    void setFilho(int i, NoB *novo);

    int achaPosicao(Book* info);
    Book* getAnterior(int i);
    Book* getProximo(int i);
    void remove(Book* info);
    void removeFolha(int i);
    void removeNaoFolha(int i);
    void preenche(int i);
    void juncao(int i);
    void redistribuicaoAnterior(int i);
    void redistribuicaoProximo(int i);
    
  private:
    int t;
    int n;
    Book **key;
    NoB **filhos;
    bool folha;
};

#endif // NOB_H