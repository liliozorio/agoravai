#include "../include/NoVP.h"
#include "../include/Book.h"

/// Construtor NoVP
NoVP::NoVP(Book info)
{
    this->info = info;
    this->cor = 1;
    this->direito = nullptr;
    this->esquerdo = nullptr;
    this->pai = nullptr;
}

/// Atualiza a informação do NoVP
void NoVP::set_info(Book info)
{
    this->info = info;
}

/// Retorna a informação do NoVP 
Book NoVP::get_info()
{
    return this->info;
}

/// Atualiza cor do NoVP
void NoVP::set_cor(bool cor)
{
    this->cor = cor;
}

/// Retorna cor do NoVP
bool NoVP::get_cor()
{
    return cor;
}

/// Atualiza filho a direita de NoVP
void NoVP::set_direito(NoVP* direito)
{
    this->direito = direito;
}

/// Retorna filho a direita de NoVP
NoVP* NoVP::get_direito()
{
    return this->direito;
}

/// Atualiza filho a esquerda de NoVP
void NoVP::set_esquerdo(NoVP* esquerdo)
{
    this->esquerdo = esquerdo;
}

/// Retorna filho a esquerda de NoVP
NoVP* NoVP::get_esquerdo()
{
    return this->esquerdo;
}

/// Atualiza pai de NoVP
void NoVP::set_pai(NoVP* pai)
{
    this->pai = pai;
}

/// Retorna pai de NoVP
NoVP* NoVP::get_pai()
{
    return this->pai;
}
