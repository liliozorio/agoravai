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
        int get_codigo();
        int get_contador();

        void set_nome(string n);
        void set_codigo(int c);
        void set_contador(int cont);


    private:
        int contador;
        string nome;
        int codigo;
};

#endif // AUTHOR_H
