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

  std::cout<<"===== al1 ====="<<std::endl;
  AuthorList al1{};
  al1.print_authors();
  std::cout<<"==============="<<std::endl;

  std::cout<<"===== al2 ====="<<std::endl;
  AuthorList al2{a1, a2};
  al2.print_authors();
  al2.add_author(a3);
  al2.print_authors();
  std::cout<<"==============="<<std::endl;

  std::cout<<"===== al3 ====="<<std::endl;
  AuthorList al3{a1};
  al3.print_authors();
  al3.add_author(a3);
  al3.print_authors();
  std::cout<<"==============="<<std::endl;

  return 0;
}