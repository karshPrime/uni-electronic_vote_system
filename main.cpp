#include <iostream>
#include "general.h"

template <typename T>
void input(const std::string& display, T& store_in) {
  std::cout << display << std::endl;
  std::cin >> store_in;
}

int main() {
  print_file_content("heading");
  char chosen_option = 'a';

  while (chosen_option != 'q') {
    print_file_content("menu");
    input(">>> ", chosen_option);
  }
}
