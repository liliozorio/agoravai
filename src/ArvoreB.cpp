#include "ArvoreB.h"
#include "NoB.h"

ArvoreB::ArvoreB(int T)
{
    raiz = nullptr;
    this->t = T;
    
}

ArvoreB::~ArvoreB()
{
    NoB* aux = raiz;
    int i = 0;
    while(aux != nullptr)
    {
      
      if(!aux->getFolha())
        aux = aux->getFilho(i);
      else
        aux = remocao(aux->getChaveI(0));
      i++;
    }
}

void ArvoreB::imprimirRaiz()
{
  cout << endl << "Imprimindo Raiz:" << endl;
  for(int i = 0; i < raiz->getN(); i++)
  {
    cout << " " <<raiz->getChaveI(i)->get_id();
  }
  cout << endl << endl;
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
      raiz->auxInsere(info);
    }
  }
}

void ArvoreB::cisao(Book* info, NoB* d)
{
  NoB* aux = new NoB(t);
  //NoB* aux2 = new NoB(t);
  aux->setFolha(false);
  aux->setFilho(0, d);

  aux->overflow(0, d);
  
  int i = 0;

  if(aux->getChaveI(0)->get_id() < info->get_id())
    i++; 
  aux->getFilho(i)->auxInsere(info);
  raiz = aux;
}

NoB* ArvoreB::remocao(Book *info)
{ 
    if (raiz == nullptr) 
    { 
        cout << "A arvore esta vazia" << endl; 
        return nullptr; 
    } 
 
    raiz->remove(info); 

    if (raiz->getN() == 0) 
    { 
        NoB *aux = raiz; 
        if (raiz->getFolha()) 
            raiz = NULL; 
        else
            raiz = raiz->getFilho(0); 

        delete aux; 
    } 
    return raiz; 
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
