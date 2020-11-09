#include <iostream>
#include <time.h>
#include "../include/Hash.h"
#include <math.h>

using namespace std;

Hash::Hash(int tamanho)
{
    //ctor
    this->m = tamanho;
  }

Hash::~Hash()
{

}

int Hash::getTamanho()
{
   return this->m;
}

/*bool Hash::Cheia(int m)
{
  int cont = 0;
  for(int i = 0; i < m; i++)
  {
    if(tabela[i] != INFINITO)
    {
      cont++;
    }
  }
  if(cont == m) return true;
  return false;
}*/


int Hash::hashFunction(int m, int mm, int *i, int data, int tipoHash)
{
  switch (tipoHash)
  {
    case LINEAR:
      return SondagemLinear(data, m, i);
      break;
    case DUPLA:
      return SondagemDupla(data, m, mm, i);
      break;
  }
}

int Hash::SondagemLinear(int chave, int m, int* i)
{
  return (chave + *i) % m;
}

int Hash::auxSondagemDupla(int chave, int m)
{
  return chave % m;
}

int Hash::SondagemDupla(int chave, int m, int mm, int* i)
{
  int h1 = auxSondagemDupla(chave, m);
  int h2 = 1 + auxSondagemDupla(chave, mm);
  return (h1 + *i*h2) % m;
}

void Hash::create(int m, int mm, int n, int tipoHash, vector<Author> Data)
{
    Author* auxInsere;

    Author* aux = new Author();
    aux->set_nome("");
    aux->set_codigo(INFINITO);
    aux->set_contador(INFINITO);

    for(int i = 0; i < m; i++)
    {
      tabela.push_back(*aux);
    }

    for(int i = 0; i < n; i ++)
    {
      int cont = 0;
      for(int j = 0; j < m; j++)
      {
        int chave = this->hashFunction(m, mm, &cont, Data[i].get_codigo(), tipoHash);
        if(tabela[chave].get_nome() != "")
        {
            numColisoes++;
            cont++;
        }
        else
        {
          this->insere(chave, &Data[i]);
          break;
        }
      }
      //if(this->Cheia(m)) break;
    }
    cout << endl << "Colisões: " << numColisoes << endl;
    this->imprime();
    cout << endl;

}

void Hash::insere(int chave, Author* data)
{
    tabela[chave] = *data;
    //return tabela[chave];
}

Author* Hash::lookup(int indice, Author* data)
{
    for (int i = 0; i < m; i++)
    {
        if (tabela[i].get_nome() == data->get_nome())
            return &tabela[i];
    }
    return nullptr;
}

void Hash::destroy()
{
    //delete [] tabela;
}

void Hash::imprime()
{
  for(int i = 0; i < m; i++)
  {
    cout << tabela[i].get_nome() << " - ";
  }
  cout << endl;
}
