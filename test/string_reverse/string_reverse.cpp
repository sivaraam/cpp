#include "string_reverse.h"

namespace unique {

  // Reverse a string using recursion without
  // extracting a substring of the given string
  /*string reverse(string str, size_t length) {
    // if length is default value get length of string
    if(length == 0) {
      length = str.length();
    }

    if(length == 1) {
      return string {str.front()};
    }

    return str.at(length-1) + reverse(str, length-1);
  } */

  // Reverse a string using recursion by
  // extracting a substring of the given string
  string reverse(string str) {
    size_t curr_length =  str.length();

    if(curr_length == 1) {
      return string {str.front()};
    }

    return str.at(curr_length-1) + reverse(str.substr(0,curr_length-1));
  }
}
