#ifndef NOVP_H
#define NOVP_H
#include "Book.h"

class NoVP
{
    public:
        NoVP(Book info);
        ~NoVP();
        NoVP* get_esquerdo();
        void set_esquerdo(NoVP* esquerdo);
        NoVP* get_direito();
        void set_direito(NoVP* direito);
        NoVP* get_pai();
        void set_pai(NoVP* pai);
        Book get_info();
        void set_info(Book info);
        bool get_cor();
        void set_cor(bool cor);

    private:
        Book info;
        NoVP* esquerdo;
        NoVP* direito;
        NoVP* pai;
        bool cor; /// 1 vermelho, 0 preto
};

#endif // NOVP_H
