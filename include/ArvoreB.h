#ifndef ARVOREB_H
#define ARVOREB_H

#include "NoB.h"

class ArvoreB
{
    public:
        ArvoreB(int M);
        //ArvoreB(int M){this->m=M;};
        ~ArvoreB();
        void insercao(Book info);
        //void cisao(Book info);
        NoB* remocao(Book info);
        NoB* busca(Book info, NoB *p);
        NoB* cisao(NoB* c);
        void auxInsere(Book info, NoB* aux);
        void overflow(int i, NoB *aux);
        int getM(){return m;};
        void setM(int m){this->m = m;};
        NoB* getRaiz(){return raiz;}; 
        void setRaiz(NoB* raiz){this->raiz = raiz;};
    private:
      NoB* raiz;
      int m;
};

#endif // ARVOREB_H
