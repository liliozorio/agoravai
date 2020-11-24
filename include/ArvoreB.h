#ifndef ARVOREB_H
#define ARVOREB_H

#include "NoB.h"

class ArvoreB
{
    public:
        ArvoreB(int T);
        ~ArvoreB();

        int get_t();
        void set_t(int T);
        NoB* get_raiz(); 
        void set_raiz(NoB* raiz);

        void imprimir_raiz();
        void remove(NoB* p);
        void insercao(Book* info); 
        NoB* remocao(Book* info);
        NoB* busca(Book* info, NoB *p);
        void cisao(Book* info, NoB* c);
        
        int num_comparacoes = 0;
        int num_copias = 0;
    private:
      NoB* raiz;
      int t;
};

#endif // ARVOREB_H
