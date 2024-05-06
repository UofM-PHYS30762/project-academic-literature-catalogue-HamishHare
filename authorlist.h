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
  // .. Parameterised constructor
  template<typename... types> AuthorList(types&&... _authors);
  // .. Destructor
  ~AuthorList(){if(lit_cat_consts::show_messages) std::cout<<"Calling AuthorList destructor"<<std::endl;}
//   // .. Copy constructor
//   AuthorList(const AuthorList& authorlist_to_copy);
//   // .. Move constructor
//   AuthorList(AuthorList&& authorlist_to_move);
//   // .. Copy assignment operator
//   AuthorList& operator=(const AuthorList& authorlist_to_copy);
//   // .. Move assignment operator
//   AuthorList& operator=(AuthorList&& authorlist_to_move);

  // Getters/Setters
  void add_author(Author& author);

  // Print Information
  void print_authors() const;
};

// .. Parameterised constructor taking variable number of Author objects
//    (given I'm using a template I need the implementation here, not in
//     authorlist.cpp)
template<typename... types> AuthorList::AuthorList(types&&... _authors)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterised AuthorList constructor"<<std::endl;
  (add_author(std::forward<Author&>(std::forward<types>(_authors))), ...);
}

#endif // AUTHORLIST_H