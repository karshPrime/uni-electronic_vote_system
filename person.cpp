// Aweb Mekhilef (103574757) Utkarsh Kishore Ranjan (102874485) Quang Thanh Tran (102649968)

/*
	Contains the classes representing the voter and candidate
*/

#include "general.h"

// Parent class for voter and candidate
class Person {
public:
    // first name, last name, suburb, email, gender, phone
    std::string f_name, l_name, suburb, email, gender, phone;

    // age and id
    int age, id;

	// overriden by subclasses
	// responsible for initalization from database string
	virtual void init(const std::string& text) = 0;
};

class Voter : public Person {
public:
    bool has_voted = false;  // if voter has voted; by default not.
    std::string date_voted; // will not be included in the file until the voter casts their vote.

	// initalizes the voter given a string from the database
    void init(const std::string &text) {
      // get the tokens (in order defined in file)
      std::vector<std::string> attributes;
      split_string(text, " ", attributes);

      // assign the variables to the candidate object
      has_voted = attributes[0] == "y";
      id = std::stoi(attributes[1]);
      l_name = attributes[2];
      f_name = attributes[3];
      age = stoi(attributes[4]);
      gender = attributes[5];
      suburb = attributes[6];
      email = attributes[7];
      phone = attributes[8];

      // if the candidate hasn't voted yet there wil be no date voted string
      if (has_voted) {
        date_voted = attributes[9];
      }
    }
};

class Candidate : public Person {
public:
  std::string symbol;	// political party symbol
  int count;

  // initalizes the candidate given a string from the database
  void init(const std::string &text){
    // get the tokens (in order defined in file)
    std::vector<std::string> attributes;
    split_string(text, " ", attributes);

    // assign the variables to the candidate object
    count = std::stoi(attributes[0]);
    id = std::stoi(attributes[1]);
    symbol = attributes[2];
    l_name = attributes[3];
    f_name = attributes[4];
    age = std::stoi(attributes[5]);
    gender = attributes[6];
    suburb = attributes[7];
    email = attributes[8];
    phone = attributes[9];
  }

  // print candidate details
  void print() {
    // configure console color
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    // color codes
    int red = 4, aqua = 11, green = 10, yellow = 14;

    SetConsoleTextAttribute(h, green);
    std::cout << "ID           : ";
    SetConsoleTextAttribute(h, aqua);
    std::cout << id << std::endl;

    SetConsoleTextAttribute(h, green);
    std::cout << "Name:        : ";
    SetConsoleTextAttribute(h, aqua);
    std::cout << l_name << " " << f_name << std::endl;

    SetConsoleTextAttribute(h, red);
    std::cout << "Total Votes  : ";
    SetConsoleTextAttribute(h, yellow);
    std::cout << count << std::endl;

    SetConsoleTextAttribute(h, green);
    std::cout << "Party:       : ";
    SetConsoleTextAttribute(h, aqua);
    std::cout << symbol << std::endl;

    SetConsoleTextAttribute(h, green);
    std::cout << "Age:         : ";
    SetConsoleTextAttribute(h, aqua);
    std::cout << age << std::endl;

    SetConsoleTextAttribute(h, green);
    std::cout << "Gender       : ";
    SetConsoleTextAttribute(h, aqua);
    std::cout << gender << std::endl;

    SetConsoleTextAttribute(h, green);
    std::cout << "Suburb:      : ";
    SetConsoleTextAttribute(h, aqua);
    std::cout << suburb << std::endl;

    SetConsoleTextAttribute(h, green);
    std::cout << "Phone Number : ";
    SetConsoleTextAttribute(h, aqua);
    std::cout << phone << std::endl;

    SetConsoleTextAttribute(h, green);
    std::cout << "email        : ";
    SetConsoleTextAttribute(h, aqua);
    std::cout << email << std::endl;
  }
};
