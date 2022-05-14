#include <string>

// Parent class for voter and candidate
struct Person {
	// first name, last name, suburb, email, gender
	std::string f_name, l_name, suburb, email, gender, phone;

	// age, phone and id
	int age, id;
};

struct Voter : public Person {
	bool has_voted = false;  // if voter has voted; by default not.
	std::string date_voted; // will not be included in the file until the voter casts their vote.
};

struct Candidate : public Person {
	std::string symbol;	// political party symbol
	std::size_t count;	// count can only be positive int
};
