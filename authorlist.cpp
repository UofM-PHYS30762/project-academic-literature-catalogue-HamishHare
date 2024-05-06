// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// AuthorList implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <list>
#include <initializer_list>
#include "authors.h"
#include "authorlist.h"

// Rule of 5
// .. Default constructor
AuthorList::AuthorList() : authors{}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling default AuthorList constructor"<<std::endl;
}
// .. Parameterised constructors
AuthorList::AuthorList(const std::list<Author>& _authors) : authors{_authors}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterised AuthorList constructor"<<std::endl;
}
#include <initializer_list>

// .. Parameterized constructor with initializer list (arbitrary length)
AuthorList::AuthorList(std::initializer_list<Author> author_list)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterized AuthorList constructor with init. list"<<std::endl;
  
  // Add each author from the initializer list to authors
  for(const auto& author : author_list)
  {
    add_author(author);
  }
}
// .. Copy constructor
AuthorList::AuthorList(const AuthorList& authorlist_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling AuthorList copy constructor"<<std::endl;
  // Copy the data members
  authors = authorlist_to_copy.authors;
}
// .. Move constructor
AuthorList::AuthorList(AuthorList&& authorlist_to_move)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling AuthorList move constructor"<<std::endl;
  // Move the data members
  authors = std::move(authorlist_to_move.authors);
}
// .. Copy assignment operator
AuthorList& AuthorList::operator=(const AuthorList& authorlist_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling AuthorList copy assignment operator"<<std::endl;
  if(&authorlist_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  authors = authorlist_to_copy.authors;

  return *this;
}
// .. Move assignment operator
AuthorList& AuthorList::operator=(AuthorList&& authorlist_to_move)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling AuthorList move assignment operator"<<std::endl;
  if(&authorlist_to_move == this) return *this; // no self-assignment

  // Move the data members
  authors = std::move(authorlist_to_move.authors);
  
  return *this;
}

// Getters/Setters
void AuthorList::add_author(const Author& author)
{
  authors.push_back(author);
}

// Print Information
void AuthorList::print_authors() const
{
  for(auto author{authors.begin()}; author!=authors.end(); ++author)
  {
    author->print_name();
  }
}