#ifndef NOB_H
#define NOB_H
#include "Book.h"


class NoB
{
  public:
    NoB(int tamanho);
    int getN() {return n; };
    int getM() {return m; };
    bool getFolha(){return folha; };

    void setN(int filhos) { n = filhos;};
    void setFolha(bool ehFolha){folha = ehFolha;};
    Book getChaveI(int i)
    {
      return chaves[i];
    };

    NoB* getFilhos(int i)
    {
      return filhos[i];
    };
  private:
    int m;
    int n;
    Book chaves[m-1];
    NoB* filhos[m];
    bool folha;
}