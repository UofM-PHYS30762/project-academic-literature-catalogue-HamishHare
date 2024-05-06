// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// AuthorList implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <list>
#include "authors.h"
#include "authorlist.h"

// Rule of 5
// .. Default constructor
AuthorList::AuthorList() : authors()
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling default AuthorList constructor"<<std::endl;
}
// .. (Parameterised constructor uses a template so must be in .h file)

// Getters/Setters
void AuthorList::add_author(Author& author)
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