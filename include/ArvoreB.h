#ifndef ARVOREB_H
#define ARVOREB_H

#include "NoB.h"

class ArvoreB
{
    public:
        ArvoreB();
        ArvoreB(int M){this->m=M;};
        ~ArvoreB();
        NoB* insercao(Book info);
        NoB* remocao(Book info);
        NoB* busca(Book info);
        NoB* cisao(NoB* c);
        int get_m(){return m;};
        void set_m(int m){this->m = m;};
        NoB* get_raiz(){return raiz;}; 
        void set_raiz(NoB* raiz){this->raiz = raiz;};
    private:
      NoB* raiz;
      int m;
};

#endif // ARVOREB_H
