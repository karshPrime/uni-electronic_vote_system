#include "general.h"
#include "options.h"

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

  SetConsoleTextAttribute(h, red);       // prompt font color = red
  print_file_content("heading");
  char chosen_option = 'a';

  // values required for actions
  int candidate_id, voter_id;

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
        input("Enter candidate ID: ", candidate_id);
        print_candidate_vote_count(candidate_id);
        break;

      case 'A':
        input("Enter voter's ID: ", voter_id);
        input("Enter voted Candidate's ID: ", candidate_id);
        add_vote_to_candidate(candidate_id, voter_id);
        break;

      case 'S':
        print_lowest_candidate_votes();
        break;

      case 'L':
        print_highest_candidate_votes();
        break;

      case 'Q':
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
