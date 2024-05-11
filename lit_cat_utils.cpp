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

  // Function to validate a positive float
  bool is_valid_positive_float(const float& float_to_check,
                               const float& caution_limit,
                               const float& max_limit,
                               const std::string_view& prompt_field)
  {
    // Check whether float_to_check is positive
    if(float_to_check<0.0)
    {
      std::cerr<<"Error: "<<prompt_field<<" cannot be negative."
               <<" Given "<<prompt_field<<": "<<float_to_check<<std::endl;
      return false;
    }
    // Check whether float_to_check is below max_limit
    if(float_to_check>max_limit)
    {
      std::cerr<<"Error: "<<prompt_field<<" exceeds maximum allowed value."
               <<" Given "<<prompt_field<<": "<<float_to_check
               <<", Max allowed: "<<max_limit<<std::endl;
      return false;
    }
    // Check if the value is over caution_limit, prompting user to confirm
    if(float_to_check>caution_limit)
    {
      std::cout<<"You have entered a large "<<prompt_field<<" ("<<float_to_check
               <<"), is this correct?"<<std::endl;
      return get_yes_no_from_user();
    }
    return true;
  }

  // Function to prompt the user for a valid positive float
  float prompt_for_valid_positive_float(const float& caution_limit,
                                        const float& max_limit,
                                        const std::string_view& prompt_field)
  {
    float new_float{0};
    size_t attempts{0};
    const size_t max_attempts{5};
    // Prompt for an input
    std::cout<<"Enter a "<<prompt_field<<" (or -1 to exit): ";
    // Repeat until a valid float or -1 (to quit) is entered,
    // .. or max_attempts attempts are made
    while(attempts<max_attempts)
    {
      // if(!(std::cin>>new_float) || (new_float!=-1 && new_float<0) || std::cin.peek()!='\n')
      if(!(std::cin>>new_float)
         || (new_float!=-1 && !is_valid_positive_float(new_float, caution_limit, max_limit, prompt_field))
         || std::cin.peek()!='\n')
      {
        std::cout<<"Please enter a valid positive "<<prompt_field
                <<" (or -1 to exit): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else break;  // Valid float, exit the loop
      attempts++;
    }
    if(attempts==max_attempts)
    {
      std::cout<<"\nMaximum attempts reached."<<std::endl;
      new_float = -1;
    }
    return new_float;
  }

  // // Function to prompt the user for a valid positive float
  // size_t prompt_for_valid_size_t(const float& caution_limit,
  //                               const float& max_limit,
  //                               const std::string_view& prompt_field)
  // {
  //   int new_value;
  //   size_t attempts{0};
  //   const size_t max_attempts{5};
  //   // Prompt for an input
  //   std::cout<<"Enter a "<<prompt_field<<" (or -1 to exit): ";
  //   // Repeat until a valid value or -1 (to quit) is entered,
  //   // .. or max_attempts attempts are made
  //   while(attempts<max_attempts)
  //   {
  //     if(!(std::cin>>new_value)
  //        || (new_value!=-1 && (new_value<0 || new_value>=list_size))
  //        || std::cin.peek()!='\n')
  //     {
  //       std::cout<<"Please enter a valid positive "<<prompt_field
  //               <<" (or -1 to exit): ";
  //       std::cin.clear();
  //       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  //     }
  //     else break; // Valid, exit the loop
  //     attempts++;
  //   }
  //   if(attempts==max_attempts)
  //   {
  //     std::cout<<"\nMaximum attempts reached. "<<std::endl;
  //     new_value = -1;
  //   }
  //   return new_value;
  // }
}