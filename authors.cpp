// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// AuthorList + Author implementations
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iostream>
#include <string>
#include <cctype> // isalpha
#include <string_view> // efficient string viewing when no editting
#include <algorithm> // any_of/all_of
#include "authors.h"
using std::string;

namespace author_validate
{
  // Check whether 'char_to_check' is consecutively repeated in 'name'
  bool is_repeated_char(const std::string_view& name, const char char_to_check)
  {
    bool previous_is_checked_char{false};
    return std::any_of(name.begin(), name.end(), [&](char c)
    {
      if(c == char_to_check)
      {
        if(previous_is_checked_char) return true; // two consecutive
        previous_is_checked_char = true;
      }
      else previous_is_checked_char = false;
      return false; // not repeated
    });
  }

  bool is_valid_name(const std::string_view& name)
  {
    constexpr size_t max_name_length = 40;

    // Check if the length of the name is not too long
    if(name.length() > max_name_length)
    {
      std::cerr<<"Error: name too long (>"<<max_name_length<<" characters). Given name: '"<<name<<"'"<<std::endl;
      exit(1);
    }
    // Check if all characters in the name are allowed
    if(!std::all_of(name.begin(), name.end(), [](char c)
      {
        return std::isalpha(static_cast<unsigned char>(c))
        || c == ' ' || c == '-';
      }))
    {
      std::cerr<<"Error: invalid character entered in given name ("<<name<<")."<<std::endl;
      exit(1);
    }
    // Check that there aren't multiple spaces or hyphens in a row
    if(is_repeated_char(name, ' ') || is_repeated_char(name, '-'))
    {
      std::cerr<<"Error: name cannot have consecutively repeated non-letter characters. Given name: '"<<name<<"'"<<std::endl;
      exit(1);
    }

    return true;
  }
}

// Rule of 5
// .. Default constructor
Author::Author()
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling default Author constructor"<<std::endl;
  first_name = "FirstName";
  middle_names = "";
  last_name = "Surname";
}
// .. Parameterised constructor
Author::Author(const string& _first_name, const string& _middle_names, const string& _last_name)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterised Author constructor"<<std::endl;
  if(author_validate::is_valid_name(_first_name)) first_name = _first_name;
  if(author_validate::is_valid_name(_middle_names)) middle_names = _middle_names;
  if(author_validate::is_valid_name(_last_name)) last_name = _last_name;
}
// .. Copy constructor
Author::Author(const Author& author_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout << "Calling Author copy constructor" << std::endl;
  // Copy the data members
  first_name = author_to_copy.first_name;
  middle_names = author_to_copy.middle_names;
  last_name = author_to_copy.last_name;
}
// .. Move constructor
Author::Author(Author&& author_to_move)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Author move constructor"<<std::endl;
  // Move the data members
  first_name = std::move(author_to_move.first_name);
  middle_names = std::move(author_to_move.middle_names);
  last_name = std::move(author_to_move.last_name);
}
// .. Copy assignment operator
Author& Author::operator=(const Author& author_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Author copy assignment operator"<<std::endl;
  if(&author_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  first_name = author_to_copy.first_name;
  middle_names = author_to_copy.middle_names;
  last_name = author_to_copy.last_name;

  return *this;
}
// .. Move assignment operator
Author& Author::operator=(Author&& author_to_move)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Author move assignment operator"<<std::endl;
  if(&author_to_move == this) return *this; // no self-assignment

  // Move the data members
  first_name = std::move(author_to_move.first_name);
  middle_names = std::move(author_to_move.middle_names);
  last_name = std::move(author_to_move.last_name);
  
  return *this;
}

// Print Information
void Author::print_name() const
{
  if(middle_names.empty()) std::cout<<first_name<<" "<<last_name<<std::endl;
  else std::cout<<first_name<<" "<<middle_names<<" "<<last_name<<std::endl;
}