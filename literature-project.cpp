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
#include "thesis.h"

int main()
{
  // Trial Authors
  Author a1{"Rock", "And", "Roll"};
  Author a2{"Stock", "and a", "Poll"};
  Author a3{"I am", "A new", "Name-okay"};
  
  // Testing Thesis
  // Thesis t0{"A Study", AuthorList{a1, a1, a2, a3},
  //           "Mystery Man", "UoM"};
  // t0.print_info();
  // t0.remove_author();

  // Ro5:
  // Thesis t1; // default constr.
  // t1.print_info();
  Thesis t2{"War of the worlds", AuthorList{a1, a2, a3},
            "Super Visor", "Uni Versity"}; // param constr.
  t2.print_info();
  // Thesis t3{t2}; // copy constr.
  // t3.print_info();
  // Thesis t4{std::move(t2)}; // move constr.
  // t4.print_info();
  // t2.print_info();
  // Thesis t5; // copy =
  // t5.print_info();
  // t5 = t2;
  // t5.print_info();
  // Thesis t6; // move =
  // t6 = std::move(t2);
  // t6.print_info();
  // t2.print_info();

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

  return 0;
}