// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Literature element implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iostream>
#include "literature-element.h"

// Initialise the static set of ids
set<size_t> LiteratureElement::all_ids{};

// Rule of 5
// .. Default constructor
LiteratureElement::LiteratureElement() : unique_id{(all_ids.empty()) ? 0 : *all_ids.rbegin()+1},
                                         type{NONE}, title{"Default"}, authors{AuthorList()}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling default LiteratureElement constructor"<<std::endl;
  all_ids.insert(unique_id);
}
// .. Parameterised constructor
LiteratureElement::LiteratureElement(const literature_type _type,
                                     const string& _title,
                                     const AuthorList& _authors) :
                                     unique_id{(all_ids.empty()) ? 0 : *all_ids.rbegin()+1},
                                     type{_type}, title{_title},
                                     authors{_authors}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterised LiteratureElement constructor"<<std::endl;
  all_ids.insert(unique_id);
  // TODO: Validation (if needed)?
}
// .. Destructor
LiteratureElement::~LiteratureElement()
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling LiteratureElement destructor"<<std::endl;
  all_ids.erase(unique_id); // remove this id from the set of all ids
}
// .. Copy constructor
// The copy gets a new unique id, but copy the other data members
LiteratureElement::LiteratureElement(const LiteratureElement& literature_to_copy) :
                                     unique_id{(all_ids.empty()) ? 0 : *all_ids.rbegin()+1},
                                     type{literature_to_copy.type},
                                     title{literature_to_copy.title},
                                     authors{literature_to_copy.authors}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling LiteratureElement copy constructor"<<std::endl;
  // Add the new id to the set of all ids
  all_ids.insert(unique_id);
}
// .. Move constructor
// The new object steals the unique id of the previous
LiteratureElement::LiteratureElement(LiteratureElement&& literature_to_move) :
                                     unique_id{std::move(literature_to_move.unique_id)},
                                     type{std::move(literature_to_move.type)},
                                     title{std::move(literature_to_move.title)},
                                     authors{std::move(literature_to_move.authors)}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling LiteratureElement move constructor"<<std::endl;
}
// .. Copy assignment operator
LiteratureElement& LiteratureElement::operator=(const LiteratureElement& literature_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling LiteratureElement copy assignment operator"<<std::endl;
  if(&literature_to_copy == this) return *this; // no self-assignment
  
  // Stop early if the literature types do not match
  if(type!=literature_to_copy.type)
  {
    std::cerr<<"Literature types do not match. No data copied."<<std::endl;
    return *this;
  }
  // Otherwise, copy the remaining data members
  // This object's unique id can stay the same
  title = literature_to_copy.title;
  authors = literature_to_copy.authors;

  return *this;
}
// .. Move assignment 
LiteratureElement& LiteratureElement::operator=(LiteratureElement&& literature_to_move)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling LiteratureElement move assignment operator"<<std::endl;
  if(&literature_to_move == this) return *this; // no self-assignment

  // Stop early if the literature types do not match
  if(type!=literature_to_move.type)
  {
    std::cerr<<"Literature types do not match. No data moved."<<std::endl;
    return *this;
  }
  // The new object cannot steal the unique id of the old one, 
  // as its own id is a const data member, so just remove the
  // old id from the list of all ids
  all_ids.erase(literature_to_move.unique_id);
  // Move the other data members
  title = std::move(literature_to_move.title);
  authors = std::move(literature_to_move.authors);
  
  return *this;
}

// Getters/Setters
shared_ptr<const AuthorList> LiteratureElement::get_authors() const
{
  return std::make_shared<const AuthorList>(authors);
}

void LiteratureElement::set_title(const string& _title)
{
  // TODO: Validation (if needed)?
  title = _title;
}
void LiteratureElement::set_authors(const AuthorList& _authors) // using an AuthorList
{
  authors = _authors;
}
void LiteratureElement::set_authors(const std::list<Author>& _authors) // using std::list
{
  authors = AuthorList(_authors);
}
// void LiteratureElement::set_authors(std::initializer_list<Author> author_list) // using arbitrary number of Authors
// {
//   authors = AuthorList(author_list);
// }

 // User interface for LiteratureElement editting
void LiteratureElement::edit()
{
  // Ask if they want to edit the title
  std::cout<<"Would you like to edit the title?"<<std::endl;
  if(lit_cat_utils::get_yes_no_from_user())
  {
    // Set the title
    string _title{lit_cat_utils::get_string_from_user("title")};
    if(_title.empty())
    {
      std::cout<<"Title incomplete, editting aborted."<<std::endl;
      return;
    }
    else title = _title;
  }
  // Ask if they want to edit the authors
  std::cout<<"Would you like to edit the authors?"<<std::endl;
  if(lit_cat_utils::get_yes_no_from_user())
  {
    // Call author editting
    authors.edit();
  }
}

// User interface for LiteratureElement creation
bool LiteratureElement::create_literature_element()
{
  // Set the title
  string _title{lit_cat_utils::get_string_from_user("title")};
  if(_title.empty())
  {
    std::cout<<"Title incomplete, could not proceed."<<std::endl;
    return false;
  }
  else title = _title;
  // Set the authors
  int num_authors{lit_cat_utils::prompt_for_valid_positive_num<int>(10, 40, "number of authors")};
  if(num_authors==-1 || num_authors==0)
  {
    std::cout<<"Author list incomplete, could not proceed"<<std::endl;
    return false;
  }
  // .. create authors until num_authors reached
  for(int i{0}; i<num_authors; i++)
  {
    Author new_author;
    new_author.create_author();
    add_author(new_author);
  }
  return true;
}

// Operator <, for use when adding elements to the catalogue
bool LiteratureElement::operator<(const LiteratureElement& right_hand_element) const
{
  return unique_id < right_hand_element.unique_id;
}

// Saving
void LiteratureElement::save(std::ofstream& outfile)
{
  // Write the base class details
  // Write the type
  outfile<<"TYPE\t"<<type<<"\n";
  // .. title
  outfile<<"TITLE\t"<<title<<"\n";
  // .. authors
  for(size_t i{0}; i<authors.size(); i++)
  {
    Author author{*authors.get_author_at(i)};
    outfile<<"FIRSTNAME\t"<<author.get_first_name()<<"\n";
    outfile<<"MIDNAMES\t"<<author.get_middle_names()<<"\n";
    outfile<<"LASTNAME\t"<<author.get_last_name()<<"\n";
  }
}

// Function to get the string associated with a book type
string LiteratureElement::get_type_string() const
{
  string return_string;
  switch(type)
  {
    case NONE:
      return_string = "None";
      break;
    case BOOK:
      return_string = "Book";
      break;
    case THESIS:
      return_string = "Thesis";
      break;
    case JOURNAL:
      return_string = "Journal";
      break;
    default:
      return_string = "Error: Unknown type.";
      break;
  }
  return return_string;
}

// Print Information
void LiteratureElement::print_info()
{
  std::cout<<"   ID: "<<unique_id<<" --- TYPE: "
           <<get_type_string()<<std::endl;
  std::cout<<"++---------------------------++"<<std::endl;
  // std::cout<<"          ID: "<<unique_id<<std::endl;
  // std::cout<<"        TYPE: "<<get_type_string()<<std::endl;
  std::cout<<"       TITLE: "<<title<<std::endl;
  std::cout<<"   AUTHOR(S): ";
  authors.print_authors();
}