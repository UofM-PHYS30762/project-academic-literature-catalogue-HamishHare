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
#include <memory> // for smart pointers
#include "lit_cat_utils.h"
#include "authors.h"
using std::shared_ptr;

class AuthorList
{
private:
  std::list<Author> authors;
  void print_authors_with_index() const; // Utility function
  bool is_valid_index(size_t index) const; // Utility function
  int get_index_from_user() const; // Utility function
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
  void remove_author_at(const size_t index_to_remove);
  void remove_author();
  shared_ptr<const Author> get_author_at(const size_t index_to_get) const;
  shared_ptr<const Author> get_author() const;

  // Print Information
  void print_authors() const;
};

#endif // AUTHORLIST_H