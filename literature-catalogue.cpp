// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Catalogue implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include "literature-catalogue.h"

// Utility functions
namespace catalogue_utils
{
  // Function to get a field type from the user
  search_field get_field_from_user()
  {
    string input;
    size_t attempts{0};
    const size_t max_attempts{5};
    
    std::cout<<"Choose a field from 'author', 'title', or 'type' (or a/ti/ty): ";
    while(attempts<max_attempts)
    {
      std::cin>>input;
      lit_cat_utils::to_lowercase(input);// Convert the input to lowercase
      
      if (input=="author" || input=="a") return AUTHOR;
      else if (input=="title" || input=="ti") return TITLE;
      else if (input=="type" || input=="ty") return TYPE;
      else
      {
        std::cout<<"Invalid input. Please enter 'author', 'title', or 'type' (or a/ti/ty): ";
        attempts++;
      }
    }
    
    std::cout<<"\nMaximum attempts reached. No field selected."<<std::endl;
    return NO_FIELD;
  }
}

// Rule of 5
// .. Default constructor
Catalogue::Catalogue() : catalogue{}, num_entries{0}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling default Catalogue constructor"<<std::endl;
}
// .. Parameterised constructors
// using std::set
Catalogue::Catalogue(const set<lit_elem_ptr>& _catalogue) : catalogue{_catalogue},
                                                            num_entries{_catalogue.size()}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterised Catalogue constructor"<<std::endl;
}
// using arbitrary number of LiteratureElement pointers
Catalogue::Catalogue(std::initializer_list<lit_elem_ptr> lit_elem_ptr_list) : num_entries{0}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterised Catalogue constructor with init. list"<<std::endl;
  // Add each piece of literature from the initializer list to catalogue
  for(const auto& lit_elem : lit_elem_ptr_list)
  {
    add_entry(lit_elem);
  }
}
// .. Copy constructor
Catalogue::Catalogue(const Catalogue& catalogue_to_copy) :
                        catalogue{catalogue_to_copy.catalogue},
                        num_entries{catalogue_to_copy.num_entries}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Catalogue copy constructor"<<std::endl;
}
// .. Move constructor
Catalogue::Catalogue(Catalogue&& catalogue_to_move) :
                                  catalogue{std::move(catalogue_to_move.catalogue)},
                                  num_entries{std::move(catalogue_to_move.num_entries)}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Catalogue move constructor"<<std::endl;
  // Clean up the previous catalogue
  catalogue_to_move.num_entries = 0;
}
// .. Copy assignment operator
Catalogue& Catalogue::operator=(const Catalogue& catalogue_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Catalogue copy assignment operator"<<std::endl;
  if(&catalogue_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  catalogue = catalogue_to_copy.catalogue;
  num_entries = catalogue_to_copy.num_entries;

  return *this;
}
// .. Move assignment operator
Catalogue& Catalogue::operator=(Catalogue&& catalogue_to_move)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Catalogue move assignment operator"<<std::endl;
  if(&catalogue_to_move == this) return *this; // no self-assignment

  // Move the data members
  catalogue = std::move(catalogue_to_move.catalogue);
  num_entries = std::move(catalogue_to_move.num_entries);
  // Clean up the previous catalogue
  catalogue_to_move.num_entries = 0;
  
  return *this;
}

// Getters/Setters
// .. add an author to the back of the list
void Catalogue::add_entry(const lit_elem_ptr& literature_element)
{
  catalogue.insert(literature_element);
  num_entries++;
}

// Functionality
// .. let the user search the catalogue
void Catalogue::search()
{
  // Get the field to be searched
  // Call the relevant search function
}

// Print Information
void Catalogue::print_catalogue()
{
  std::cout<<std::endl;
  std::cout<<"++===========================++"<<std::endl;
  std::cout<<"||     CATALOGUE DETAILS     ||"<<std::endl;
  std::cout<<"++===========================++"<<std::endl;
  // End early if no entries in the catalogue
  if(num_entries==0)
  {
    std::cout<<"   Catalogue is empty"<<std::endl;
    std::cout<<"++---------------------------++"<<std::endl;
    return;
  }
  // Print the information from each entry in the catalogue
  std::cout<<"   Showing "<<num_entries<<"/"<<num_entries<<" entries"<<std::endl;
  std::cout<<"++---------------------------++"<<std::endl;
  for(auto entry{catalogue.begin()}; entry!=catalogue.end(); ++entry)
  {
    // Print details of the entry
    (*entry)->print_info();
    std::cout<<"++---------------------------++"<<std::endl;
  }
}