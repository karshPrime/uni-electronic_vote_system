/*
This file contains functions that would be required by different modules
*/

#include "general.h"    // contains common declarations

// prints the contents of the given text file
void print_file_content(std::string file_name) {
  // adding file extension
  file_name += ".txt";

  std::fstream toread;

  toread.open(file_name, std::ios::in);
  if (toread.is_open()) {
    std::string text_line;

    // loop through the file- line by line, and print the content
    while (std::getline(toread, text_line)) {
      std::cout << text_line << "\n";
    }

    toread.close();
  }
  else {
    std::cout << "file not found\n";
  }
}

// given a string, splits it by the delimiter and puts it in a vector
// Reference: https://stackoverflow.com/a/600040
void split_string(const std::string &str, const std::string &delimiters, std::vector<std::string> &result) {
  // skip delimiters at beginning
  std::string::size_type last_pos = str.find_first_not_of(delimiters, 0);

  // find first "non-delimiter".
  std::string::size_type pos = str.find_first_of(delimiters, last_pos);

  while (std::string::npos != pos || std::string::npos != last_pos) {
    // found a token, add it to the vector.
    result.push_back(str.substr(last_pos, pos - last_pos));

    // skip delimiters. Note the "not_of"
    last_pos = str.find_first_not_of(delimiters, pos);

    // find next "non-delimiter"
    pos = str.find_first_of(delimiters, last_pos);
  }
}