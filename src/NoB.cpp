#include "../include/NoB.h"

/// Construtor NoB
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

/// Destrutor NoB
NoB::~NoB()
{
    delete [] key;
    delete [] filhos;
}

/// Retorna n do NoB
int NoB::get_n() 
{
  return n; 
}

/// Retorna t do NoB
int NoB::get_t() 
{
  return t;
}

/// Retorna chava[i] do NoB
Book* NoB::get_chave_i(int i)
{
  return key[i];
}

/// Retorna filho[i] do NoB
NoB* NoB::get_filho(int i)
{
  return filhos[i];
}
    
/// Retorna se o NoB é folha ou não
bool NoB::get_folha()
{
  return folha; 
}

/// Atualiza o t do NoB
void NoB::set_t(int T)
{
  t = T;
}

/// Atualiza o n do NoB
void NoB::set_n(int N) 
{ 
  n = N;
}

/// Atualiza se o NoB é folha ou não
void NoB::set_folha(bool ehFolha)
{
  folha = ehFolha;
}

/// Atualiza chave[i] no NoB
void NoB::set_chave_i(int i, Book* novo)
{
  this->key[i] = novo;
}

/// Atualiza filho[i] no NoB
void NoB::set_filho(int i, NoB* novo)
{
  filhos[i] = novo;
}

/// Imprime
void NoB::imprime() 
{ 
    int i;
    for (i = 0; i < n; i++) 
    {
      if (folha == false) 
        filhos[i]->imprime();  
      cout << " " << key[i]->get_id() << "::" << n; 
    } 
    cout << endl;
    if (folha == false) 
      filhos[i]->imprime(); 
}

/// Auxiliar da inserção
void NoB::aux_insere(Book *info, int* num_comparacoes, int* num_copias)
{
  //cout << *num_comparacoes << " - " << *num_copias << endl;
  int i = this->n - 1;
  if(this->folha)
  {
    while(i >= 0 && this->key[i]->get_id() > info->get_id())
    {
      this->key[i+1] = this->key[i] ;
      i--;
      *num_comparacoes = *num_comparacoes + 1;
    } 
    this->key[i+1] = info;
    this->n = n+1;
  }
  else
  {
    while(i >= 0 && this->key[i]->get_id() > info->get_id())
    {
      *num_comparacoes = *num_comparacoes + 1;
      i--;
    }
    if(this->filhos[i+1]->get_n() == 2*t - 1)
    {
      overflow(i+1, this->filhos[i+1], num_copias);
      if(this->key[i+1]->get_id() < info->get_id())
        i++;
    }
    this->filhos[i+1]->aux_insere(info, num_comparacoes, num_copias);
  }
}

/// Função que executa a cisão do NoB
void NoB::overflow(int i, NoB *aux, int* num_copias)
{
  NoB *aux2 = new NoB(t);
  aux2->set_n(t - 1);
  int g = 0;
  while(g < (t - 1))
  {
    aux2->set_chave_i(g, aux->get_chave_i(g+t));
    g = g + 1;
    *num_copias = *num_copias + 1;
  }
   
  if(!aux->get_folha())
  {
    int j = 0;
    while(j < t)
    {
      aux2->set_filho(j, aux->get_filho(j + t));
      j++;
      *num_copias = *num_copias + 1;
    }
  }

  aux->set_n(t - 1);

  for(int j = n; j >= i+1; j--)
  {
    filhos[j + 1] = filhos[j];
    *num_copias = *num_copias + 1;
  }

  filhos[i + 1] = aux2;

  for (int j = n - 1; j >= i; j--) 
  {
    key[j+1] = key[j];
    *num_copias = *num_copias + 1;
  }
  
  key[i] = aux->get_chave_i(t-1);

  n = n + 1;
}

/// Acha posição em que a chave ficaria no NoB
int NoB::acha_posicao(Book* info) 
{ 
    int i = 0;
    while (i < n && key[i]->get_id() < info->get_id()) 
        i++;
    return i; 
} 

/// Funçao de remoção do NoB
void NoB::remove(Book* info)
{
  int i = acha_posicao(info);

  if(i < n && key[i]->get_id() == info->get_id())
  {
    if(folha)
    {
      remove_folha(i);
    }
    else
      remove_nao_folha(i);
  }
  else
  {
    if(this->folha == true)
    {
      return;
    }
    bool ehFilho;
    if(i == n)
      ehFilho = true;
    else
      ehFilho = false;
  
    if(filhos[i]->get_n() < t)
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
}

/// Remove se o NoB for folha
void NoB::remove_folha(int i)
{
  for(int j = i+1; j < n; j++)
  {
    key[j-1] = key[j];
  }
  n--;
}

/// Chega na folha pegando o filho a esquerda do NoB
Book* NoB::get_anterior(int i)
{
  NoB* aux = filhos[i];
  while(aux->get_folha() == false)
  {
    aux = aux->get_filho(aux->get_n());
  }
  return aux->get_chave_i(aux->get_n() - 1);
}

/// Chega na folha pegando o filho a direita do NoB
Book* NoB::get_proximo(int i)
{
  NoB* aux = filhos[i + 1];
  while(aux->get_folha() == false)
  {
    aux = aux->get_filho(0);
  }
  return aux->get_chave_i(0);
}

/// Remove se o NoB não for folha
void NoB::remove_nao_folha(int i)
{
  Book* k = key[i];
  if(filhos[i]->get_n() >= t)
  {
    Book* anterior = get_anterior(i);
    key[i] = anterior;
    filhos[i]->remove(anterior);
  } 
  else if(filhos[i+1]->get_n() >= t)
  {
    Book* proximo = get_proximo(i);
    key[i] = proximo;
    filhos[i+1]->remove(proximo);
  }
  else
  {
    juncao(i);
    filhos[i]->remove(k);
  }
  //n--;
}

/// Seleciona qual procedimento executar: redistribuição ou junção
void NoB::preenche(int i) 
{ 
    if (i != 0 && filhos[i-1]->get_n() >= t)
    {
      redistribuicao_anterior(i); 
    }
    else if (i != n && filhos[i+1]->get_n() >= t)
    { 
      redistribuicao_proximo(i); 
    }
    else
    { 
        if (i != n) 
            juncao(i);
        else
            juncao(i-1); 
    }
} 

/// Junção 
void NoB::juncao(int i)
{
  NoB* filho = filhos[i];
  NoB* irmao = filhos[i+1];
  filho->set_chave_i(t-1, key[i]);
  for(int j = 0; j < irmao->get_n(); j++)
  {
    filho->set_chave_i(t+j, irmao->get_chave_i(j));
  }
  if(!filho->get_folha())
  {
    for(int j = 0; j <= irmao->get_n(); j++)
    {
      filho->set_filho(j+t, irmao->get_filho(j));
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
  aux_n = filho->get_n() + irmao->get_n() + 1;
  filho->set_n(aux_n);
  n = n-1;
}

/// Redistribui no NoB anterior
void NoB::redistribuicao_anterior(int i) 
{ 
    NoB *f = filhos[i]; 
    NoB *irmao = filhos[i-1];  
 
    for (int j = f->get_n()-1; j >= 0; j--) 
        f->set_chave_i(j+1, f->get_chave_i(j)); 
   
    if (f->get_folha() == false) 
    { 
      for(int j = f->get_n(); j >= 0; j--) 
        f->set_filho(i+1, f->get_filho(i)); 
    } 
    f->set_chave_i(0, key[i-1]); 

    if(f->get_folha() == false) 
        f->set_filho(0, irmao->get_filho(irmao->get_n())); 
  
    key[i-1] = irmao->get_chave_i(irmao->get_n()-1); 
  
    f->set_n(f->get_n() + 1); 
    irmao->set_n(irmao->get_n() - 1);
    //return; 
} 

/// Redistribui no NoB posterior
void NoB::redistribuicao_proximo(int i) 
{ 
  
    NoB *f = filhos[i]; 
    NoB *irmao = filhos[i+1]; 
  
    f->set_chave_i((f->get_n()), key[i]); 
  
    if (!(f->get_folha())) 
    {
        f->set_filho((f->get_n())+1, irmao->get_filho(0)); 
    } 
    
   
    key[i] = irmao->get_chave_i(0); 
  
    for (int j = 1; j < irmao->get_n(); j++) 
    {
        irmao->set_chave_i(j-1, irmao->get_chave_i(j)); 
    }
  
    if (!irmao->get_folha()) 
    { 
        for(int j = 1; j <= irmao->get_n(); j++) 
            irmao->set_filho(j-1, irmao->get_filho(j)); 
    } 
  
    f->set_n(f->get_n() + 1); 
    irmao->set_n(irmao->get_n() - 1); 
} 
  