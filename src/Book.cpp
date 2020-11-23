#include "Book.h"
#include <string>

/// Construtor Book
Book::Book()
{

}

/// Destrutor Book 
Book::~Book()
{

}

/// Retorna authours
string Book::get_authors()
{
    return this->authors;
}

/// Atualiza authours
void Book::set_authours(string authours)
{
    this->authors = authours;
}

/// Retorna bestsellers_rank
int Book::get_bestsellers_rank()
{
    return this->bestsellers_rank;
}

/// Atualiza bestsellers_rank
void Book::set_bestseller_rank(int bestsellers_rank)
{
    this->bestsellers_rank = bestsellers_rank;
}

/// Retorna categories
string Book::get_categories()
{
    return this->categories;
}

/// Atualiza categories
void Book::set_categories(string categories)
{
    this->categories = categories;
}

/// Retorna description
string Book::get_description()
{
    return this->description;
}

/// Atualiza description
void Book::set_description(string description)
{
    this->description = description;
}

/// Retorna edition
string Book::get_edition()
{
    return this->edition;
}

/// Atualiza edition
void Book::set_edition(string edition)
{
    this->edition = edition;
}

/// Retorna id
long int Book::get_id()
{
    return this->id;
}

/// Atualiza id
void Book::set_id(long int id)
{
    this->id = id;
}

/// Retorna isbn10
string Book::get_isbn10()
{
    return this->isbn10;
}

/// Atualiza isbn10
void Book::set_isbn10(string isbn10)
{
    this->isbn10 = isbn10;
}

/// Retorna isbn13
string Book::get_isbn13()
{
    return this->isbn13;
}

/// Atualiza isbn13
void Book::set_isbn13(string isbn13)
{
    this->isbn13 = isbn13;
}

/// Retorna rating_avg
float Book::get_rating_avg()
{
    return this->rating_avg;
}

/// Atualiza rating_avg
void Book::set_rating_avg(float rating_avg)
{
    this->rating_avg = rating_avg;
}

/// Retorna rating_count
int Book::get_rating_count()
{
    return this->rating_count;
}

/// Atualiza rating_count
void Book::set_rating_count(int rating_count)
{
    this->rating_count = rating_count;
}

/// Retorna title
string Book::get_title()
{
    return this->title;
}

/// Atualiza title
void Book::set_title(string title)
{
    this->title = title;
}

