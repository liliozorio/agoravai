#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

using namespace std;

class Book
{
    public:
        Book();
        ~Book();
        string get_authors();
        string get_categories();
        string get_description();
        string get_edition();
        string get_isbn10();
        string get_isbn13();
        string get_title();
        int get_bestsellers_rank();
        long int get_id();
        int get_rating_count();
        float get_rating_avg();

        void set_authours(string authours);
        void set_bestseller_rank(int bestsellers_rank);
        void set_categories(string categories);
        void set_description(string description);
        void set_edition(string edition);
        void set_id(long int id);
        void set_isbn10(string isbn10);
        void set_isbn13(string isbn13);
        void set_rating_avg(float rating_avg);
        void set_rating_count(int rating_count);
        void set_title(string title);

    private:
        string authors;
        int bestsellers_rank;
        string categories;
        string description;
        string edition;
        long int id;
        string isbn10;
        string isbn13;
        float rating_avg;
        int rating_count;
        string title;

};

#endif // BOOK_H
