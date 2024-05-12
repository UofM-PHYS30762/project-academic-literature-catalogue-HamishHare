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
#include <memory> // for smart pointers
#include <fstream> // for saving/loading from file
#include "lit_cat_utils.h"
#include "authorlist.h"
using std::set;
using std::string;
using std::shared_ptr;

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
  size_t get_unique_id() const {return unique_id;}
  literature_type get_type() const {return type;}
  string get_type_string() const; // Utility function
  string get_title() const {return title;}
  shared_ptr<const AuthorList> get_authors() const;

  void set_title(const string& _title);
  void set_authors(const AuthorList& _authors); // using an AuthorList
  void set_authors(const std::list<Author>& _authors); // using std::list
  // void set_authors(std::initializer_list<Author> author_list); // using arbitrary number of Authors
  void add_author(const Author& author){authors.add_author(author);}
  void remove_author(){authors.remove_author();}

  bool create_literature_element(); // User interface for setting elements

  // Operator <, for use when adding elements to the catalogue
  bool operator<(const LiteratureElement& right_hand_element) const;

  // Saving
  virtual void save(std::ofstream& outfile) = 0;

  // Print Information
  virtual void print_info() = 0;
};

#endif // LIT_ELEMENT_H