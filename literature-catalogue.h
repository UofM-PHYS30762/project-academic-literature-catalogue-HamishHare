// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Catalogue interface
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef LIT_CATALOGUE_H
#define LIT_CATALOGUE_H

#include <set>
#include <memory> // smart pointers
#include <iostream>
#include <initializer_list>
#include "lit_cat_utils.h"
#include "literature-element.h"
using std::shared_ptr;

typedef shared_ptr<LiteratureElement> lit_elem_ptr;

class Catalogue
{
private:
  set<lit_elem_ptr> catalogue;
  size_t num_entries;
public:
  // Rule of 5
  // .. Default constructor
  Catalogue();
  // .. Parameterised constructor
  Catalogue(const set<lit_elem_ptr>& _catalogue); // using std::set
  Catalogue(std::initializer_list<lit_elem_ptr> lit_elem_ptr_list); // using arbitrary number of LiteratureElements
  // .. Destructor
  ~Catalogue(){if(lit_cat_consts::show_messages) std::cout<<"Calling Catalogue destructor"<<std::endl;};
  // .. Copy constructor
  Catalogue(const Catalogue& catalogue_to_copy);
  // .. Move constructor
  Catalogue(Catalogue&& catalogue_to_move);
  // .. Copy assignment operator
  Catalogue& operator=(const Catalogue& catalogue_to_copy);
  // .. Move assignment operator
  Catalogue& operator=(Catalogue&& catalogue_to_move);

  // Getters/Setters
  void add_entry(const lit_elem_ptr& literature_element);

  // Print Information
  void print_catalogue();
};

#endif // LIT_CATALOGUE_H