/*
This file contains functions that would be required by different modules
*/

#include "general.h"    // contains common declarations

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

// print details of passed candidate
void print_candidate(const Candidate &c) {
  // configure console color
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  int red = 4, aqua = 11, green = 10, yellow = 14; // color codes

  SetConsoleTextAttribute(h, green);
  std::cout << "ID           : ";
  SetConsoleTextAttribute(h, aqua);
  std::cout << c.id << std::endl;

  SetConsoleTextAttribute(h, green);
  std::cout << "Name:        : ";
  SetConsoleTextAttribute(h, aqua);
  std::cout << c.l_name << " " << c.f_name << std::endl;

  SetConsoleTextAttribute(h, red);
  std::cout << "Total Votes  : ";
  SetConsoleTextAttribute(h, yellow);
  std::cout << c.count << std::endl;

  SetConsoleTextAttribute(h, green);
  std::cout << "Party:       : ";
  SetConsoleTextAttribute(h, aqua);
  std::cout << c.symbol << std::endl;

  SetConsoleTextAttribute(h, green);
  std::cout << "Age:         : ";
  SetConsoleTextAttribute(h, aqua);
  std::cout << c.age << std::endl;

  SetConsoleTextAttribute(h, green);
  std::cout << "Gender       : ";
  SetConsoleTextAttribute(h, aqua);
  std::cout << c.gender << std::endl;

  SetConsoleTextAttribute(h, green);
  std::cout << "Suburb:      : ";
  SetConsoleTextAttribute(h, aqua);
  std::cout << c.suburb << std::endl;

  SetConsoleTextAttribute(h, green);
  std::cout << "Phone Number : ";
  SetConsoleTextAttribute(h, aqua);
  std::cout << c.phone << std::endl;

  SetConsoleTextAttribute(h, green);
  std::cout << "email        : ";
  SetConsoleTextAttribute(h, aqua);
  std::cout << c.email << std::endl;
}