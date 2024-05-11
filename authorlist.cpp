// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// AuthorList implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <list>
#include <initializer_list>
#include <limits> // for numeric_limits
#include "authors.h"
#include "authorlist.h"

// Rule of 5
// .. Default constructor
AuthorList::AuthorList() : authors{}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling default AuthorList constructor"<<std::endl;
}
// .. Parameterised constructors
AuthorList::AuthorList(const std::list<Author>& _authors) : authors{_authors}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterised AuthorList constructor"<<std::endl;
}
#include <initializer_list>

// .. Parameterized constructor with initializer list (arbitrary length)
AuthorList::AuthorList(std::initializer_list<Author> author_list)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterized AuthorList constructor with init. list"<<std::endl;
  
  // Add each author from the initializer list to authors
  for(const auto& author : author_list)
  {
    add_author(author);
  }
}
// .. Copy constructor
AuthorList::AuthorList(const AuthorList& authorlist_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling AuthorList copy constructor"<<std::endl;
  // Copy the data members
  authors = authorlist_to_copy.authors;
}
// .. Move constructor
AuthorList::AuthorList(AuthorList&& authorlist_to_move)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling AuthorList move constructor"<<std::endl;
  // Move the data members
  authors = std::move(authorlist_to_move.authors);
}
// .. Copy assignment operator
AuthorList& AuthorList::operator=(const AuthorList& authorlist_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling AuthorList copy assignment operator"<<std::endl;
  if(&authorlist_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  authors = authorlist_to_copy.authors;

  return *this;
}
// .. Move assignment operator
AuthorList& AuthorList::operator=(AuthorList&& authorlist_to_move)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling AuthorList move assignment operator"<<std::endl;
  if(&authorlist_to_move == this) return *this; // no self-assignment

  // Move the data members
  authors = std::move(authorlist_to_move.authors);
  
  return *this;
}

// Utility function for printing authors with an index
void AuthorList::print_authors_with_index() const
{
  size_t index = 0;
  for (const auto& author : authors) {
    std::cout<<index++<<": ";
    author.print_name();
    std::cout<<std::endl;
  }
}
// Utility function for checking a given index is valid
bool AuthorList::is_valid_index(const size_t index) const
{
  if(index<0 || index>=authors.size())
  {
    std::cerr<<"Error: Index out of range."<<std::endl;
    return false;
  }
  else return true;
}
// Utility function for prompting a user for an index
// .. used for cases with more than one author
int AuthorList::get_index_from_user() const
{
  int index;
  size_t list_size{authors.size()};
  size_t attempts{0};
  const size_t max_attempts{5};
  // Prompt for an input
  std::cout<<"Enter an index from 0 to "<<list_size-1<<" (or -1 to exit): ";
  // Repeat until a valid index or -1 (to quit) is entered,
  // .. or max_attempts attempts are made
  while(attempts<max_attempts)
  {
    if(!(std::cin>>index) || (index!=-1 && (index<0 || index>=list_size)) || std::cin.peek()!='\n')
    {
      std::cout<<"Invalid input. Please enter a valid index"
               <<" from 0 to "<<list_size-1<<" (or -1 to exit): ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else break;  // Valid index, exit the loop
    attempts++;
  }
  if(attempts==max_attempts)
  {
    std::cout<<"\nMaximum attempts reached. "<<std::endl;
    index = -1;
  }
  return index;
}

// Getters/Setters
// .. add an author to the back of the list
void AuthorList::add_author(const Author& author)
{
  authors.push_back(author);
}
// .. remove an author from a given position in the list
void AuthorList::remove_author_at(const size_t index_to_remove)
{
  if(!is_valid_index(index_to_remove)) return;

  auto author_iter = authors.begin();
  std::advance(author_iter, index_to_remove);
  authors.erase(author_iter);
}
// .. remove an author by prompting for an index first
void AuthorList::remove_author()
{
  size_t list_size{authors.size()};
  // End early if no authors in the list
  if(list_size==0)
  {
    std::cout<<"No authors to remove."<<std::endl;
    return;
  }
  // If only one author, confirm if they want to remove it
  else if(list_size==1)
  {
    std::cout<<"There is only one author listed: ";
    print_authors();
    std::cout<<"Are you sure you want to remove them?"<<std::endl;
    bool confirmed{lit_cat_utils::get_yes_no_from_user()};
    if(confirmed) // remove the author
    {
      remove_author_at(0);
      std::cout<<"Author removed."<<std::endl;
    }
    else std::cout<<"Author not removed."<<std::endl;
  }
  // If more than one author ask which to remove
  else
  {
    // Prompt for an author to remove
    std::cout<<"Which author would you like to"
             <<" remove from the list below?"<<std::endl;
    print_authors_with_index();
    // Get the index of chosen author from user
    int chosen_index{get_index_from_user()};
    if(chosen_index==-1) // no index given
    {
      std::cout<<"No authors removed"<<std::endl;
      return;
    }
    // Remove the chosen index
    remove_author_at(static_cast<size_t>(chosen_index));
  }
}
// .. get an author from a given position in the list
shared_ptr<const Author> AuthorList::get_author_at(const size_t index_to_get) const
{
  if(!is_valid_index(index_to_get))
  {
    std::cerr<<"Error: Invalid index, returning a nullptr."<<std::endl;
    return nullptr;
  }

  auto author_iter = authors.begin();
  std::advance(author_iter, index_to_get);
  return std::make_shared<const Author>(*author_iter);
}
// .. get an author by prompting for an index first
shared_ptr<const Author> AuthorList::get_author() const
{
  size_t list_size{authors.size()};
  // End early if no authors in the list
  if(list_size==0)
  {
    std::cout<<"Error: No authors to retrieve."<<std::endl;
    return nullptr;
  }
  // If only one author, return it
  else if(list_size==1) return get_author_at(0);
  // If more than one author ask which to remove
  else
  {
    // Prompt for an author to retrieve
    std::cout<<"Which author would you like to"
             <<" get from the list below?"<<std::endl;
    print_authors_with_index();
    // Get the index of chosen author from user
    int chosen_index{get_index_from_user()};
    if(chosen_index==-1) // no index given
    {
      std::cout<<"No authors retrieved, returning nullptr."<<std::endl;
      return nullptr;
    }
    // Retrieve the chosen index
    return get_author_at(static_cast<size_t>(chosen_index));
  }
}

// Print Information
void AuthorList::print_authors() const
{
  int count{0};
  for(auto author{authors.begin()}; author!=authors.end(); ++author)
  {
    // End early if more than 3 authors, with et al.
    count++;
    if(count>3)
    {
      std::cout<<"et al."<<std::endl;
      return;
    }
    // Print author name
    author->print_name();
    // Place commas between all but last element
    if(std::next(author)!=authors.end()) std::cout<<", ";
  }
  std::cout<<std::endl;
}

// 