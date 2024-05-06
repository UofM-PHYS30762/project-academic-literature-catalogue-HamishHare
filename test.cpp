#include <cctype>
#include <string_view>
#include <algorithm>
#include <iostream>

// Check whether 'char_to_check' is consecutively repeated in 'name'
bool is_repeated_char(const std::string_view& name, const char char_to_check)
{
  bool previous_is_checked_char{false};
  return std::any_of(name.begin(), name.end(), [&](char c)
    {
      if(c == char_to_check)
      {
        if(previous_is_checked_char) return true; // two consecutive
        previous_is_checked_char = true;
      }
      else previous_is_checked_char = false;
      return false; // not repeated
    });
}

bool is_valid_name(const std::string_view& name)
{
  constexpr size_t max_name_length = 40; // Maximum allowed length for a name

  // Check if the length of the name is not too long
  if(name.length() > max_name_length)
  {
    std::cerr<<"Error: name too long (>"<<max_name_length<<" characters). Given name: "<<name<<std::endl;
    exit(1);
  }

  // Check if all characters in the name are allowed
  if(!std::all_of(name.begin(), name.end(), [](char c)
    {
      return std::isalpha(static_cast<unsigned char>(c))
      || c == ' ' || c == '-';
    }))
  {
    std::cerr<<"Error: invalid character entered in given name ("<<name<<")."<<std::endl;
    exit(1);
  }

  // Check that there aren't multiple spaces or hyphens in a row
  if(is_repeated_char(name, ' ') || is_repeated_char(name, '-'))
  {
    std::cerr<<"Error: name cannot have consecutively repeated special characters. Given name: "<<name<<std::endl;
    exit(1);
  }

  return true;
}


int main()
{
  std::cout<<is_valid_name("test")<<std::endl; // Valid
  std::cout<<is_valid_name("t-e-s-t")<<std::endl; // Valid
  std::cout<<is_valid_name("Paul AstonSSDSD")<<std::endl; // Valid
  //std::cout<<is_valid_name("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz")<<std::endl; // Too long
  //std::cout<<is_valid_name("abcde4")<<std::endl; // Invalid character
  //std::cout<<is_valid_name("abcdefgh  ")<<std::endl; // Consecutive space
  std::cout<<is_valid_name("--abcdefgh")<<std::endl; // Consecutive hyphens
}