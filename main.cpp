#include <iostream>
#include <windows.h>
#include "general.h"
#include "options.h"

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
  }
}
