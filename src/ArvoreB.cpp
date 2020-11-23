#include "ArvoreB.h"
#include "NoB.h"

ArvoreB::ArvoreB(int T)
{
    raiz = nullptr;
    this->t = T;
    
}

ArvoreB::~ArvoreB()
{
    /*NoB* aux = new NoB(t);
    aux = raiz;
    int i = 0;
    while(aux != nullptr)
    {
      if(!aux->get_folha())
        aux = aux->get_filho(i);
      else
        aux = remocao(aux->get_chave_i(0));
      i++;
    }*/
    remove(raiz);
}

void ArvoreB::remove(NoB* p)
{
  if(p->get_folha())
  {
    p->~NoB();
  }
  else
  {
    for(int i = 0; i <= p->get_n(); i++)
    {
      remove(p->get_filho(i));
    }
    p->set_folha(true);
  }
}

int ArvoreB::get_t()
{
  return t;
}

/// Atulaizar 
void ArvoreB::set_t(int T)
{
  this->t = t;
}

/// Retorna raiz  
NoB* ArvoreB::get_raiz()
{
  return raiz;
} 

/// Atualiza raiz 
void ArvoreB::set_raiz(NoB* raiz)
{
  this->raiz = raiz;
}

/// Imprime as chaves contidas na raiz da arvore
void ArvoreB::imprimir_raiz()
{
  cout << endl << "Imprimindo Raiz:" << endl;
  for(int i = 0; i < raiz->get_n(); i++)
  {
    cout << " " <<raiz->get_chave_i(i)->get_id();
  }
  cout << endl << endl;
}

/// Insere chave 
void ArvoreB::insercao(Book* info)
{
  if(raiz == nullptr)
  {
    NoB* p = new NoB(t);
    raiz = p;
    raiz->set_n(1);
    raiz->set_chave_i(0, info);
  }
  else
  {
    NoB *aux2 = new NoB(raiz->get_t());
    ///caso que arvore n vazia
    if(raiz->get_n() == ((t*2)-1)) ///caso que n eh cisao
    {
      cisao(info, raiz);
    }
    else
    {
      raiz->aux_insere(info);
    }
  }
}

/// Chama a cisão dentro do no
void ArvoreB::cisao(Book* info, NoB* d)
{
  NoB* aux = new NoB(t);
  //NoB* aux2 = new NoB(t);
  aux->set_folha(false);
  aux->set_filho(0, d);

  aux->overflow(0, d);
  
  int i = 0;

  if(aux->get_chave_i(0)->get_id() < info->get_id())
    i++; 
  aux->get_filho(i)->aux_insere(info);
  raiz = aux;
}

/// Remove chave
NoB* ArvoreB::remocao(Book *info)
{ 
    if (raiz == nullptr) 
    { 
        cout << "A arvore esta vazia" << endl; 
        return nullptr; 
    } 
 
    raiz->remove(info); 

    if (raiz->get_n() == 0) 
    { 
        NoB *aux = new NoB(t);
        aux = raiz; 
        if (raiz->get_folha()) 
            raiz = NULL; 
        else
            raiz = raiz->get_filho(0); 

        delete aux; 
    } 
    return raiz; 
} 

/// Busca 
NoB* ArvoreB::busca(Book *info, NoB *p)
{
  if(raiz == nullptr)
    return NULL;

  int i = 0;

  while(i < p->get_n() && p->get_chave_i(i)->get_id() < info->get_id())
  {
    i++;
  }

  if(p->get_chave_i(i)->get_id() == info->get_id())
  {
    return p;
  }

  if(p->get_folha())
  {
    return NULL;
  }

  return busca(info, p->get_filho(i));
  
}
