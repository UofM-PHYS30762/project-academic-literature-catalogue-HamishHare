// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Journal implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare


#include <iomanip>
#include "journal.h"

// Rule of 5
// .. Default constructor
Journal::Journal() : LiteratureElement(JOURNAL, string("Default Journal"), AuthorList()),
                     impact_factor{0.0}, num_volumes{0}, scope{}, num_contributors{0},
                     num_papers{0}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling default Journal constructor"<<std::endl;
}
// .. Parameterised constructor
Journal::Journal(const string& _title, const AuthorList& _authors,
                 const float& _impact_factor, const size_t& _num_volumes,
                 const size_t& _num_contributors, const size_t& _num_papers,
                 const set<string>& _scope) :
                 LiteratureElement(JOURNAL, _title, _authors)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterised Journal constructor"<<std::endl;
  impact_factor = _impact_factor; // Validation?
  num_volumes = _num_volumes; // Validation?
  num_contributors = _num_contributors; // Validation?
  num_papers = _num_papers; // Validation?
  scope = _scope; // Validation?
}
// .. Copy constructor
Journal::Journal(const Journal& journal_to_copy) :
                    LiteratureElement(journal_to_copy),
                    impact_factor{journal_to_copy.impact_factor},
                    num_volumes{journal_to_copy.num_volumes},
                    num_contributors{journal_to_copy.num_contributors},
                    num_papers{journal_to_copy.num_papers},
                    scope{journal_to_copy.scope}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Journal copy constructor"<<std::endl;
}
// .. Move constructor
Journal::Journal(Journal&& journal_to_move) :
                    LiteratureElement(std::move(journal_to_move)),
                    impact_factor{std::move(journal_to_move.impact_factor)},
                    num_volumes{std::move(journal_to_move.num_volumes)},
                    num_contributors{std::move(journal_to_move.num_contributors)},
                    num_papers{std::move(journal_to_move.num_papers)},
                    scope{std::move(journal_to_move.scope)}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Journal move constructor"<<std::endl;
}
// .. Copy assignment operator
Journal& Journal::operator=(const Journal& journal_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Journal copy assignment operator"<<std::endl;
  if(&journal_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  // .. of the base class
  LiteratureElement::operator=(journal_to_copy);
  // .. of the journal only
  impact_factor = journal_to_copy.impact_factor;
  num_volumes = journal_to_copy.num_volumes;
  num_contributors = journal_to_copy.num_contributors;
  num_papers = journal_to_copy.num_papers;
  scope = journal_to_copy.scope;

  return *this;
}
// .. Move assignment operator
Journal& Journal::operator=(Journal&& journal_to_move)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Journal move assignment operator"<<std::endl;
  if(&journal_to_move == this) return *this; // no self-assignment

  // Move the data members
  // .. of the base class
  LiteratureElement::operator=(std::move(journal_to_move));
  // .. of the journal only
  impact_factor = std::move(journal_to_move.impact_factor);
  num_volumes = std::move(journal_to_move.num_volumes);
  num_contributors = std::move(journal_to_move.num_contributors);
  num_papers = std::move(journal_to_move.num_papers);
  scope = std::move(journal_to_move.scope);
  
  return *this;
}

// Function to print each element of the scope
void Journal::print_scope() const
{
  int count{0};
  for(auto field{scope.begin()}; field!=scope.end(); ++field)
  {
    // End early if more than 3 fields, with 'and more'
    count++;
    if(count>3)
    {
      std::cout<<"and more"<<std::endl;
      return;
    }
    // Print author name
    std::cout<<*field;
    // Place commas between all but last element
    if(std::next(field)!=scope.end()) std::cout<<", ";
  }
  std::cout<<std::endl;
}

// Print Information
void Journal::print_info()
{
  LiteratureElement::print_info();
  std::cout<<"IMPACT: "<<std::fixed<<std::setprecision(1)
                       <<impact_factor<<std::endl;
  std::cout<<"VOLUMES: "<<num_volumes<<std::endl;
  std::cout<<"SCOPE: ";
  print_scope();
  std::cout<<"CONTRIBUTORS: "<<num_contributors<<std::endl;
  std::cout<<"PAPERS: "<<num_papers<<std::endl;
  std::cout<<"======="<<std::endl;
}