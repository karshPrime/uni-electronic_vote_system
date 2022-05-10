#include <iostream>
#include <windows.h>
#include "general.h"

// more compact way to get user input
template <typename T>
void input(const std::string& display, T& store_in) {
  std::cout << display;
  std::cin >> store_in;
}

// main function
int main() {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(h, 1);
  print_file_content("heading");
  char chosen_option = 'a';

  // loop until user opts to quit
  while (chosen_option != 'q') {
    SetConsoleTextAttribute(h, 3);
    print_file_content("menu");

    SetConsoleTextAttribute(h, 4);
    input(">>> ", chosen_option);
    std::cout << std::endl;
    
    // removing empty char from last cin.
    std::cin.ignore(100, '\n');

    // switch statement for upper case user_input
    switch ((char)toupper(chosen_option)) {
      case 'P':
        // call function to display number of candidates here
        break;
      case 'A':
        // call function to add votes to a candidate here
        break;
      case 'S':
        // call function to display candidate with the least votes here
        break;
      case 'L':
        // call function to display candidate with the most votes here
        break;
      default:
        SetConsoleTextAttribute(h, 4);
        std::cout << "Invalid Input\n";
        break;
    }
    std::cout << std::endl;
  }
}
