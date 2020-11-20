#include "ArvoreB.h"
#include "NoB.h"

ArvoreB::ArvoreB(int M)
{
    raiz = nullptr;
    this->m = M;
}

ArvoreB::~ArvoreB()
{
    //dtor
}

void ArvoreB::insercao(Book info)
{
  if(raiz == nullptr)
  {
    NoB* p = new NoB(this->m);
    raiz = p;
    raiz->setN(1);
    raiz->setChaveI(0, info);
  }
  
  else
  {
    ///caso que arvore n vazia
    NoB aux = *busca(info, this->raiz);
    if(aux.getN() < (m-1)) ///caso que n eh cisao
    {
      cisao(&aux);
    }
    else
    {
      auxInsere(info, &aux);
    }
  }
}

void ArvoreB::auxInsere(Book info, NoB* aux)
{
  int i = aux->getM() - 1;
  if(aux->getFolha())
  {
    while(i >= 0 && aux->getChaveI(i)->get_id() > info.get_id())
    {
      aux->setChaveI(i+1, *aux->getChaveI(i));
      i--;
    }

    aux->setChaveI(i+1, info);
    aux->setM(aux->getM() + 1);
  }
  else
  {
    while(i >= 0 && aux->getChaveI(i)->get_id() > info.get_id())
    {
      i--;
    }
    if(aux->getFilhos(i+1)->getM() == aux->getM() - 1)
    {
      //overflow(i+1, aux->getFilhos(i+1));
      if(aux->getChaveI(i+1)->get_id() < info.get_id())
        i++;
    }
    auxInsere(info, aux->getFilhos(i+1));
  }
}

void ArvoreB::overflow(int i, NoB *aux)
{
  
}

NoB* ArvoreB::cisao(NoB* c)
{

}

NoB* ArvoreB::remocao(Book info)
{

}

NoB* ArvoreB::busca(Book info, NoB *p)
{
  
  if(raiz == nullptr)
    return NULL;

  int i = 0;

  while(i < p->getN() && p->getChaveI(i)->get_id() < info.get_id())
  {
    i++;
  }

  if(p->getChaveI(i)->get_id() == info.get_id())
  {
    return p;
    //return p->getChaveI(i);
  }

  if(p->getFolha())
  {
    return NULL;
  }

  return busca(info, p->getFilhos(i));
  
}