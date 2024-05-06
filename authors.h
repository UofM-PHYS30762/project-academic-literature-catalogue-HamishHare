// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// AuthorList + Author interfaces
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef AUTHORS_H
#define AUTHORS_H

#include <string>
#include <iostream>
#include "lit_cat_consts.cpp"
using std::string;

// A class to hold author names
// Note: only really suited to typical name formats
class Author
{
private:
  string first_name;
  string middle_names;
  string last_name;
public:
  // Rule of 5
  // .. Default constructor
  Author();
  // .. Parameterised constructor
  Author(const string& _first_name, const string& _middle_names, const string& _last_name);
  // .. Destructor
  ~Author(){if(lit_cat_consts::show_messages) std::cout<<"Calling Author destructor"<<std::endl;}
  // .. Copy constructor
  Author(const Author& author_to_copy);
  // .. Move constructor
  Author(Author&& author_to_move);
  // .. Copy assignment operator
  Author& operator=(const Author& author_to_copy);
  // .. Move assignment operator
  Author& operator=(Author&& author_to_move);

  // Print Information
  void print_name() const;
};


#endif // AUTHORS_H