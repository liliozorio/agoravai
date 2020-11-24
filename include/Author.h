#ifndef AUTHOR_H
#define AUTHOR_H
#include <iostream>
#include <string>

using namespace std;

class Author
{
    public:
        Author();
        virtual ~Author();

        string get_nome();
        long int get_codigo();
        int get_contador();

        void set_nome(string n);
        void set_codigo(long int c);
        void set_contador(int cont);

        void cont_mais_um();
        
    private:
        int contador = 0;
        string nome;
        long int codigo;
};

#endif // AUTHOR_H
