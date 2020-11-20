#include "../include/NoB.h"


NoB::NoB(int tamanho)
{  
    m = tamanho;
    folha = true;
    filhos = new NoB* [tamanho];
    key = new Book* [tamanho];
    for(int i = 0; i < m-1; i++)
    {
      filhos[i] = nullptr;
      key[i] = nullptr;
    }
    filhos[m] = nullptr;
    n = 0;
}

NoB::~NoB()
{
    delete [] key;
    delete [] filhos;
}

int NoB::getN() 
{
  return n; 
}

int NoB::getM() 
{
  return m;
}

Book* NoB::getChaveI(int i)
{
  return key[i];
}

NoB* NoB::getFilhos(int i)
{
  return filhos[i];
}
    
bool NoB::getFolha()
{
  return folha; 
}

void NoB::setM(int M)
{
  m = M;
}

void NoB::setN(int N) 
{ 
  n = N;
}

void NoB::setFolha(bool ehFolha)
{
  folha = ehFolha;
}
    
void NoB::setChaveI(int i, Book novo)
{
  key[i] = &novo;
}
