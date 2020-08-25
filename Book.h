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
        string get_edition_statement();
        string get_for_ages();
        string get_format();
        string get_illustrations_note();
        string get_imprint();
        string get_index_date();
        string get_isbn10();
        string get_isbn13();
        string get_lang();
        string get_publication_date();
        string get_publication_place();
        string get_publisher();
        string get_title();
        string get_url();
        int get_bestsellers_rank();
        int get_id();
        int get_rating_count();
        float get_dimension_x();
        float get_dimension_y();
        float get_dimension_z();
        float get_rating_avg();
        float get_weight();

        void set_authours(string authours);
        void set_bestseller_rank(int bestsellers_rank);
        void set_categories(string categories);
        void set_description(string description);
        void set_dimention_x(float dimension_x);
        void set_dimention_y(float dimension_y);
        void set_dimention_z(float dimension_z);
        void set_edition(string edition);
        void set_edition_statement(string edition_statement);
        void set_for_ages(string for_ages);
        void set_format(string format);
        void set_id(int id);
        void set_illustrations_note(string illustrations_note);
        void set_imprint(string imprint);
        void set_index_date(string index_date);
        void set_isbn10(string isbn10);
        void set_isbn13(string isbn13);
        void set_lang(string lang);
        void set_publication_date(string publication_date);
        void set_publication_place(string publication_place);
        void set_publisher(string publisher);
        void set_rating_avg(float rating_avg);
        void set_rating_count(int rating_count);
        void set_title(string title);
        void set_url(string url);
        void set_weight(float weight);

    private:
        string authors;
        int bestsellers_rank;
        string categories;
        string description;
        float dimension_x;
        float dimension_y;
        float dimension_z;
        string edition;
        string edition_statement;
        string for_ages;
        string format;
        int id;
        string illustrations_note;
        string imprint;
        string index_date;
        string isbn10;
        string isbn13;
        string lang;
        string publication_date;
        string publication_place;
        string publisher;
        float rating_avg;
        int rating_count;
        string title;
        string url;
        float weight;

};

#endif // BOOK_H
