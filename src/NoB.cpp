#include "../include/NoB.h"


NoB::NoB(int tamanho)
{  
    folha = true;
    t = tamanho;
    filhos = new NoB* [tamanho*2];
    key = new Book* [(tamanho*2)-1];
    for(int i = 0; i < tamanho*2- 1; i++)
    {
      filhos[i] = nullptr;
      key[i] = nullptr;
    }
    filhos[tamanho] = nullptr;
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

int NoB::getT() 
{
  return t;
}

Book* NoB::getChaveI(int i)
{
  return key[i];
}

NoB* NoB::getFilho(int i)
{
  return filhos[i];
}
    
bool NoB::getFolha()
{
  return folha; 
}

void NoB::setT(int T)
{
  t = T;
}

void NoB::setN(int N) 
{ 
  n = N;
}

void NoB::setFolha(bool ehFolha)
{
  folha = ehFolha;
}
    
void NoB::setChaveI(int i, Book* novo)
{
  this->key[i] = novo;
}

void NoB::setFilho(int i, NoB* novo)
{
  filhos[i] = novo;
}

void NoB::imprime() 
{ 
  int i;
    for (i = 0; i < n; i++) 
    {
        if (folha == false) 
            filhos[i]->imprime(); 
        cout << " " << key[i]->get_id(); 
    } 
    cout << endl;
    if (folha == false) 
      filhos[i]->imprime(); 
}

void NoB::auxInsere(Book *info, NoB *aux3)
{
  int i = this->n - 1;
  if(this->folha)
  {
    cout << "!!" << endl;
    while(i >= 0 && this->key[i]->get_id() > info->get_id())
    {
      this->key[i+1] = this->key[i] ;
      i--;
    } 
    this->key[i+1] = info;
    this->n = n+1;
  }
  else
  {
    while(i >= 0 && this->key[i]->get_id() > info->get_id())
    {
      i--;
    }
    if(this->filhos[i+1]->getN() == 2*t - 1)
    {
      cout << "AUX INSERE DEU RUIM" << endl;
      overflow(i+1, this->filhos[i+1], aux3);
      if(this->key[i+1]->get_id() < info->get_id())
        i++;
    }
    this->filhos[i+1]->auxInsere(info, aux3);
  }
}

void NoB::overflow(int i, NoB *aux, NoB *aux2)
{
  cout << "aaaaaaaaaa" << endl;
  //NoB *aux2 = new NoB(t);
  aux2->setN(t - 1);
  cout<<"antes for1"<<endl;
  int g = 0;
   cout << t << endl; 
  while(g < (t - 1))
  {
    cout << endl << aux->getChaveI(1+t) <<endl;
    aux2->setChaveI(g, aux->getChaveI(g+t));
    g = g + 1;
  }
  cout<<"dps for1"<<endl;
   
  if(!aux->getFolha())
  {
    int j = 0;
    while(j < t)
    {
      aux2->setFilho(j, aux->getFilho(j + t));
      j++;
    }
  }

  aux->setN(t - 1);

  for(int j = n; j >= i+1; j--)
  {
    filhos[j + 1] = filhos[j];
  }

  filhos[i + 1] = aux2;

  for (int j = n - 1; j >= i; j--) 
  {
    key[j+1] = key[j];
  }
  cout << t << endl;
  cout << aux->getChaveI(this->t) << endl;
  key[i] = aux->getChaveI(t);

  /*aux->setN(1);
  aux->setFilho(0, aux2);
  aux->setFilho(1, c); */
  n = n + 1;
}