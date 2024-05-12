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
#include <limits> // numeric_limits
#include <functional> // to pass in functions as args
#include <string>
#include "lit_cat_utils.h"
#include "literature-element.h"
using std::shared_ptr;
using std::string;

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
  // Function to get an author name field from the user
  author_name_fields get_author_name_field_from_user();
  // Function to get a query string from the user
  string get_query_from_user();
  // Function to get a literature type from the user
  literature_type get_literature_type_from_user();
}

// Create the Catalogue class
class Catalogue
{
private:
  set<lit_elem_ptr> catalogue;
  size_t num_entries;
  void search_author();
  void search_title();
  void search_type();
  void print_catalogue(std::function<bool(const lit_elem_ptr&)> filter); // Private implementation
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
  void print_catalogue(); // Public interface, calls private one but prints everything
};

#endif // LIT_CATALOGUE_H