// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Author implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iostream>
#include <string>
#include <cctype> // isalpha
#include <string_view> // efficient string viewing when no editting
#include <algorithm> // any_of/all_of, transform, etc.
#include "authors.h"
using std::string;

namespace author_utils
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

  // Check if a provided string is a valid name format 
  bool is_valid_name(const std::string_view& name)
  {
    constexpr size_t max_name_length{40};

    // Check if the length of the name is not too long
    if(name.length()>max_name_length)
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

  // Format names so that the first letter of any new word is capitalised
  void format_name(string& input_string)
  {
    if(!input_string.empty())
    {
      bool capitalise_next{true};
      for (char& c : input_string)
      {
        if(c == ' ') capitalise_next = true;
        else if(capitalise_next)
        {
          c = std::toupper(static_cast<unsigned char>(c));
          capitalise_next = false;
        }
        else c = std::tolower(static_cast<unsigned char>(c));
      }
    }
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
  if(author_utils::is_valid_name(_first_name)) first_name = _first_name;
  if(author_utils::is_valid_name(_middle_names)) middle_names = _middle_names;
  if(author_utils::is_valid_name(_last_name)) last_name = _last_name;
  author_utils::format_name(first_name);
  author_utils::format_name(middle_names);
  author_utils::format_name(last_name);
}
// .. Copy constructor
Author::Author(const Author& author_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Author copy constructor"<<std::endl;
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

// Setters
void Author::set_names(const string& _first_name, const string& _middle_names, const string& _last_name)
{
  if(author_utils::is_valid_name(_first_name)) first_name = _first_name;
  if(author_utils::is_valid_name(_middle_names)) middle_names = _middle_names;
  if(author_utils::is_valid_name(_last_name)) last_name = _last_name;
  author_utils::format_name(first_name);
  author_utils::format_name(middle_names);
  author_utils::format_name(last_name);
}
void Author::set_first_name(const string& _first_name)
{
  if(author_utils::is_valid_name(_first_name)) first_name = _first_name;
  author_utils::format_name(first_name);
}
void Author::set_middle_names(const string& _middle_names)
{
  if(author_utils::is_valid_name(_middle_names)) middle_names = _middle_names;
  author_utils::format_name(middle_names);
}
void Author::set_last_name(const string& _last_name)
{
  if(author_utils::is_valid_name(_last_name)) last_name = _last_name;
  author_utils::format_name(last_name);
}

// User interface for Author editting
void Author::edit()
{
  // Set first name
  std::cout<<"Would you like to edit the first name?"<<std::endl;
  if(lit_cat_utils::get_yes_no_from_user())
  {
    string _first_name{lit_cat_utils::get_string_from_user("first name")};
    if(_first_name.empty())
    {
      std::cout<<"Warning: first name empty."<<std::endl;
    }
    first_name = _first_name;
    author_utils::format_name(first_name);
  }
  // Set any middle names
  std::cout<<"Would you like to edit the middle names?"<<std::endl;
  if(lit_cat_utils::get_yes_no_from_user())
  {
    string _middle_names{lit_cat_utils::get_string_from_user("middle names")};
    middle_names = _middle_names;
    author_utils::format_name(middle_names);
  }
  // Set last name
  std::cout<<"Would you like to edit the last name?"<<std::endl;
  if(lit_cat_utils::get_yes_no_from_user())
  {
    string _last_name{lit_cat_utils::get_string_from_user("last name")};
    if(_last_name.empty())
    {
      std::cout<<"Warning: last name empty."<<std::endl;
    }
    last_name = _last_name;
    author_utils::format_name(last_name);
  }
}

// User interface for Author creation
void Author::create_author()
{
  // Set first name
  string _first_name{lit_cat_utils::get_string_from_user("first name")};
  if(_first_name.empty())
  {
    std::cout<<"Warning: first name empty."<<std::endl;
  }
  first_name = _first_name;
  author_utils::format_name(first_name);
  // Set any middle names
  string _middle_names{lit_cat_utils::get_string_from_user("middle names")};
  middle_names = _middle_names;
  author_utils::format_name(middle_names);
  // Set last name
  string _last_name{lit_cat_utils::get_string_from_user("last name")};
  if(_last_name.empty())
  {
    std::cout<<"Warning: last name empty."<<std::endl;
  }
  last_name = _last_name;
  author_utils::format_name(last_name);
}

// Print Information
void Author::print_name() const
{
  if(middle_names.empty()) std::cout<<first_name<<" "<<last_name;
  else std::cout<<first_name<<" "<<middle_names<<" "<<last_name;
}