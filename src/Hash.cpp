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


int Hash::SondagemLinear(int chave, int* i)
{
  return (chave + *i) % this->m;
}

void Hash::create(Author* Data)
{
    Author* auxInsere;

    Author* aux = new Author();
    aux->set_nome("");
    aux->set_codigo(INFINITO);
    aux->set_contador(INFINITO);

    tabela.push_back(*aux);

    //cout << endl << "Colis�es: " << numColisoes << endl;
    //this->imprime();
    //cout << endl;

}

void Hash::insere(Author* data)
{
  int cont = 0;
  for(int j = 0; j < this->m; j++)
  {
    int chave = this->SondagemLinear(data->get_codigo(), &cont);
    cout << "CHAVE AQUI OH: " << chave << endl;
    
    if(tabela[chave].get_nome() != "")
    {
      cout<< "Nome:" << tabela[chave].get_nome() << endl << endl;
      cout << "ENTREI IF" << endl;
      numColisoes++;
      cont++;
    }
    else
    {
      cout<< "Nome:" << tabela[chave].get_nome() << endl << endl;
      cout << "ENTREI ELSE" << endl;
      tabela[chave] = *data;
      break;
    }

  }
  cout << "PASSOU AQUI " << endl;
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
