#include "../include/Author.h"
#include <string>

/// Retorna nome
string Author::get_nome()
{
    return nome;
}

/// Retorna codigo
int Author::get_codigo()
{
    return codigo;
}

/// Retorna
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
void Author::cont_mais_um()
{
  contador++;
}
