#ifndef LIT_CAT_UTILS_H
#define LIT_CAT_UTILS_H

#include <iostream>
#include <limits> // for numeric_limits
#include <string>
#include <algorithm>
#include <string_view> // efficient string viewing when no editting
using std::string;
using std::string_view;

namespace lit_cat_consts
{
  const bool show_messages{false};
}

namespace lit_cat_utils
{
  // Function to convert strings to lowercase
  void to_lowercase(string& input_string);
  // Function to get a yes or no from the user
  bool get_yes_no_from_user();
  // Function to get a string from the user
  string get_string_from_user(const string_view& prompt);
  // Function to get a float from the user
  string get_float_from_user(const string_view& prompt);
  
  // TEMPLATE FUNCTIONS:
  // These must have their implementation in the header file.

  // Function to validate a positive number
  // .. the type must be able to hold negative numbers
  template <class T> bool is_valid_positive_num(const T& num_to_check,
                                                const T& caution_limit, // value above which to seek confirmation
                                                const T& max_limit, // maximum allowed value
                                                const string_view& prompt_field)
  {
    // Check whether num_to_check is positive
    if(num_to_check<0.0)
    {
      std::cerr<<"Error: "<<prompt_field<<" cannot be negative."
               <<" Given "<<prompt_field<<": "<<num_to_check<<std::endl;
      return false;
    }
    // Check whether num_to_check is below max_limit
    if(num_to_check>max_limit)
    {
      std::cerr<<"Error: "<<prompt_field<<" exceeds maximum allowed value."
               <<" Given "<<prompt_field<<": "<<num_to_check
               <<", Max allowed: "<<max_limit<<std::endl;
      return false;
    }
    // Check if the value is over caution_limit, prompting user to confirm
    if(num_to_check>caution_limit)
    {
      std::cout<<"You have entered a large "<<prompt_field<<" ("<<num_to_check
               <<"), is this correct?"<<std::endl;
      return get_yes_no_from_user();
    }
    return true;
  }
  
  // Function to prompt the user for a valid positive number
  // .. the type must be able to hold negative numbers
  template <class T> T prompt_for_valid_positive_num(const T& caution_limit, // value above which to seek confirmation
                                                     const T& max_limit, // maximum allowed value
                                                     const string_view& prompt_field)
  {
    T new_value{0};
    size_t attempts{0};
    const size_t max_attempts{5};
    // Prompt for an input
    std::cout<<"Enter a "<<prompt_field<<" (or -1 to exit): ";
    // Repeat until a valid number or -1 (to quit) is entered,
    // .. or max_attempts attempts are made
    while(attempts<max_attempts)
    {
      // if(!(std::cin>>new_value) || (new_value!=-1 && new_value<0) || std::cin.peek()!='\n')
      if(!(std::cin>>new_value)
         || (new_value!=-1 && !is_valid_positive_num<T>(new_value, caution_limit, max_limit, prompt_field))
         || std::cin.peek()!='\n')
      {
        std::cout<<"Please enter a valid positive "<<prompt_field
                <<" (or -1 to exit): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else break; // Valid number, exit the loop
      attempts++;
    }
    if(attempts==max_attempts)
    {
      std::cout<<"\nMaximum attempts reached."<<std::endl;
      new_value = -1;
    }
    return new_value;
  }
}

#endif // LIT_CAT_UTILS_H