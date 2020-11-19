#ifndef ARVOREVP_H
#define ARVOREVP_H
#include "NoVP.h"
#include "Book.h"


class ArvoreVP
{
    public:
        ArvoreVP();
        ~ArvoreVP();
        NoVP* insercao(Book info, NoVP* p);
        NoVP* remocao(Book info, NoVP* p);
        NoVP* busca(Book info, NoVP* p);
        NoVP* rotacao_simples_direita(NoVP* p, NoVP* pai);
        NoVP* rotacao_simples_esquerda(NoVP* p, NoVP* pai);
        NoVP* rotacao_dupla_esquerda(NoVP* p, NoVP* pai);
        NoVP* rotacao_dupla_direita(NoVP* p, NoVP* pai);
        NoVP* ajusta(NoVP* p, NoVP* pai);
        NoVP* get_raiz();

    private:
        NoVP* raiz;

};

#endif // ARVOREVP_H
