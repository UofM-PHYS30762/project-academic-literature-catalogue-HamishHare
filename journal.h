// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Journal interface
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>
#include <iostream>
#include <set>
#include "lit_cat_utils.h"
#include "literature-element.h"
#include "authorlist.h"
using std::string;
using std::set;

class Journal : public LiteratureElement
{
private:
  float impact_factor;
  size_t num_volumes;
  size_t num_contributors;
  size_t num_papers;
  set<string> scope;
  void print_scope() const; // Utility function
public:
  // Rule of 5
  // .. Default constructor
  Journal();
  // .. Parameterised constructor
  Journal(const string& _title, const AuthorList& _authors,
          const float& _impact_factor, const size_t& _num_volumes,
          const size_t& _num_contributors, const size_t& _num_papers,
          const set<string>& _scope);
  // .. Destructor
  ~Journal(){if(lit_cat_consts::show_messages) std::cout<<"Calling Journal destructor"<<std::endl;};
  // .. Copy constructor
  Journal(const Journal& journal_to_copy);
  // .. Move constructor
  Journal(Journal&& journal_to_move);
  // .. Copy assignment operator
  Journal& operator=(const Journal& journal_to_copy);
  // .. Move assignment operator
  Journal& operator=(Journal&& journal_to_move);

  // Getters/Setters
  float get_impact_factor() const {return impact_factor;}
  size_t get_num_volumes() const {return num_volumes;}
  set<string> get_scope() const {return scope;}
  size_t get_num_contributors() const {return num_contributors;}
  size_t get_num_papers() const {return num_papers;}

  // Print information
  void print_info();
};

#endif // JOURNAL_H