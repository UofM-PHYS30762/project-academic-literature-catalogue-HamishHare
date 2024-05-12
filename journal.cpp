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
                 const float& _impact_factor, const int& _num_volumes,
                 const int& _num_contributors, const int& _num_papers,
                 const set<string>& _scope) :
                 LiteratureElement(JOURNAL, _title, _authors)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterised Journal constructor"<<std::endl;
  scope = _scope; // Validation?

  // set validated impact factor
  if(lit_cat_utils::is_valid_positive_num<float>(_impact_factor,
                                                 impact_caution_value,
                                                 impact_maximum_value,
                                                 "impact factor")) impact_factor = _impact_factor;
  else
  {
    float new_impact_factor{lit_cat_utils::prompt_for_valid_positive_num<float>(impact_caution_value,
                                                                                impact_maximum_value,
                                                                                "impact factor")};
    if(new_impact_factor==-1)
    {
      std::cout<<"Setting impact factor to zero."<<std::endl;
      impact_factor = 0;
    }
    else impact_factor = new_impact_factor;
  }
  // set validated num_volumes
  if(lit_cat_utils::is_valid_positive_num<int>(_num_volumes,
                                               volumes_caution_value,
                                               volumes_maximum_value,
                                               "number of volumes")) num_volumes = _num_volumes;
  else
  {
    int new_num_volumes{lit_cat_utils::prompt_for_valid_positive_num<int>(volumes_caution_value,
                                                                          volumes_maximum_value,
                                                                          "number of volumes")};
    if(new_num_volumes==-1)
    {
      std::cout<<"Setting number of volumes to zero."<<std::endl;
      num_volumes = 0;
    }
    else num_volumes = new_num_volumes;
  }
  // set validated num_contributors
  if(lit_cat_utils::is_valid_positive_num<int>(_num_contributors,
                                               contributors_caution_value,
                                               contributors_maximum_value,
                                               "number of contributors")) num_contributors = _num_contributors;
  else
  {
    int new_num_contributors{lit_cat_utils::prompt_for_valid_positive_num<int>(contributors_caution_value,
                                                                               contributors_maximum_value,
                                                                               "number of contributors")};
    if(new_num_contributors==-1)
    {
      std::cout<<"Setting number of contributors to zero."<<std::endl;
      num_contributors = 0;
    }
    else num_contributors = new_num_contributors;
  }
  // set validated num_papers
  if(lit_cat_utils::is_valid_positive_num<int>(_num_papers,
                                               papers_caution_value,
                                               papers_maximum_value,
                                               "number of papers")) num_papers = _num_papers;
  else
  {
    int new_num_papers{lit_cat_utils::prompt_for_valid_positive_num<int>(papers_caution_value,
                                                                         papers_maximum_value,
                                                                         "number of papers")};
    if(new_num_papers==-1)
    {
      std::cout<<"Setting number of papers to zero."<<std::endl;
      num_papers = 0;
    }
    else num_papers = new_num_papers;
  }
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

// Setters
void Journal::set_impact_factor(const float& _impact_factor)
{
  if(lit_cat_utils::is_valid_positive_num<float>(_impact_factor,
                                                 impact_caution_value,
                                                 impact_maximum_value,
                                                 "impact factor")) impact_factor = _impact_factor;
  else
  {
    float new_impact_factor{lit_cat_utils::prompt_for_valid_positive_num<float>(impact_caution_value,
                                                                                impact_maximum_value,
                                                                                "impact factor")};
    if(new_impact_factor!=-1) impact_factor = new_impact_factor;
  }
}
void Journal::set_num_volumes(const int& _num_volumes)
{
  if(lit_cat_utils::is_valid_positive_num<int>(_num_volumes,
                                               volumes_caution_value,
                                               volumes_maximum_value,
                                               "number of volumes")) num_volumes = _num_volumes;
  else
  {
    int new_num_volumes{lit_cat_utils::prompt_for_valid_positive_num<int>(volumes_caution_value,
                                                                          volumes_maximum_value,
                                                                          "number of volumes")};
    if(new_num_volumes!=-1) num_volumes = new_num_volumes;
  }
}
void Journal::set_num_contributors(const int& _num_contributors)
{
  if(lit_cat_utils::is_valid_positive_num<int>(_num_contributors,
                                               contributors_caution_value,
                                               contributors_maximum_value,
                                               "number of contributors")) num_contributors = _num_contributors;
  else
  {
    int new_num_contributors{lit_cat_utils::prompt_for_valid_positive_num<int>(contributors_caution_value,
                                                                               contributors_maximum_value,
                                                                               "number of contributors")};
    if(new_num_contributors!=-1) num_contributors = new_num_contributors;
  }
}
void Journal::set_num_papers(const int& _num_papers)
{
  if(lit_cat_utils::is_valid_positive_num<int>(_num_papers,
                                               papers_caution_value,
                                               papers_maximum_value,
                                               "number of papers")) num_papers = _num_papers;
  else
  {
    int new_num_papers{lit_cat_utils::prompt_for_valid_positive_num<int>(papers_caution_value,
                                                                         papers_maximum_value,
                                                                         "number of papers")};
    if(new_num_papers!=-1) num_papers = new_num_papers;
  }
}
void Journal::set_scope(const set<string>& _scope)
{
  scope = _scope; // Validation?
}

// const float& _impact_factor, const int& _num_volumes,
// const int& _num_contributors, const int& _num_papers,
// const set<string>& _scope

// User interface for editting Journal 
void Journal::edit()
{
  // Edit the impact_factor
  std::cout<<"Would you like to edit the impact factor?"<<std::endl;
  if(lit_cat_utils::get_yes_no_from_user())
  {
    float _impact_factor{lit_cat_utils::prompt_for_valid_positive_num<float>(impact_caution_value,
                                                                           impact_maximum_value,
                                                                           "impact factor")};
    if(_impact_factor==-1)
    {
      std::cout<<"Aborting impact factor edit."<<std::endl;
    }
    else impact_factor = _impact_factor;
  }
  // Edit the num volumes
  std::cout<<"Would you like to edit the number of volumes?"<<std::endl;
  if(lit_cat_utils::get_yes_no_from_user())
  {
    int _num_volumes{lit_cat_utils::prompt_for_valid_positive_num<int>(volumes_caution_value,
                                                                       volumes_maximum_value,
                                                                      "number of volumes")};
    if(_num_volumes==-1)
    {
      std::cout<<"Aborting number of volumes edit."<<std::endl;
    }
    else num_volumes = _num_volumes;
  }
  // Edit the num contributors
  std::cout<<"Would you like to edit the number of contributors?"<<std::endl;
  if(lit_cat_utils::get_yes_no_from_user())
  {
    int _num_contributors{lit_cat_utils::prompt_for_valid_positive_num<int>(contributors_caution_value,
                                                                            contributors_maximum_value,
                                                                            "number of contributors")};
    if(_num_contributors==-1)
    {
      std::cout<<"Aborting number of contributors edit."<<std::endl;
    }
    else num_contributors = _num_contributors;
  }
  // Edit the num papers
  std::cout<<"Would you like to edit the number of papers?"<<std::endl;
  if(lit_cat_utils::get_yes_no_from_user())
  {
    int _num_papers{lit_cat_utils::prompt_for_valid_positive_num<int>(papers_caution_value,
                                                                      papers_maximum_value,
                                                                      "number of papers")};
    if(_num_papers==-1)
    {
      std::cout<<"Aborting number of papers edit."<<std::endl;
    }
    else num_papers = _num_papers;
  }
  // Edit the scope
  std::cout<<"Would you like to edit the scope?"<<std::endl;
  if(lit_cat_utils::get_yes_no_from_user())
  {
    int num_areas{lit_cat_utils::prompt_for_valid_positive_num<int>(10, 40, "number of disciplines")};
    if(num_areas==-1 || num_areas==0)
    {
      std::cout<<"Aborting scope edit."<<std::endl;
    }
    // .. create discipline strings until num_areas reached
    for(int i{0}; i<num_areas; i++)
    {
      string area{lit_cat_utils::get_string_from_user("discipline")};
      if(area.empty())
      {
        std::cout<<"Aborting scope edit."<<std::endl;
      }
      else scope.insert(area);
    }
  }
}

// User interface for Journal creation
bool Journal::create_journal()
{
  std::cout<<"Enter the parameters for a Journal:"<<std::endl;
  // Set the title and authors using base class function
  if(!LiteratureElement::create_literature_element()) return false;
  // Set the impact_factor
  float _impact_factor{lit_cat_utils::prompt_for_valid_positive_num<float>(impact_caution_value,
                                                                           impact_maximum_value,
                                                                           "impact factor")};
  if(_impact_factor==-1)
  {
    std::cout<<"Impact factor incomplete, could not make Journal"<<std::endl;
    return false;
  }
  else impact_factor = _impact_factor;
  // Set the num_volumes
  int _num_volumes{lit_cat_utils::prompt_for_valid_positive_num<int>(volumes_caution_value,
                                                                       volumes_maximum_value,
                                                                      "number of volumes")};
  if(_num_volumes==-1)
  {
    std::cout<<"Number of volumes incomplete, could not make Journal"<<std::endl;
    return false;
  }
  else num_volumes = _num_volumes;
  // Set the num_contributors
  int _num_contributors{lit_cat_utils::prompt_for_valid_positive_num<int>(contributors_caution_value,
                                                                            contributors_maximum_value,
                                                                            "number of contributors")};
  if(_num_contributors==-1)
  {
    std::cout<<"Number of contributors incomplete, could not make Journal"<<std::endl;
    return false;
  }
  else num_contributors = _num_contributors;
  // Set the num_papers
  int _num_papers{lit_cat_utils::prompt_for_valid_positive_num<int>(papers_caution_value,
                                                                      papers_maximum_value,
                                                                      "number of papers")};
  if(_num_papers==-1)
  {
    std::cout<<"Number of papers incomplete, could not make Journal"<<std::endl;
    return false;
  }
  else num_papers = _num_papers;

  // Set the scope
  int num_areas{lit_cat_utils::prompt_for_valid_positive_num<int>(10, 40, "number of disciplines")};
  if(num_areas==-1 || num_areas==0)
  {
    std::cout<<"Scope creation incomplete, could not make Journal"<<std::endl;
    return false;
  }
  // .. create discipline strings until num_areas reached
  for(int i{0}; i<num_areas; i++)
  {
    string area{lit_cat_utils::get_string_from_user("discipline")};
    if(area.empty())
    {
      std::cout<<"Disciplines incomplete, could not make Journal"<<std::endl;
      return false;
    }
    else scope.insert(area);
  }
  return true;
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

// Saving
void Journal::save(std::ofstream& outfile)
{
  LiteratureElement::save(outfile);
  outfile<<"IMPACT\t"<<impact_factor<<"\n";
  outfile<<"VOLUMES\t"<<num_volumes<<"\n";
  outfile<<"CONTRIBUTORS\t"<<num_contributors<<"\n";
  outfile<<"PAPERS\t"<<num_papers<<"\n";
  for(auto area{scope.begin()}; area!=scope.end(); area++)
  {
    outfile<<"SCOPE\t"<<*area<<"\n";
  }
}

// Print Information
void Journal::print_info()
{
  LiteratureElement::print_info();
  std::cout<<"       SCOPE: ";
  print_scope();
  std::cout<<"      IMPACT: "<<std::fixed<<std::setprecision(1)
                             <<impact_factor<<std::endl;
  std::cout<<" NUM VOLUMES: "<<num_volumes<<std::endl;
  std::cout<<"CONTRIBUTORS: "<<num_contributors<<std::endl;
  std::cout<<"  NUM PAPERS: "<<num_papers<<std::endl;
}