// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Thesis interface
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef THESIS_H
#define THESIS_H

#include <string>
#include <iostream>
#include "lit_cat_utils.h"
#include "literature-element.h"
#include "authorlist.h"
using std::string;

class Thesis : public LiteratureElement
{
private:
  string supervisor;
  string university;
public:
  // Rule of 5
  // .. Default constructor
  Thesis();
  // .. Parameterised constructor
  Thesis(const string& _title, const AuthorList& _authors,
         const string& _supervisor, const string& _university);
  // .. Destructor
  ~Thesis(){if(lit_cat_consts::show_messages) std::cout<<"Calling Thesis destructor"<<std::endl;};
  // .. Copy constructor
  Thesis(const Thesis& thesis_to_copy);
  // .. Move constructor
  Thesis(Thesis&& thesis_to_move);
  // .. Copy assignment operator
  Thesis& operator=(const Thesis& thesis_to_copy);
  // .. Move assignment operator
  Thesis& operator=(Thesis&& thesis_to_move);

  // Getters/Setters
  string get_supervisor() const {return supervisor;}
  string get_university() const {return university;}

  // Print information
  void print_info();
};

#endif // THESIS_H