/*
This file contains functions that would be required by different modules
*/

#include "general.h"    // contains common declarations

// prints the contents of the given text file
void print_file_content(std::string file_name) {
	// adding file extension
	file_name += ".txt";

	std::fstream toread;

	toread.open(file_name, std::ios::in);
	if (toread.is_open()) {
		std::string text_line;

		// loop through the file- line by line, and print the content
		while (std::getline(toread, text_line)) {
			std::cout << text_line << "\n";
		}

		toread.close();
	}
	else {
		std::cout << "file not found\n";
	}
}

// prints the details of a given candidate in a neat manner
void print_candidate(const Candidate &c) {
	// configure console color
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	// color codes
	int red = 4, aqua = 11, green = 10, yellow = 14;

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

// given a string, splits it by the delimiter and puts it in a vector
// Reference: https://stackoverflow.com/a/600040
void split_string(const std::string &str, const std::string &delimiters, std::vector<std::string> &result) {
  // Skip delimiters at beginning.
  std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);

  // find first "non-delimiter".
  std::string::size_type pos = str.find_first_of(delimiters, lastPos);

  while (std::string::npos != pos || std::string::npos != lastPos) {
    // found a token, add it to the vector.
    result.push_back(str.substr(lastPos, pos - lastPos));

    // skip delimiters. Note the "not_of"
    lastPos = str.find_first_not_of(delimiters, pos);

    // find next "non-delimiter"
    pos = str.find_first_of(delimiters, lastPos);
  }
}

// creates a candidate object given a text string
Candidate construct_candidate(const std::string &text) {
	Candidate candidate;

	// get the tokens (in order defined in file)
	std::vector<std::string> attributes;
	split_string(text, " ", attributes);

	// assign the variables to the candidate object
	candidate.count = std::stoi(attributes[0]);
	candidate.id = std::stoi(attributes[1]);
	candidate.symbol = attributes[2];
	candidate.l_name = attributes[3];
	candidate.f_name = attributes[4];
	candidate.age = std::stoi(attributes[5]);
	candidate.gender = attributes[6];
	candidate.suburb = attributes[7];
	candidate.email = attributes[8];
	candidate.phone = attributes[9];

	return candidate;
}

// creates a voter object given a text string
Voter construct_voter(const std::string &text) {
	Voter voter;

	// get the tokens (in order defined in file)
	std::vector<std::string> attributes;
	split_string(text, " ", attributes);

	// assign the variables to the candidate object
	voter.has_voted = attributes[0] == "y";
	voter.id = std::stoi(attributes[1]);
	voter.l_name = attributes[2];
	voter.f_name = attributes[3];
	voter.age = stoi(attributes[4]);
	voter.gender = attributes[5];
	voter.suburb = attributes[6];
	voter.email = attributes[7];
	voter.phone = attributes[8];

	// if the candidate hasn't voted yet there wil be no date voted string
	if (voter.has_voted) {
    voter.date_voted = attributes[9];
  }
	return voter;
}
