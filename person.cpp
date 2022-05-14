#include <string>

// Parent class for voter and candidate
struct Person {
	// first name, last name, suburb, email, gender
	std::string f_name, l_name, suburb, email, gender;

	// age, phone and id
	int age, phone, id;
};

struct Voter : public Person {
	bool has_voted = false;  // if voter has voted; by default not.
};

struct Candidate : public Person {
	std::string symbol;        // political party symbol
	std::size_t count;  // count can only be positive int
};
