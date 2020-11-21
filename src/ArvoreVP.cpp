#include "../include/ArvoreVP.h"
#include "../include/NoVP.h"
#include "../include/Book.h"
#include <iostream>

using namespace std;

ArvoreVP::ArvoreVP()
{
    raiz = nullptr;
}

ArvoreVP::~ArvoreVP()
{
    NoVP* aux;
    while(raiz != nullptr)
    {
        aux = remocao(raiz->get_info(), raiz);
        raiz = aux;
    }
}

NoVP* ArvoreVP::get_raiz()
{
    return this->raiz;
}

NoVP* ArvoreVP::rotacao_simples_esquerda(NoVP* p, NoVP* pai)
{
    NoVP* filho_esq = p->get_esquerdo();
    p->set_esquerdo(pai);
    p->set_pai(pai->get_pai());
    pai->set_pai(p);
    if(pai == this->raiz)
    {
        this->raiz = p;
    }
    return filho_esq;
}

NoVP* ArvoreVP::rotacao_simples_direita(NoVP* p, NoVP* pai)
{
    NoVP* filho_dir = p->get_direito();
    p->set_direito(pai);
    p->set_pai(pai->get_pai());
    pai->set_pai(p);
    if(pai == this->raiz)
    {
        this->raiz = p;
    }
    return filho_dir;
}

NoVP* ArvoreVP::rotacao_dupla_direita(NoVP* p, NoVP* pai)
{
    NoVP* filho_esq = p->get_esquerdo();
    p->set_esquerdo(rotacao_simples_direita(filho_esq, p));
    return rotacao_simples_esquerda(p->get_pai(), pai);;
}

NoVP* ArvoreVP::rotacao_dupla_esquerda(NoVP* p, NoVP* pai)
{
    NoVP* filho_dir = p->get_direito();
    p->set_direito(rotacao_simples_esquerda(filho_dir, p));
    return rotacao_simples_direita(p->get_pai(), pai);
}

NoVP* ArvoreVP::ajusta(NoVP* p, NoVP* pai)
{
    NoVP* irmao = nullptr;
    NoVP* filho_dir = p->get_direito();
    NoVP* filho_esq = p->get_esquerdo();

    if(pai != nullptr)
    {
        if(pai->get_esquerdo() == p)
        {
            irmao = pai->get_direito();
        }
        else if(pai->get_direito() == p)
        {
            irmao = pai->get_esquerdo();
        }
    }

    if(pai == nullptr)
    {
        p->set_cor(0);
    }

    else if(irmao == nullptr)
    {
        if(p->get_direito() != nullptr && p->get_esquerdo() != nullptr)
        {
            if(pai->get_direito() == p && p->get_direito()->get_cor() == 1)
            {
                pai->set_cor(1);
                p->set_cor(0);
                p = rotacao_simples_esquerda(p, pai);
            }
            else if(pai->get_esquerdo() == p && p->get_esquerdo()->get_cor() == 1)
            {
                pai->set_cor(1);
                p->set_cor(0);
                p = rotacao_simples_direita(p, pai);
            }
            else if(pai->get_direito() == p && p->get_esquerdo()->get_cor() == 1)
            {
                p->get_esquerdo()->set_cor(0);
                pai->set_cor(1);
                p = rotacao_dupla_direita(p, pai);
            }
            else if(pai->get_esquerdo() == p && p->get_direito()->get_cor() == 1)
            {
                p->get_direito()->set_cor(0);
                pai->set_cor(1);
                p = rotacao_dupla_esquerda(p, pai);
            }
        }
        if(p->get_direito() != nullptr)
        {
            if(pai->get_direito() == p && p->get_direito()->get_cor() == 1)
            {
                pai->set_cor(1);
                p->set_cor(0);
                p = rotacao_simples_esquerda(p, pai);
            }
            else if(pai->get_esquerdo() == p && p->get_direito()->get_cor() == 1)
            {
                p->get_direito()->set_cor(0);
                pai->set_cor(1);
                p = rotacao_dupla_esquerda(p, pai);
            }
        }
        else if(p->get_esquerdo() != nullptr)
        {
            if(pai->get_esquerdo() == p && p->get_esquerdo()->get_cor() == 1)
            {
                pai->set_cor(1);
                p->set_cor(0);
                p = rotacao_simples_direita(p, pai);
            }
            else if(pai->get_direito() == p && p->get_esquerdo()->get_cor() == 1)
            {
                p->get_esquerdo()->set_cor(0);
                pai->set_cor(1);
                p = rotacao_dupla_direita(p, pai);
            }
        }

    }

    else if(irmao->get_cor() == 0)
    {
        if(p->get_direito() != nullptr && p->get_esquerdo() != nullptr)
        {
            if(pai->get_direito() == p && p->get_direito()->get_cor() == 1)
            {
                pai->set_cor(1);
                p->set_cor(0);
                p = rotacao_simples_esquerda(p, pai);
            }
            else if(pai->get_esquerdo() == p && p->get_esquerdo()->get_cor() == 1)
            { 
                pai->set_cor(1);
                p->set_cor(0);
                p = rotacao_simples_direita(p, pai);
            }
            else if(pai->get_direito() == p && p->get_esquerdo()->get_cor() == 1)
            {
                p->get_esquerdo()->set_cor(0);
                pai->set_cor(1);
                p = rotacao_dupla_esquerda(p, pai);
            }
            else if(pai->get_esquerdo() == p && p->get_direito()->get_cor() == 1)
            {
                p->get_direito()->set_cor(0);
                pai->set_cor(1);
                p = rotacao_dupla_direita(p, pai);
            }
        }
        else if(p->get_direito() != nullptr)
        {
            if(pai->get_direito() == p && p->get_direito()->get_cor() == 1)
            {
                pai->set_cor(1);
                p->set_cor(0);
                p = rotacao_simples_esquerda(p, pai);
            }
            else if(pai->get_esquerdo() == p && p->get_direito()->get_cor() == 1)
            {
                p->get_direito()->set_cor(0);
                pai->set_cor(1);
                p = rotacao_dupla_direita(p, pai);
            }
        }
        else if(p->get_esquerdo() != nullptr)
        {
            p->get_esquerdo()->set_cor(0);
            pai->set_cor(1);
            if(pai->get_esquerdo() == p && p->get_esquerdo()->get_cor() == 1)
            {
                pai->set_cor(1);
                p->set_cor(0);
                p = rotacao_simples_direita(p, pai);
            }
            else if(pai->get_direito() == p && p->get_esquerdo()->get_cor() == 1)
            {
                p = rotacao_dupla_esquerda(p, pai);
            }
        }
    }
    else if(p->get_direito() != nullptr)
    {
        if(p->get_direito()->get_cor() == 1 && irmao->get_cor() == 1)
        {
            pai->set_cor(1);
            p->set_cor(0);
            irmao->set_cor(0);
        }
    }
    else if(p->get_esquerdo() != nullptr)
    {
        if(p->get_esquerdo()->get_cor() == 1 && irmao->get_cor() == 1)
        {
            pai->set_cor(1);
            p->set_cor(0);
            irmao->set_cor(0);
        }
    }
    if(pai != nullptr)
    {
        if(pai->get_esquerdo() == irmao)
        {
            pai->set_esquerdo(irmao);
        }
        if(pai->get_direito() == irmao)
        {
            pai->set_direito(irmao);
        }
    }
    return p;
}

NoVP* ArvoreVP::insercao(Book info, NoVP* p)
{
    if(p == nullptr)
    {
        p = new NoVP(info);

        if(raiz == nullptr)
        {
            this->raiz = p;
            p->set_cor(0);
        }
    }
    else if(info.get_id() > p->get_info().get_id())
    {
        NoVP* pai = p->get_pai();
        p->set_direito(insercao(info, p->get_direito()));
        if(p->get_direito() != nullptr)
        {
            p->get_direito()->set_pai(p);
        }
        if(p->get_cor() == 1)
        {
            p = ajusta(p, p->get_pai());
        }
        if(p != nullptr)
        {
            while(p->get_pai() != pai)
            {
                p = p->get_pai();
            }
        }
    }
    else
    {
        NoVP* pai = p->get_pai();
        p->set_esquerdo(insercao(info, p->get_esquerdo()));
        if(p->get_esquerdo() != nullptr)
        {
            p->get_esquerdo()->set_pai(p);
        }
        if(p->get_cor() == 1)
        {
            p = ajusta(p, p->get_pai());
        }
        if(p != nullptr)
        {
            while(p->get_pai() != pai)
            {
                p = p->get_pai();
            }
        }

    }
    return p;
}

NoVP* ArvoreVP::remocao(Book info, NoVP* p)
{
    if(p == nullptr)
    {
        return p;
    }
    if(p->get_info().get_id() > info.get_id())
    {
        NoVP* pai = p->get_pai();
        p->set_esquerdo(remocao(info, p->get_esquerdo()));
        if(p->get_cor() == 1)
        {
            p = ajusta(p, p->get_pai());
        }
        if(p != nullptr)
        {
            while(p->get_pai() != pai)
            {
                p = p->get_pai();
            }
        }
    }
    else if(p->get_info().get_id() < info.get_id())
    {
        NoVP* pai = p->get_pai();
        p->set_direito(remocao(info, p->get_direito()));
        if(p->get_cor() == 1)
        {
            p = ajusta(p, p->get_pai());
        }
        if(p != nullptr)
        {
            while(p->get_pai() != pai)
            {
                p = p->get_pai();
            }
        }
    }
    else
    {
        if(p->get_esquerdo() == nullptr)
        {
            NoVP* temp = p->get_direito();
            delete p;
            return temp;
        }
        else if(p->get_direito() == nullptr)
        {
            NoVP* temp = p->get_esquerdo();
            delete p;
            return temp;
        }
        else
        {
            NoVP* temp = p->get_direito();
            while(temp->get_esquerdo() != nullptr)
            {
                temp = temp->get_esquerdo();
            }
            p->set_info(temp->get_info());
            p->set_direito(remocao(temp->get_info(), p->get_direito()));
        }
    }
    return p;
}

NoVP* ArvoreVP::busca(Book info, NoVP* p)
{
    if(p == nullptr)
    {
        return nullptr;
    }

    int dado = p->get_info().get_id();

    if(dado == info.get_id())
    {
        return p;
    }
    else if(dado > info.get_id())
    {
        return busca(info, p->get_esquerdo());
    }
    else if(dado < info.get_id())
    {
        return busca(info, p->get_direito());
    }
}
