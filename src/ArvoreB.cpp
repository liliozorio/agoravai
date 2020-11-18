#include "ArvoreB.h"

ArvoreB::ArvoreB()
{
    //ctor
}

ArvoreB::~ArvoreB()
{
    //dtor
}

NoB* ArvoreB::insercao(Book info)
{
  BUSCA AQUI
  depois faz inserção
  
  if(raiz == nullptr)
  {
    NoB* p = new NoB(this->m);
    raiz = p;
  }
  else if()
  {
    
  }
}

NoB* ArvoreB::remocao(Book info)
{

}

NoB* ArvoreB::busca(Book info)
{
  NoB* p;
  p = raiz;
  
  if(raiz == nullptr)
    return NULL;

  int i = 0;

  while(i < p->getN() && p->getChavesI(i)->getId() < info->getId())
  {
    i++;
  }

  if(p->getChavesI(i)->getId() == info->geId())
  {
    return p->getChavesI(i)->getId();
  }

  if(p->getFolha())
  {
    return NULL;
  }

  return p->getFilho(i)->busca(info);
  
}