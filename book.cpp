// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Book implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iomanip>
#include <limits> // for numeric_limits
#include "book.h"

namespace book_utils
{
  // Prompt for a new price
  float prompt_for_price()
  {
    float new_price{0};
    size_t attempts{0};
    const size_t max_attempts{5};
    // Prompt for an input
    std::cout<<"Enter a price (or -1 to exit): ";
    // Repeat until a valid price or -1 (to quit) is entered,
    // .. or max_attempts attempts are made
    while(attempts<max_attempts)
    {
      if(!(std::cin>>new_price) || (new_price!=-1 && new_price<0) || std::cin.peek()!='\n')
      {
        std::cout<<"Invalid input. Please enter a valid price"
                <<" (or -1 to exit): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else break;  // Valid price, exit the loop
      attempts++;
    }
    if(attempts==max_attempts)
    {
      std::cout<<"\nMaximum attempts reached. Setting price to 0."<<std::endl;
      new_price = 0;
    }
    return new_price;
  }

  // Validate the price
  bool is_valid_price(const float& price_to_check)
  {
    // Check whether price_to_check is positive
    if(price_to_check<0.0)
    {
      std::cerr<<"Error: price cannot be negative. Given price: "<<price_to_check<<std::endl;
      return false;
    }
    // Check if the value is large, then prompt user to confirm
    if(price_to_check>10000.0)
    {
      std::cout<<"You have entered a large price ("<<price_to_check
               <<"), is this correct?"<<std::endl;
      return lit_cat_utils::get_yes_no_from_user();
    }
    return true;
  }
}

// Rule of 5
// .. Default constructor
Book::Book() : LiteratureElement(BOOK, string("Default Book"), AuthorList()),
               publisher{"Default Publisher"}, subject{"Default Subject"}, price{0.00}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling default Book constructor"<<std::endl;
}
// .. Parameterised constructor
Book::Book(const string& _title, const AuthorList& _authors,
           const string& _publisher, const string& _subject,
           const float& _price) : LiteratureElement(BOOK, _title, _authors)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling parameterised Book constructor"<<std::endl;
  publisher = _publisher; // Validation?
  subject = _subject; // Validation?
  if(book_utils::is_valid_price(_price)) price = _price;
  else
  {
    float new_price{book_utils::prompt_for_price()};
    if(new_price==-1)
    {
      std::cout<<"Setting price to zero."<<std::endl;
      price = 0;
    }
    else price = new_price;
  }
}
// .. Copy constructor
Book::Book(const Book& book_to_copy) : LiteratureElement(book_to_copy),
                                       publisher{book_to_copy.publisher},
                                       subject{book_to_copy.subject},
                                       price{book_to_copy.price}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Book copy constructor"<<std::endl;
}
// .. Move constructor
Book::Book(Book&& book_to_move) : LiteratureElement(std::move(book_to_move)),
                                  publisher{std::move(book_to_move.publisher)},
                                  subject{std::move(book_to_move.subject)},
                                  price{std::move(book_to_move.price)}
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Book move constructor"<<std::endl;
}
// .. Copy assignment operator
Book& Book::operator=(const Book& book_to_copy)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Book copy assignment operator"<<std::endl;
  if(&book_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  // .. of the base class
  LiteratureElement::operator=(book_to_copy);
  // .. of the book only
  publisher = book_to_copy.publisher;
  subject = book_to_copy.subject;
  price = book_to_copy.price;

  return *this;
}
// .. Move assignment operator
Book& Book::operator=(Book&& book_to_move)
{
  if(lit_cat_consts::show_messages) std::cout<<"Calling Book move assignment operator"<<std::endl;
  if(&book_to_move == this) return *this; // no self-assignment

  // Move the data members
  // .. of the base class
  LiteratureElement::operator=(std::move(book_to_move));
  // .. of the book only
  publisher = std::move(book_to_move.publisher);
  subject = std::move(book_to_move.subject);
  price = std::move(book_to_move.price);
  
  return *this;
}

// Setters
void Book::set_publisher(const string& _publisher)
{
  publisher = _publisher; // Validation?
}
void Book::set_subject(const string& _subject)
{
  subject = _subject; // Validation?
}
void Book::set_price(const float& _price)
{
  if(book_utils::is_valid_price(_price)) price = _price;
  else
  {
    float new_price{book_utils::prompt_for_price()};
    if(new_price!=-1) price = new_price;
  }
}

// Print Information
void Book::print_info()
{
  LiteratureElement::print_info();
  std::cout<<"PUBLISHER: "<<publisher<<std::endl;
  std::cout<<"SUBJECT: "<<subject<<std::endl;
  std::cout<<" PRICE: "<<std::fixed<<std::setprecision(2)
                       <<price<<" GBP"<<std::endl;
  std::cout<<"======="<<std::endl;
}