// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// AuthorList interface
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef AUTHORLIST_H
#define AUTHORLIST_H

#include <string>
#include <iostream>
#include <list>
#include <initializer_list>
#include <type_traits> // type-checking
#include "lit_cat_consts.cpp"
#include "authors.h"

class AuthorList
{
private:
  std::list<Author> authors;
public:
  // Rule of 5
  // .. Default constructor
  AuthorList();
  // .. Parameterised constructors
  AuthorList(const std::list<Author>& _authors); // using std::list
  AuthorList(std::initializer_list<Author> author_list); // using arbitrary number of Authors
  // .. Destructor
  ~AuthorList(){if(lit_cat_consts::show_messages) std::cout<<"Calling AuthorList destructor"<<std::endl;}
  // .. Copy constructor
  AuthorList(const AuthorList& authorlist_to_copy);
  // .. Move constructor
  AuthorList(AuthorList&& authorlist_to_move);
  // .. Copy assignment operator
  AuthorList& operator=(const AuthorList& authorlist_to_copy);
  // .. Move assignment operator
  AuthorList& operator=(AuthorList&& authorlist_to_move);

  // Getters/Setters
  void add_author(const Author& author);

  // Print Information
  void print_authors() const;
};

#endif // AUTHORLIST_H