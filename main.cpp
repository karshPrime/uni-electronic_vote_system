#include <iostream>
#include <windows.h>
#include "general.h"

// simpler way to store user input
template <typename T>
void input(const std::string& display, T& store_in) {
  std::cout << display;
  std::cin >> store_in;

  // removing 'extra input'
  std::cin.ignore(100, '\n');
}

// main function
int main() {
  // configure console color
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  int red = 4, aqua = 11, green = 10, yellow = 14; // color codes

  // setting font color to red
  SetConsoleTextAttribute(h, red);       // prompt font color = red
  print_file_content("heading");
  char chosen_option = 'a';

  // loop until user opts to quit
  while (chosen_option != 'q') {
    SetConsoleTextAttribute(h, aqua);       // prompt font color = blue
    print_file_content("menu");

    SetConsoleTextAttribute(h, green);      // prompt font color = green
    input(">>> ", chosen_option);
    std::cout << std::endl; // print empty line

    SetConsoleTextAttribute(h, yellow); // prompt font color = yellow
    // switch statement for upper case user_input
    switch ((char)toupper(chosen_option)) {
      case 'P':
        std::cout << "hello P\n";
        // call function to display number of candidates here
        break;
      case 'A':
        std::cout << "hello A\n";
        break;
      case 'S':
        std::cout << "hello S\n";
        // call function to display candidate with the least votes here
        break;
      case 'L':
        std::cout << "hello L\n";
        // call function to display candidate with the most votes here
        break;
      default:
        // setting font color to dark red
        SetConsoleTextAttribute(h, red);    // prompt font color = red
        std::cout << "Invalid Input\n";
        break;
    }
    std::cout << std::endl;
  }
}
