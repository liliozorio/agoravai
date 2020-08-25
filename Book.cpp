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
    int i=0;
    while(authours[i]!='\0')
    {
        i++;
    }
    if(i==0)
    {
        this->authors = authours;
    }
    else
    {
        this->authors = this->authors + ", " + authours;
    }
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
    int i=0;
    while(categories[i]!='\0')
    {
        i++;
    }
    if(i==0)
    {
        this->categories = categories;
    }
    else
    {
        this->categories = this->categories + ", " + categories;
    }
}

string Book::get_description()
{
    return this->description;
}

void Book::set_description(string description)
{
    this->description = description;
}

float Book::get_dimension_x()
{
    return this->dimension_x;
}

void Book::set_dimention_x(float dimension_x)
{
    this->dimension_x = dimension_x;
}

float Book::get_dimension_y()
{
    return this->dimension_y;
}

void Book::set_dimention_y(float dimension_y)
{
    this->dimension_y = dimension_y;
}

float Book::get_dimension_z()
{
    return this->dimension_z;
}

void Book::set_dimention_z(float dimension_z)
{
    this->dimension_z = dimension_z;
}

string Book::get_edition()
{
    return this->edition;
}

void Book::set_edition(string edition)
{
    this->edition = edition;
}

string Book::get_edition_statement()
{
    return this->edition_statement;
}

void Book::set_edition_statement(string edition_statement)
{
    this->edition_statement = edition_statement;
}

string Book::get_for_ages()
{
    return this->for_ages;
}

void Book::set_for_ages(string for_ages)
{
    this->for_ages = for_ages;
}

string Book::get_format()
{
    return this->format;
}

void Book::set_format(string format)
{
    this->format = format;
}

int Book::get_id()
{
    return this->id;
}

void Book::set_id(int id)
{
    this->id = id;
}

string Book::get_illustrations_note()
{
    return this->illustrations_note;
}

void Book::set_illustrations_note(string illustrations_note)
{
    this->illustrations_note = illustrations_note;
}

string Book::get_imprint()
{
    return this->imprint;
}

void Book::set_imprint(string imprint)
{
    this->imprint = imprint;
}

string Book::get_index_date()
{
    return this->index_date;
}

void Book::set_index_date(string index_date)
{
    this->index_date = index_date;
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

string Book::get_lang()
{
    return this->lang;
}

void Book::set_lang(string lang)
{
    this->lang = lang;
}

string Book::get_publication_date()
{
    return this->publication_date;
}

void Book::set_publication_date(string publication_date)
{
    this->publication_date = publication_date;
}

string Book::get_publication_place()
{
    return this->publication_place;
}

void Book::set_publication_place(string publication_place)
{
    this->publication_place = publication_place;
}

string Book::get_publisher()
{
    return this->publisher;
}

void Book::set_publisher(string publisher)
{
    this->publisher = publisher;
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

string Book::get_url()
{
    return this->url;
}

void Book::set_url(string url)
{
    this->url = url;
}

float Book::get_weight()
{
    return this->weight;
}

void Book::set_weight(float weight)
{
    this->weight = weight;
}
