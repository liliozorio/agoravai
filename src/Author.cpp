#include "../include/Author.h"
#include <string>

Author::Author()
{
  
}

Author::~Author()
{
    //dtor
}

string Author::get_nome()
{
    return nome;
}
int Author::get_codigo()
{
    return codigo;
}
int Author::get_contador()
{
    return contador;
}

void Author::set_nome(string n)
{
    nome = n;
}
void Author::set_codigo(int c)
{
    codigo = c;
}
void Author::set_contador(int cont)
{
    contador = cont;
}
void Author::contMaisUm()
{
  contador++;
}
