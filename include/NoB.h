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
    int getM();
    bool getFolha();
    Book getChaveI(int i);
    NoB getFilhos(int i);

    void setN(int N);
    void setM(int M);
    void setFolha(bool ehFolha);
    void setChaveI(int i, Book novo);
    
  private:
    int m;
    int n;
    Book *key;
    NoB *filhos;
    bool folha;
};

#endif // NOB_H