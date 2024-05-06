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
    Author a0{"Test", "", "Passed"}; // Valid
    // Author a0{"T-e-s-t", "-", "P a s s e d"}; // Valid
    // Author a0{"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", "", ""}; // Too long
    // Author a0{"abcde4", "", "Passed"}; // Invalid character
    // Author a0{"abcd'e", "", "Passed"}; // Invalid character
    // Author a0{"a/!bcde4", "", "Passed"}; // Invalid character
    // Author a0{"abcdefgh  ", "", "Passed"}; // Consecutive space
    // Author a0{"--abcdefgh", "", "Passed"}; // Consecutive hyphens
    a0.print_name();

    // std::cout<<is_valid_name("test")<<std::endl; // Valid
    // std::cout<<is_valid_name("t-e-s-t")<<std::endl; // Valid
    // std::cout<<is_valid_name("Paul AstonSSDSD")<<std::endl; // Valid
    // //std::cout<<is_valid_name("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz")<<std::endl; // Too long
    // //std::cout<<is_valid_name("abcde4")<<std::endl; // Invalid character
    // //std::cout<<is_valid_name("abcdefgh  ")<<std::endl; // Consecutive space
    // std::cout<<is_valid_name("--abcdefgh")<<std::endl; // Consecutive hyphens
    
    // Testing Ro5
    Author a1;
    a1.print_name();

    Author a2{"Rock", "And", "Roll"};
    a2.print_name();
    
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

    return 0;
}