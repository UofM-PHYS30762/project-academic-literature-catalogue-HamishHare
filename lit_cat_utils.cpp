#include "lit_cat_utils.h"

namespace lit_cat_utils
{
  // Function to convert strings to lowercase
  void to_lowercase(string& input_string)
  {
    std::transform(input_string.begin(), input_string.end(), input_string.begin(),
                   [](unsigned char c){return std::tolower(c);});
  }

  // Function to get a yes/no from user and return a matching bool
  bool get_yes_no_from_user()
  {
    string input;
    size_t attempts{0};
    const size_t max_attempts{5};
    
    std::cout<<"Enter yes or no (or y/n): ";
    while(attempts<max_attempts)
    {
      std::cin>>input;
      to_lowercase(input);// Convert the input to lowercase
      
      if (input=="yes" || input=="y") return true;
      else if (input=="no" || input=="n") return false;
      else
      {
        std::cout<<"Invalid input. Please enter 'yes' or 'no' (or y/n): ";
        attempts++;
      }
    }
    
    std::cout<<"\nMaximum attempts reached. Defaulting to 'no'."<<std::endl;
    return false;
  }
}