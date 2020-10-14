#include "Book.h"
#include <string>

Book::Book()
{
    //ctor
}

Book::~Book()
{
    //dtor

}

string Book::get_authors()
{
    return this->authors;
}

void Book::set_authours(string authours)
{
    this->authors = this->authors + ", " + authours;
}

int Book::get_bestsellers_rank()
{
    return this->bestsellers_rank;
}

void Book::set_bestseller_rank(int bestsellers_rank)
{
    this->bestsellers_rank = bestsellers_rank;
}

string Book::get_categories()
{
    return this->categories;
}

void Book::set_categories(string categories)
{
    this->categories = categories;
}

string Book::get_description()
{
    return this->description;
}

void Book::set_description(string description)
{
    this->description = description;
}


string Book::get_edition()
{
    return this->edition;
}

void Book::set_edition(string edition)
{
    this->edition = edition;
}

int Book::get_id()
{
    return this->id;
}

void Book::set_id(int id)
{
    this->id = id;
}

string Book::get_isbn10()
{
    return this->isbn10;
}

void Book::set_isbn10(string isbn10)
{
    this->isbn10 = isbn10;
}

string Book::get_isbn13()
{
    return this->isbn13;
}

void Book::set_isbn13(string isbn13)
{
    this->isbn13 = isbn13;
}

float Book::get_rating_avg()
{
    return this->rating_avg;
}

void Book::set_rating_avg(float rating_avg)
{
    this->rating_avg = rating_avg;
}

int Book::get_rating_count()
{
    return this->rating_count;
}

void Book::set_rating_count(int rating_count)
{
    this->rating_count = rating_count;
}

string Book::get_title()
{
    return this->title;
}

void Book::set_title(string title)
{
    this->title = title;
}

