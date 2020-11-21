#include "ArvoreB.h"
#include "NoB.h"

ArvoreB::ArvoreB(int T)
{
    raiz = nullptr;
    this->t = T;
    
}

ArvoreB::~ArvoreB()
{
    //dtor
}

void ArvoreB::insercao(Book* info)
{
  if(raiz == nullptr)
  {
    NoB* p = new NoB(t);
    raiz = p;
    raiz->setN(1);
    raiz->setChaveI(0, info);
  }
  else
  {
    NoB *aux2 = new NoB(raiz->getT());
    ///caso que arvore n vazia
    if(raiz->getN() == ((t*2)-1)) ///caso que n eh cisao
    {
      cisao(info, raiz);
    }
    else
    {
      raiz->auxInsere(info, aux2);
    }
  }
  
}

void ArvoreB::cisao(Book* info, NoB* d)
{
  NoB* aux = new NoB(t);
  NoB* aux2 = new NoB(t);
  aux->setFolha(false);
  aux->setFilho(0, raiz);

  cout<<"antes overflow"<<endl;
  aux->overflow(0, raiz, aux2);
  cout<<"dps overflow"<<endl;
  
  int i = 0;

  if(aux->getChaveI(0)->get_id() < info->get_id())
    i++;
  cout<<"antes insere"<<endl;  
  aux->getFilho(i)->auxInsere(info, aux2);
  raiz = aux;
  //cout << "!!" << endl;
}

NoB* ArvoreB::remocao(Book *info)
{

}

NoB* ArvoreB::busca(Book *info, NoB *p)
{
  if(raiz == nullptr)
    return NULL;

  int i = 0;

  while(i < p->getN() && p->getChaveI(i)->get_id() < info->get_id())
  {
    i++;
  }

  if(p->getChaveI(i)->get_id() == info->get_id())
  {
    return p;
    //return p->getChaveI(i);
  }

  if(p->getFolha())
  {
    return NULL;
  }

  return busca(info, p->getFilho(i));
  
}
