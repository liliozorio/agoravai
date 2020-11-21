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
    
    void auxInsere(Book *info, NoB *aux3);
    void overflow(int i, NoB *aux, NoB *aux2);
    void imprime(); 
    void setN(int N);
    void setT(int T);
    void setFolha(bool ehFolha);
    void setChaveI(int i, Book* novo);
    void setFilho(int i, NoB *novo);
    
  private:
    int t;
    int n;
    Book **key;
    NoB **filhos;
    bool folha;
};

#endif // NOB_H