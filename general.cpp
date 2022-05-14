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

	}
	else {
		std::cout << "file not found\n";
	}
}

// print details of passed candidate
void print_candidate(const Candidate& c) {
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

Candidate construct_candidate(const std::string& text)
{
	Candidate candidate;

	std::vector<std::string> attributes;
	split(text, " ", attributes);

	std::cout << attributes[5];

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

// Given a string, splits it by the delimiter and puts it in a vector
// Reference: https://stackoverflow.com/a/600040
void split(const std::string& str, const std::string& delimiters, std::vector<std::string>& tokens)
{
	// Skip delimiters at beginning.
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
}