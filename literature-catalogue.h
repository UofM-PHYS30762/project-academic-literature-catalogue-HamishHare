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

// Utilities
// .. define the data type used in the catalogue
typedef shared_ptr<LiteratureElement> lit_elem_ptr;
// .. an enumerator to relate search fields to an identfying int
enum search_field
{
  NO_FIELD = 0,
  AUTHOR = 1,
  TITLE = 2,
  TYPE = 3
};
// .. utility functions
namespace catalogue_utils
{
  // Function to get a field type from the user
  search_field get_field_from_user();
}

// Create the Catalogue class
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
  size_t size() const {return num_entries;}

  // Functionality
  void search();

  // Print Information
  void print_catalogue();
};

#endif // LIT_CATALOGUE_H