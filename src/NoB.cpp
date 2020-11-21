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

void NoB::auxInsere(Book *info)
{
  int i = this->n - 1;
  if(this->folha)
  {
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
      overflow(i+1, this->filhos[i+1]);
      if(this->key[i+1]->get_id() < info->get_id())
        i++;
    }
    this->filhos[i+1]->auxInsere(info);
  }
}

void NoB::overflow(int i, NoB *aux)
{
  NoB *aux2 = new NoB(t);
  aux2->setN(t - 1);
  int g = 0;
  while(g < (t - 1))
  {
    aux2->setChaveI(g, aux->getChaveI(g+t));
    g = g + 1;
  }
   
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
  
  key[i] = aux->getChaveI(t-1);

  n = n + 1;
}
int NoB::achaPosicao(Book* info) 
{ 
    int i = 0; 
    cout << "Valor n: " << n << endl;
    while (i < n && key[i]->get_id() < info->get_id()) 
        i++;
    return i; 
} 

void NoB::remove(Book* info)
{
  cout << "entrei remove" << endl;
  int i = achaPosicao(info);
  cout << "Valor i: " << i << endl;
  if(i < n && key[i]->get_id() == info->get_id())
  {
    if(folha)
    {
      cout << "entrei sei lá qual" << endl;
      removeFolha(i);
    }
    else
      removeNaoFolha(i);
  }
  if(this->folha == true)
  {
    cout << info->get_id() << endl;
    cout << "entrei" << endl;
    return;
  }
  bool ehFilho;
  if(i == n)
    ehFilho = true;
  else
    ehFilho = false;
  
  if(filhos[i]->getN() < t)
  {
    preenche(i);
  }
  if(ehFilho && i > n)
  {
    filhos[i-1]->remove(info);
  }
  else
  {
    filhos[i]->remove(info);
  }
}

void NoB::removeFolha(int i)
{
  for(int j = i+1; j < n; j++)
  {
    key[j-1] = key[j];
  }
  n--;
}

Book* NoB::getAnterior(int i)
{
  NoB* aux = filhos[i];
  while(aux->getFolha() == false)
  {
    aux = aux->getFilho(aux->getN());
  }
  return aux->getChaveI(aux->getN() - 1);
}

Book* NoB::getProximo(int i)
{
  NoB* aux = filhos[i + 1];
  while(aux->getFolha() == false)
  {
    aux = aux->getFilho(0);
  }
  return aux->getChaveI(0);
}

void NoB::removeNaoFolha(int i)
{
  Book* k = key[i];
  if(filhos[i]->getN() >= t)
  {
    Book* anterior = getAnterior(i);
    key[i] = anterior;
    filhos[i]->remove(anterior);
  } 
  else if(filhos[i+1]->getN() >= t)
  {
    Book* proximo = getProximo(i);
    key[i] = proximo;
    filhos[i+1]->remove(proximo);
  }
  else
  {
    juncao(i);
    filhos[i]->remove(k);
  }
  n--;
}

void NoB::preenche(int i) 
{ 
    if (i != 0 && filhos[i-1]->getN() >= t)
    {
      redistribuicaoAnterior(i); 
    }
    else if (i != n && filhos[i+1]->getN() >= t)
    { 
      redistribuicaoProximo(i); 
    }
    else
    { 
        if (i != n) 
            juncao(i);
        else
            juncao(i-1); 
    }
} 

void NoB::juncao(int i)
{
  NoB* filho = filhos[i];
  NoB* irmao = filhos[i+1];
  filho->setChaveI(t-1, filho->getChaveI(t));
  for(int j = 0; j < irmao->getN(); j++)
  {
    filho->setChaveI(t+1, irmao->getChaveI(j));
  }
  if(!filho->getFolha())
  {
    for(int j = 0; j <= irmao->getN(); j++)
    {
      filho->setFilho(j+t, irmao->getFilho(j));
    }
  }
  for(int j = i+1; j < n; j++)
  {
    key[j-1] = key[j];
  }
  for(int j = i+2; j <= n; j++)
  {
    filho[j-1] = filho[j];
  }
  int aux_n;
  aux_n = filho->getN() + irmao->getN() + 1;
  filho->setN(aux_n);
  n = n-1;
  delete irmao;
}

void NoB::redistribuicaoAnterior(int i) 
{ 
    NoB *f = filhos[i]; 
    NoB *irmao = filhos[i-1]; 
 
    for (int j = f->getN()-1; j >= 0; j--) 
        f->setChaveI(j+1, f->getChaveI(j)); 
   
    if (f->getFolha() == false) 
    { 
      for(int j = f->getN(); j >= 0; j--) 
        f->setFilho(i+1, f->getFilho(i)); 
    } 
    f->setChaveI(0, key[i-1]); 

    if(f->getFolha() == false) 
        f->setFilho(0, irmao->getFilho(irmao->getN())); 
  
    key[i-1] = irmao->getChaveI(irmao->getN()-1); 
  
    f->setN(f->getN() + 1); 
    irmao->setN(irmao->getN() - 1); 
    //return; 
} 

void NoB::redistribuicaoProximo(int i) 
{ 
  
    NoB *f = new NoB(t);
    f = filhos[i]; 
    NoB *irmao = new NoB(t);
    irmao = filhos[i+1]; 
  
    f->setChaveI((f->getN()), key[i]); 
  
    if (!(f->getFolha())) 
    {
        f->setFilho((f->getN())+1, irmao->getFilho(0)); 
    } 
    
   
    key[i] = irmao->getChaveI(0); 
  
    for (int j = 1; j < irmao->getN(); j++) 
    {
        irmao->setChaveI(j-1, irmao->getChaveI(j)); 
    }
  
    if (!irmao->getFolha()) 
    { 
        for(int j = 1; j <= irmao->getN(); j++) 
            irmao->setFilho(j-1, irmao->getFilho(j)); 
    } 
  
    f->setN(f->getN() + 1); 
    irmao->setN(irmao->getN() - 1); 
  
    //return; 
} 
  