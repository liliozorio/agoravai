#include "NoB.h"

NoB::NoB(int tamanho)
{  
    m = tamanho;
    folha = true;
    for(i = 0; i < m; i++)
    {
      filhos[i] = nullptr;
    }
    n = 0;
}

NoB::~NoB()
{
    
}
