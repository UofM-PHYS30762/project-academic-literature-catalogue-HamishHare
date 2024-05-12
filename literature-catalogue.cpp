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
      
      if(input=="author" || input=="a") return AUTHOR;
      else if(input=="title" || input=="ti") return TITLE;
      else if(input=="type" || input=="ty") return TYPE;
      else
      {
        std::cout<<"Invalid input. Please enter 'author', 'title', or 'type' (or a/ti/ty): ";
        attempts++;
      }
    }
    
    std::cout<<"\nMaximum attempts reached. No field selected."<<std::endl;
    return NO_FIELD;
  }
  // Function to get an author name field from the user
  author_name_fields get_author_name_field_from_user()
  {
    string input;
    size_t attempts{0};
    const size_t max_attempts{5};
    
    std::cout<<"Choose a field from 'first', 'middle', 'last', or 'all' (or f/m/l/a): ";
    while(attempts<max_attempts)
    {
      std::cin>>input;
      lit_cat_utils::to_lowercase(input); // Convert the input to lowercase
      
      if(input=="first" || input=="f") return FIRST_NAME;
      else if(input=="middle" || input=="m") return MIDDLE_NAMES;
      else if(input=="last" || input=="l") return LAST_NAME;
      else if(input=="all" || input=="a") return ALL_NAMES;
      else
      {
        std::cout<<"Invalid input. Please enter 'first', 'middle', 'last', or 'all' (or f/m/l/a): ";
        attempts++;
      }
    }
    
    std::cout<<"\nMaximum attempts reached. No field selected."<<std::endl;
    return NO_NAME_FIELD;
  }
  // Function to get a query string from the user
  string get_query_from_user()
  {
    string query;
    size_t attempts{0};
    const size_t max_attempts{5};
    std::cout<<"Please enter a search query: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(attempts<max_attempts)
    {
      std::getline(std::cin, query);
      if(!query.empty())
      {
        std::cout<<"Is this the correct query?: '"<<query<<"'"<<std::endl;
        if(lit_cat_utils::get_yes_no_from_user())
        {
          lit_cat_utils::to_lowercase(query);
          return query;
        }
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout<<"Please re-enter a query: ";
      attempts++;
    }
    std::cout<<"\nMaximum attempts reached. Full search used."<<std::endl;
    return "";
  }
  // Function to get a literature type from the user
  literature_type get_literature_type_from_user()
  {
    string input;
    size_t attempts{0};
    const size_t max_attempts{5};
    
    std::cout<<"Choose a type from 'book', 'thesis', or 'journal' (or b/t/j): ";
    while(attempts<max_attempts)
    {
      std::cin>>input;
      lit_cat_utils::to_lowercase(input); // Convert the input to lowercase
      
      if(input=="book" || input=="b") return BOOK;
      else if(input=="thesis" || input=="t") return THESIS;
      else if(input=="journal" || input=="j") return JOURNAL;
      else
      {
        std::cout<<"Invalid input. Please enter 'book', 'thesis', or 'journal' (or b/t/j): ";
        attempts++;
      }
    }
    
    std::cout<<"\nMaximum attempts reached. No type selected."<<std::endl;
    return NONE;
  }
  // Function to get an ID number from the user
  // .. needs to be an int to allow negative numbers (-1),
  // .. but should be casted to size_t once -1 handled when used
  int get_id_from_user()
  {
    int new_value{0};
    size_t attempts{0};
    const size_t max_attempts{5};
    // Prompt for an input
    std::cout<<"Enter the ID number to remove (or -1 to exit): ";
    // Repeat until a valid number or -1 (to quit) is entered,
    // .. or max_attempts attempts are made
    while(attempts<max_attempts)
    {
      if(!(std::cin>>new_value)
         || (new_value!=-1 && new_value<0) // || (new_value!=-1 && !is_valid_id()))
         || std::cin.peek()!='\n')
      {
        std::cout<<"Please enter a valid positive ID (or -1 to exit): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else break; // Valid, exit the loop
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
// .. add an entry to the set given a complete object
void Catalogue::add_entry(const lit_elem_ptr& literature_element)
{
  catalogue.insert(literature_element);
  num_entries++;
  print_catalogue();
}
// .. add an entry after prompting
void Catalogue::add_entry()
{
  // Get the type of LiteratureElement to add
  literature_type type{catalogue_utils::get_literature_type_from_user()};
  // Exit if no valid type given
  if(type==NONE)
  {
    std::cout<<"No element added."<<std::endl;
    return;
  }
  // Call the relevant creation function otherwise
  if(type==BOOK)
  {
    Book book_to_add;
    if(book_to_add.create_book())
    {
      std::cout<<"Successfully added a Book."<<std::endl;
      add_entry(std::make_shared<Book>(book_to_add));
    }
    else return;
  }

}

// .. remove an entry at a given index
void Catalogue::remove_entry_at(const size_t id_to_remove)
{
  // Search for the given id
  auto entry_iter = std::find_if(catalogue.begin(), catalogue.end(),
                                 [&id_to_remove](const lit_elem_ptr& entry)
                                 {return entry->get_unique_id()==id_to_remove;});
  // Remove it if found, after prompting the user
  if(entry_iter==catalogue.end()) // not found
  {
    std::cout<<"Provided ID ("<<id_to_remove<<") not found in the catalogue."<<std::endl;
  }
  else // found
  {
    // confirm if user wants to remove found element
    std::cout<<"Are you sure you want to remove ("
             <<(*entry_iter)->get_type_string()<<") '"
             <<(*entry_iter)->get_title()<<"' with ID "
             <<(*entry_iter)->get_unique_id()<<"?"<<std::endl;
    if(lit_cat_utils::get_yes_no_from_user())
    {
      catalogue.erase(entry_iter); // remove it
      num_entries--; // update the number of entries
    }
    else std::cout<<"No entries removed."<<std::endl;
  }
}
// .. remove an entry after prompting
void Catalogue::remove_entry()
{
  // Ouput a summary of each entry in the catalogue
  print_summary();
  // Exit early if no elements
  if(num_entries==0)
  {
    std::cout<<"No elements to remove."<<std::endl;
    return;
  }
  // Get an element to remove:
  int chosen_id = catalogue_utils::get_id_from_user();
  if(chosen_id==-1)
  {
    std::cout<<"No entries removed."<<std::endl;
    return;
  }
  else
  {
    size_t id_to_remove{static_cast<size_t>(chosen_id)};
    remove_entry_at(id_to_remove);
  }

}

// Functionality
// .. let the user search the catalogue
void Catalogue::search()
{
  // Get the field to be searched
  search_field field{catalogue_utils::get_field_from_user()};
  // Call the relevant search function
  switch(field)
  {
    case AUTHOR:
      search_author();
      break;
    case TITLE:
      search_title();
      break;
    case TYPE:
      search_type();
      break;
    default:
      break;
  }
}
// .. search by author
void Catalogue::search_author()
{
  // End early if no entries
  if(num_entries==0)
  {
    std::cout<<"No entries to search."<<std::endl;
    return;
  }
  // Otherwise...
  // Get which name field the user wants to search
  std::cout<<"Which part of the author name would you like to search?"<<std::endl;
  const author_name_fields name_field{catalogue_utils::get_author_name_field_from_user()};
  if(name_field==NO_NAME_FIELD) return;
  // Get the search query from the user
  string query{catalogue_utils::get_query_from_user()};
  // Define a lambda function to filter entries
  auto filter = [&](const lit_elem_ptr& entry)
                {return entry->get_authors()->search_authors(name_field, query);};
                    
  // Output the results of the search
  print_catalogue(filter);
}
// .. search by title
void Catalogue::search_title()
{
  // End early if no entries
  if(num_entries==0)
  {
    std::cout<<"No entries to search."<<std::endl;
    return;
  }
  // Otherwise...
  // Get the search query from the user
  std::cout<<"Searching by title. ";
  string query{catalogue_utils::get_query_from_user()};
  // Define a lambda function to filter entries
  auto filter = [&](const lit_elem_ptr& entry)
                {
                  string title{entry->get_title()};
                  lit_cat_utils::to_lowercase(title);
                  return title.find(query) != string::npos;
                };
                    
  // Output the results of the search
  print_catalogue(filter);
}
// .. search by title
void Catalogue::search_type()
{
  // End early if no entries
  if(num_entries==0)
  {
    std::cout<<"No entries to search."<<std::endl;
    return;
  }
  // Otherwise...
  // Get the search query from the user
  std::cout<<"Searching by type. ";
  literature_type type_query{catalogue_utils::get_literature_type_from_user()};
  // Define a lambda function to filter entries
  auto filter = [&](const lit_elem_ptr& entry)
                {
                  if(type_query==NONE) return true;
                  else return entry->get_type()==type_query;
                };
                    
  // Output the results of the search
  print_catalogue(filter);
}

// Print Information
// .. private implementation: accepts a conditional filter
void Catalogue::print_catalogue(std::function<bool(const lit_elem_ptr&)> filter)
{ 
  size_t count{0};
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
  for(const auto& entry : catalogue)
  {
    // Only print the details of an entry if it meets the given condition
    if(filter(entry))
    {
      entry->print_info();
      std::cout<<"++---------------------------++"<<std::endl;
      count++;
    }
  }
  std::cout<<"   Showing "<<count<<"/"<<num_entries<<" entries"<<std::endl;
  std::cout<<"++---------------------------++"<<std::endl;
}

// .. public implementation: uses a conditional filter to print everything
void Catalogue::print_catalogue()
{
  print_catalogue([](const lit_elem_ptr& entry){return true;});
}

// .. print a brief summary of each entry
void Catalogue::print_summary()
{
  std::cout<<std::endl;
  std::cout<<"++===========================++"<<std::endl;
  std::cout<<"||     CATALOGUE SUMMARY     ||"<<std::endl;
  std::cout<<"++===========================++"<<std::endl;
  // End early if no entries in the catalogue
  if(num_entries==0)
  {
    std::cout<<"   Catalogue is empty"<<std::endl;
    std::cout<<"++---------------------------++"<<std::endl;
    return;
  }
  for(const auto& entry : catalogue)
  {
    std::cout<<"ID "<<entry->get_unique_id()<<": ("
             <<entry->get_type_string()<<") "<<entry->get_title()<<std::endl;
  }
  std::cout<<"++---------------------------++"<<std::endl;
}