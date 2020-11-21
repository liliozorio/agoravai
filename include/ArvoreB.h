#ifndef ARVOREB_H
#define ARVOREB_H

#include "NoB.h"

class ArvoreB
{
    public:
        ArvoreB(int T);
        //ArvoreB(int M){this->m=M;};
        ~ArvoreB();
        void insercao(Book *info);
        //void cisao(Book info);
        NoB* remocao(Book *info);
        NoB* busca(Book *info, NoB *p);
        void cisao(Book *info, NoB* c);
        int getT(){return t;};
        void setT(int T){this->t = t;};
        NoB* getRaiz(){return raiz;}; 
        void setRaiz(NoB* raiz){this->raiz = raiz;};
    private:
      NoB* raiz;
      int t;
};

#endif // ARVOREB_H
