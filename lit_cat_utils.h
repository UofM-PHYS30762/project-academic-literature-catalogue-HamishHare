#ifndef LIT_CAT_UTILS_H
#define LIT_CAT_UTILS_H

#include <iostream>
#include <string>
#include <algorithm>
#include <string_view> // efficient string viewing when no editting
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
  // Function to validate a positive float
  bool is_valid_positive_float(const float& float_to_check,
                               const float& caution_limit, // value above which to seek confirmation
                               const float& max_limit, // maximum allowed value
                               const std::string_view& prompt_field);
  // Function to prompt the user for a valid positive float
  float prompt_for_valid_positive_float(const float& caution_limit, // value above which to seek confirmation
                                        const float& max_limit, // maximum allowed value
                                        const std::string_view& prompt_field);
}

#endif // LIT_CAT_UTILS_H