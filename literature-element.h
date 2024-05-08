// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Literature element interface
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef LIT_ELEMENT_H
#define LIT_ELEMENT_H

#include <set>
#include <string>
#include <iostream>
#include "lit_cat_utils.h"
#include "authorlist.h"
using std::set;
using std::string;

// An enumerator to relate types of literature to an
// identfying int (rather than having to e.g. use a
// string, which has more overhead.)
enum literature_type
{
  NONE = 0,
  BOOK = 1,
  THESIS = 2,
  JOURNAL = 3
};

// Abstract base class for a piece of literature
class LiteratureElement
{
private:
  string get_type_string() const; // Utility function
protected:
  static set<size_t> all_ids;
  const size_t unique_id;
  const literature_type type;
  string title;
  AuthorList authors;
public:
  // Rule of 5
  // .. Default constructor
  LiteratureElement();
  // .. Parameterised constructor
  LiteratureElement(const literature_type _type, const string& _title,
                    const AuthorList& _authors);
  // .. Destructor
  ~LiteratureElement();
  // .. Copy constructor
  LiteratureElement(const LiteratureElement& literature_to_copy);
  // .. Move constructor
  LiteratureElement(LiteratureElement&& literature_to_move);
  // .. Copy assignment operator
  LiteratureElement& operator=(const LiteratureElement& literature_to_copy);
  // .. Move assignment operator
  LiteratureElement& operator=(LiteratureElement&& literature_to_move);

  // Getters/Setters

  // Print Information
  void print_info();
};

#endif // LIT_ELEMENT_H