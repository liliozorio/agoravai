#include "../include/NoVP.h"
#include "../include/Book.h"

NoVP::NoVP(Book info)
{
    this->info = info;
    this->cor = 1;
    this->direito = nullptr;
    this->esquerdo = nullptr;
    this->pai = nullptr;
}

NoVP::~NoVP()
{
    //dtor
}

void NoVP::set_info(Book info)
{
    this->info = info;
}

Book NoVP::get_info()
{
    return this->info;
}

void NoVP::set_cor(bool cor)
{
    this->cor = cor;
}

bool NoVP::get_cor()
{
    return cor;
}

void NoVP::set_direito(NoVP* direito)
{
    this->direito = direito;
}

NoVP* NoVP::get_direito()
{
    return this->direito;
}

void NoVP::set_esquerdo(NoVP* esquerdo)
{
    this->esquerdo = esquerdo;
}

NoVP* NoVP::get_esquerdo()
{
    return this->esquerdo;
}

void NoVP::set_pai(NoVP* pai)
{
    this->pai = pai;
}

NoVP* NoVP::get_pai()
{
    return this->pai;
}
