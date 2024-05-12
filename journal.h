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
  int num_volumes;
  int num_contributors;
  int num_papers;
  set<string> scope;

  const float impact_caution_value{200.0}; // impact_factor over which to warn about
  const float impact_maximum_value{1000.0}; // maximum allowed impact_factor
  const int volumes_caution_value{10}; // num_volumes over which to warn about
  const int volumes_maximum_value{100}; // maximum allowed num_volumes
  const int contributors_caution_value{1000}; // num_contributors over which to warn about
  const int contributors_maximum_value{10000}; // maximum allowed num_contributors
  const int papers_caution_value{200}; // num_papers over which to warn about
  const int papers_maximum_value{5000}; // maximum allowed num_papers

  void print_scope() const; // Utility function
public:
  // Rule of 5
  // .. Default constructor
  Journal();
  // .. Parameterised constructor
  Journal(const string& _title, const AuthorList& _authors,
          const float& _impact_factor, const int& _num_volumes,
          const int& _num_contributors, const int& _num_papers,
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
  int get_num_volumes() const {return num_volumes;}
  int get_num_contributors() const {return num_contributors;}
  int get_num_papers() const {return num_papers;}
  set<string> get_scope() const {return scope;}

  void set_impact_factor(const float& _impact_factor);
  void set_num_volumes(const int& _num_volumes);
  void set_num_contributors(const int& _num_contributors);
  void set_num_papers(const int& _num_papers);
  void set_scope(const set<string>& _scope);

  bool create_journal(); // User interface for setting elements

  // Print information
  void print_info();
};

#endif // JOURNAL_H