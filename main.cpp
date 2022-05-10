#include <iostream>

#include "general.h"
#include "options.h"

// more compact way to get user input
template <typename T>
void input(const std::string& display, T& store_in) {
  std::cout << display << std::endl;
  std::cin >> store_in;
}

// main function
int main() {
  print_file_content("heading");
  char chosen_option = 'a';

  // loop until user opts to quit
  while (chosen_option != 'q') {
    print_file_content("menu");
    input(">>> ", chosen_option);
  }
}
