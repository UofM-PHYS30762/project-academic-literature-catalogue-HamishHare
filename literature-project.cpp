// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Main functionality
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <memory> // smart pointers
#include "authors.h"
#include "authorlist.h"

int main()
{
  // Testing AuthorList
  Author a1{"Rock", "And", "Roll"};
  Author a2{"Stock", "and a", "Poll"};
  Author a3{"I am", "A new", "Name-okay"};

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

  // std::cout<<"===== al3 ====="<<std::endl; // Param. constr. list of Authors
  // std::list<Author> temp_alist{a1, a2, a3};
  // AuthorList al3{temp_alist};
  // al3.print_authors();
  // std::cout<<"==============="<<std::endl;

  // std::cout<<"===== al4 ====="<<std::endl; // Param. constr. single Author argument (special case of arb.)
  // AuthorList al4{a1};
  // al4.print_authors();
  // al4.add_author(a3);
  // al4.print_authors();
  // std::cout<<"==============="<<std::endl;

  // AuthorList al5{al3}; // Copy constr.
  // al5.print_authors();

  // AuthorList al6{std::move(al3)}; // Move constr.
  // al6.print_authors();
  // al3.print_authors();

  // AuthorList al7; // Copy assignment
  // al7 = al3;
  // al7.print_authors();

  // AuthorList al8; // Move assignment
  // al8 = std::move(al3);
  // al8.print_authors();
  // al3.print_authors();

  // Test with index
  // al2.remove_author_at(2);
  // al2.print_authors();
  // al2.get_author_at(1).print_name();

  // Test adding many authors and printing names
  std::cout<<"===== al9 ====="<<std::endl; // Param. constr. arb. Author arguments
  AuthorList al9{a1, a1, a1, a2, a2, a2, a3, a3, a3};
  al9.print_authors();
  std::cout<<"==============="<<std::endl;
  // Test removing author when prompted
  al9.remove_author();
  al9.print_authors();
  std::cout<<"==============="<<std::endl;
  AuthorList al10;
  al10.print_authors();
  al10.remove_author();
  std::cout<<"==============="<<std::endl;
  AuthorList al11{a1};
  al11.print_authors();
  al11.remove_author();
  al11.print_authors();
  std::cout<<"==============="<<std::endl;

  return 0;
}