// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Main functionality
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <memory> // smart pointers
#include "authors.h"
#include "authorlist.h"
#include "literature-element.h"
#include "book.h"

int main()
{
  // Trial Authors
  Author a1{"Rock", "And", "Roll"};
  Author a2{"Stock", "and a", "Poll"};
  Author a3{"I am", "A new", "Name-okay"};
  
  // Testing Book
  Book b0{"A Dictionary", AuthorList{a1, a1, a2, a2, a3, a3},
          "Whomeggies", "English Literature", 230.11212};
  b0.print_info();
  b0.remove_author();

  // Ro5:
  // Book b1; // default constr.
  // b1.print_info();
  // Book b2{"War of the worlds", AuthorList{a1, a2, a3},
  //         "Pub. Company", "Fiction", 1.513}; // param constr.
  // b2.print_info();
  // Book b3{b2}; // copy constr.
  // b3.print_info();
  // Book b4{std::move(b2)}; // move constr.
  // b4.print_info();
  // b2.print_info();
  // Book b5; // copy =
  // b5.print_info();
  // b5 = b2;
  // b5.print_info();
  // Book b6; // move =
  // b6 = std::move(b2);
  // b6.print_info();
  // b2.print_info();

  // Testing LiteratureElement
  // LiteratureElement le0{BOOK, "War of the worlds", AuthorList{a1, a2, a3}};
  // std::cout<<le0.get_unique_id()<<std::endl
  //          <<le0.get_type()<<std::endl
  //          <<le0.get_title()<<std::endl;
  // le0.get_authors()->print_authors();
  // le0.set_title("2nd WotW");
  // le0.set_authors(std::list<Author>{a3, a1});
  //le0.set_authors(AuthorList{a3, a2});
  // le0.add_author(a1);
  // le0.remove_author();
  // le0.print_info();
  
  // Testing AuthorList
  // std::cout<<"===== al1 ====="<<std::endl; // Default constr.
  // AuthorList al1{};
  // al1.print_authors();
  // std::cout<<"==============="<<std::endl;

  // std::cout<<"===== al2 ====="<<std::endl; // Param. constr. arb. Author arguments
  // AuthorList al2{a1, a2};
  // al2.print_authors();
  // al2.add_author(a3);
  // al2.print_authors();
  // std::cout<<"==============="<<std::endl;

  return 0;
}