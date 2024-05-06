// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Main functionality
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <memory> // smart pointers
#include "authors.h"

int main()
{
    // Testing validation
    // Author a0{"Test", "", "Passed"}; // Valid
    // Author a0{"T-e-s-t", "-", "P a s s e d"}; // Valid
    // Author a0{"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", "", ""}; // Too long
    // Author a0{"abcde4", "", "Passed"}; // Invalid character
    // Author a0{"abcd'e", "", "Passed"}; // Invalid character
    // Author a0{"a/!bcde4", "", "Passed"}; // Invalid character
    // Author a0{"abcdefgh  ", "", "Passed"}; // Consecutive space
    // Author a0{"--abcdefgh", "", "Passed"}; // Consecutive hyphens
    // a0.print_name();
    
    // Testing Ro5
    // Author a1;
    // a1.print_name();

    // Author a2{"Rock", "And", "Roll"};
    // a2.print_name();
    
    // Author a3{a2};
    // a3.print_name();

    // Author a4{std::move(a2)};
    // a4.print_name();
    // a2.print_name();

    // Author a5;
    // a5=a2;
    // a2.print_name();

    // Author a6;
    // a6=std::move(a2);
    // a6.print_name();
    // a2.print_name();

    // Testing Setters/Getters
    Author a7;
    a7.set_first_name("first");
    a7.set_middle_names("middle");
    a7.set_last_name("last");
    std::cout<<a7.get_first_name()<<", "<<a7.get_middle_names()<<", "<<a7.get_last_name()<<std::endl;
    a7.set_names("aaaaaaaaa", "BBBBBB", "ccC-cC");
    a7.print_name();

    return 0;
}