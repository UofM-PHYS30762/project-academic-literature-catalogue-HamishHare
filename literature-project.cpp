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
#include "literature-catalogue.h"

int main()
{
  // Trial Authors
  Author a1{"Rock", "And", "Roll"};
  Author a2{"Stock", "and a", "Poll"};
  Author a3{"I am", "A new", "Name-okay"};

  // Test Book
  Book b0{"To Kill a Mockingbird", AuthorList{a3, a2, a1},
  "Publishing Company", "Fiction", 13.99}; // fine
  // Book b0{"To Kill a Mockingbird", AuthorList{a3, a2, a1},
  //         "Publishing Company", "Fiction", 10000.546}; // large price
  // Book b0{"To Kill a Mockingbird", AuthorList{a3, a2, a1},
  // "Publishing Company", "Fiction", -1.546}; // negative price
  // b0.print_info();
  // b0.set_price(-1);
  // b0.set_publisher("New Pub Co.");
  // b0.set_subject("New Subject");
  // b0.print_info();

  // Test Thesis
  Thesis t0{"Cancer Cure", AuthorList{a1}, "Super Visor", "Universe City"};
  // t0.print_info();
  // t0.set_supervisor("S. Visor Jr");
  // t0.set_university("U. City Jr");
  // t0.print_info();
  
  // Test Journal
  Journal j0{"A Journal", AuthorList{a1, a1, a2, a3},
             30.2, 2, 120, 80,
             set<string>{"Astronomy", "Biophysics",
             "Chemisty", "Applied Nuclear"}};
  // j0.print_info();
  // j0.remove_author();
  // j0.set_impact_factor(10000.0); // over max
  // j0.set_impact_factor(250.0); // caution
  // j0.set_impact_factor(-12); // negative
  // j0.set_num_contributors(-34);
  // j0.set_num_papers(-20);
  // j0.set_num_volumes(1212);
  // j0.set_scope(set<string>{"XXXX", "RRRRR", "EEEEE"});
  // j0.print_info();

  std::cout<<catalogue_utils::get_field_from_user();

  // Test Catalogue
  // Catalogue c1;
  // c1.print_catalogue();
  // Catalogue c2{std::make_shared<Book>(b0),
  //              std::make_shared<Thesis>(t0),
  //              std::make_shared<Journal>(j0)};
  // c2.print_catalogue();
  // set<lit_elem_ptr> leSet{std::make_shared<Thesis>(t0),
  //                         std::make_shared<Book>(b0)};
  // Catalogue c3{leSet};
  // c3.print_catalogue();

  // Catalogue c4{c3};
  // c4.print_catalogue();
  // Catalogue c5{std::move(c3)};
  // c5.print_catalogue();
  // c3.print_catalogue();

  // Catalogue c6;
  // c6 = c3;
  // c6.print_catalogue();
  // Catalogue c7;
  // c7 = std::move(c3);
  // c7.print_catalogue();
  // c3.print_catalogue();


  // Ro5:
  // Journal j1; // default constr.
  // j1.print_info();
  // Journal j2{"Food Studies", AuthorList{a1, a3},
  //            1.21212, 4, 1000, 567,
  //            set<string>{"Pancakes", "Sandwiches",
  //            "Eggs", "Fruits"}}; // param constr.
  // j2.print_info();
  // Journal j3{j2}; // copy constr.
  // j3.print_info();
  // Journal j4{std::move(j2)}; // move constr.
  // j4.print_info();
  // j2.print_info();
  // Journal j5; // copy =
  // j5.print_info();
  // j5 = j2;
  // j5.print_info();
  // Journal j6; // move =
  // j6 = std::move(j2);
  // j6.print_info();
  // j2.print_info();

  return 0;
}