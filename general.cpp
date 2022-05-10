#include <iostream>
#include <fstream>
#include <string>

/*
This file contains functions that would be required by different modules
*/

// print content of the passed file
void print_file_content(std::string file_name) {
  file_name += ".txt";  // adding file extension
  std::fstream toread;

  toread.open(file_name, std::ios::in);
  if (toread.is_open()) {
    std::string text_line;
    // loop through the file- line by line, and print the content
    while (std::getline(toread, text_line)) {
      std::cout << text_line << "\n";
    }
    toread.close();

  } else {
    std::cout << "file not found\n";
  }
}
