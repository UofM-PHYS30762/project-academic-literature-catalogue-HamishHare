// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Author interface
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <iostream>
#include "lit_cat_utils.h"
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

  // Getters/Setters
  string get_first_name() const {return first_name;}
  string get_middle_names() const {return middle_names;}
  string get_last_name() const {return last_name;}

  void set_names(const string& _first_name, const string& _middle_names, const string& _last_name);
  void set_first_name(const string& _first_name);
  void set_middle_names(const string& _middle_names);
  void set_last_name(const string& _last_name);

  void edit(); // User interface for editting elements
  void create_author(); // User interface for setting elements

  // Print Information
  void print_name() const;
};

#endif // AUTHOR_H