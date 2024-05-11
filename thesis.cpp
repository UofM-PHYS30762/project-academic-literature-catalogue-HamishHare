// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Thesis implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include "thesis.h"

// Rule of 5
// .. Default constructor
Thesis::Thesis() : LiteratureElement(THESIS, string("Default Thesis"), AuthorList()),
                   supervisor{"Default Supervisor"}, university{"Default University"}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling default Thesis constructor"<<std::endl;
}
// .. Parameterised constructor
Thesis::Thesis(const string& _title, const AuthorList& _authors,
               const string& _supervisor, const string& _university) :
               LiteratureElement(THESIS, _title, _authors)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterised Thesis constructor"<<std::endl;
  supervisor = _supervisor; // Validation?
  university = _university; // Validation?
}
// .. Copy constructor
Thesis::Thesis(const Thesis& thesis_to_copy) : LiteratureElement(thesis_to_copy),
                                               supervisor{thesis_to_copy.supervisor},
                                               university{thesis_to_copy.university}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Thesis copy constructor"<<std::endl;
}
// .. Move constructor
Thesis::Thesis(Thesis&& thesis_to_move) : LiteratureElement(std::move(thesis_to_move)),
                                          supervisor{std::move(thesis_to_move.supervisor)},
                                          university{std::move(thesis_to_move.university)}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Thesis move constructor"<<std::endl;
}
// .. Copy assignment operator
Thesis& Thesis::operator=(const Thesis& thesis_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Thesis copy assignment operator"<<std::endl;
  if(&thesis_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  // .. of the base class
  LiteratureElement::operator=(thesis_to_copy);
  // .. of the thesis only
  supervisor = thesis_to_copy.supervisor;
  university = thesis_to_copy.university;

  return *this;
}
// .. Move assignment operator
Thesis& Thesis::operator=(Thesis&& thesis_to_move)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Thesis move assignment operator"<<std::endl;
  if(&thesis_to_move == this) return *this; // no self-assignment

  // Move the data members
  // .. of the base class
  LiteratureElement::operator=(std::move(thesis_to_move));
  // .. of the thesis only
  supervisor = std::move(thesis_to_move.supervisor);
  university = std::move(thesis_to_move.university);
  
  return *this;
}

// Setters
void Thesis::set_supervisor(const string& _supervisor)
{
  supervisor = _supervisor; // Validation?
}
void Thesis::set_university(const string& _university)
{
  university = _university; // Validation?
}

// Print Information
void Thesis::print_info()
{
  LiteratureElement::print_info();
  std::cout<<"  SUPERVISOR: "<<supervisor<<std::endl;
  std::cout<<"  UNIVERSITY: "<<university<<std::endl;
}