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

int main()
{
  // Trial Authors
  Author a1{"Rock", "And", "Roll"};
  Author a2{"Stock", "and a", "Poll"};
  Author a3{"I am", "A new", "Name-okay"};

  // Testing LiteratureElement
  LiteratureElement le0{BOOK, "War of the worlds", AuthorList{a1, a2, a3}};
  // std::cout<<le0.get_unique_id()<<std::endl
  //          <<le0.get_type()<<std::endl
  //          <<le0.get_title()<<std::endl;
  // le0.get_authors()->print_authors();
  // le0.set_title("2nd WotW");
  // le0.set_authors(std::list<Author>{a3, a1});
  //le0.set_authors(AuthorList{a3, a2});
  le0.add_author(a1);
  le0.remove_author();
  le0.print_info();

  // Ro5:
  // LiteratureElement le1; // default constr.
  // le1.print_info();
  // LiteratureElement le2{BOOK, "War of the worlds", AuthorList{a1, a2, a3}}; // param constr.
  // le2.print_info();
  // LiteratureElement le3{le2}; // copy constr.
  // le3.print_info();
  // LiteratureElement le4{std::move(le2)}; // move constr.
  // le4.print_info();
  // le2.print_info();
  // LiteratureElement le5{BOOK, "Not WotW", AuthorList{a2}}; // copy =
  // le5.print_info();
  // le5 = le2;
  // le5.print_info();
  // LiteratureElement le6{BOOK, "Not WotW", AuthorList{a2}}; // move =
  // le6 = std::move(le2);
  // le6.print_info();
  // le2.print_info();
  
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