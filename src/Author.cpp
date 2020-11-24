#include "../include/Author.h"
#include <string>

/// Construtor Author
Author::Author()
{

}

/// Destrutor Author
Author::~Author()
{

}

/// Retorna nome
string Author::get_nome()
{
    return nome;
}

/// Retorna codigo
long int Author::get_codigo()
{
    return codigo;
}

/// Retorna contador
int Author::get_contador()
{
    return contador;
}

/// Atualiza nome
void Author::set_nome(string n)
{
    nome = n;
}

/// Atualiza codigo
void Author::set_codigo(long int c)
{
    codigo = c;
}

/// Atualiza contador
void Author::set_contador(int cont)
{
    contador = cont;
}

/// Acrescenta 1 ao contador
void Author::cont_mais_um()
{
  contador++;
}
