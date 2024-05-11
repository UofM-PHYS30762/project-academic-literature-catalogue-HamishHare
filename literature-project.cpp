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
#include "journal.h"

int main()
{
  // Trial Authors
  Author a1{"Rock", "And", "Roll"};
  Author a2{"Stock", "and a", "Poll"};
  Author a3{"I am", "A new", "Name-okay"};
  
  // Testing Journal
  // Journal j0{"A Journal", AuthorList{a1, a1, a2, a3},
  //            30.2, 2, 120, 80,
  //            set<string>{"Astronomy", "Biophysics",
  //            "Chemisty", "Applied Nuclear"}};
  // j0.print_info();
  // j0.remove_author();

  // Ro5:
  // Journal j1; // default constr.
  // j1.print_info();
  Journal j2{"Food Studies", AuthorList{a1, a3},
             1.21212, 4, 1000, 567,
             set<string>{"Pancakes", "Sandwiches",
             "Eggs", "Fruits"}}; // param constr.
  j2.print_info();
  // Journal j3{j2}; // copy constr.
  // j3.print_info();
  // Journal j4{std::move(j2)}; // move constr.
  // j4.print_info();
  // j2.print_info();
  Journal j5; // copy =
  j5.print_info();
  j5 = j2;
  j5.print_info();
  Journal j6; // move =
  j6 = std::move(j2);
  j6.print_info();
  j2.print_info();

  return 0;
}