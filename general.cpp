#include <iostream>
#include <fstream>

void print_file_content(std::string file_name) {
  file_name += ".txt";
  std::fstream toread;

  toread.open(file_name, std::ios::in);
  if (toread.is_open()) {
    std::string text_line;

    while (std::getline(toread, text_line)) {
      std::cout << text_line << "\n";
    }
    toread.close();
  } else {
    std::cout << "file not found\n";
  }
}
