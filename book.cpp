// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Book implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iomanip>
#include <limits> // for numeric_limits
#include "book.h"

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
  if(lit_cat_utils::is_valid_positive_float(_price, price_caution_value,
                                            price_maximum_value, "price")) price = _price;
  else
  {
    float new_price{lit_cat_utils::prompt_for_valid_positive_float(price_caution_value,
                                                                   price_maximum_value, "price")};
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
  if(lit_cat_utils::is_valid_positive_float(_price, price_caution_value,
                                            price_maximum_value, "price")) price = _price;
  else
  {
    float new_price{lit_cat_utils::prompt_for_valid_positive_float(price_caution_value,
                                                                   price_maximum_value, "price")};
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