#ifndef LIT_CAT_UTILS_H
#define LIT_CAT_UTILS_H

#include <iostream>
#include <string>
#include <algorithm>
using std::string;

namespace lit_cat_consts
{
  const bool show_messages{false};
}

namespace lit_cat_utils
{
  // Function to convert strings to lowercase
  void to_lowercase(string& input_string);
  // Function to get a yes or no from the user
  bool get_yes_no_from_user();
}

#endif // LIT_CAT_UTILS_H