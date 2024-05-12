// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Book interface
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include "lit_cat_utils.h"
#include "literature-element.h"
#include "authorlist.h"
using std::string;

class Book : public LiteratureElement
{
private:
  string publisher;
  string subject;
  float price;
  const float price_caution_value{5000.0}; // Price over which to warn about
  const float price_maximum_value{50000.0}; // Maximum allowed price
public:
  // Rule of 5
  // .. Default constructor
  Book();
  // .. Parameterised constructor
  Book(const string& _title, const AuthorList& _authors,
       const string& _publisher, const string& _subject,
       const float& _price);
  // .. Destructor
  ~Book(){if(lit_cat_consts::show_messages) std::cout<<"Calling Book destructor"<<std::endl;};
  // .. Copy constructor
  Book(const Book& book_to_copy);
  // .. Move constructor
  Book(Book&& book_to_move);
  // .. Copy assignment operator
  Book& operator=(const Book& book_to_copy);
  // .. Move assignment operator
  Book& operator=(Book&& book_to_move);

  // Getters/Setters
  string get_publisher() const {return publisher;}
  string get_subject() const {return subject;}
  float get_price() const {return price;}

  void set_publisher(const string& _publisher);
  void set_subject(const string& _subject);
  void set_price(const float& _price);

  bool create_book(); // User interface for setting elements

  // Print information
  void print_info();
};

#endif // BOOK_H