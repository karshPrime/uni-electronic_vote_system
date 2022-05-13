#include <string>

// Parent class for voter and candidate
class Person {
public:
    // first name, last name, suburb, email, gender
    std::string f_name, l_name, suburb, email, gender;

    // age, phone and id
    int age, phone, id;
};

// Voter class
class Voter : public Person {
public:
    bool has_voted = false;  // if voter has voted; by default not.
};

// candidate class
class Candidate : public Person {
public:
    std::string symbol;        // political party symbol
    std::size_t count;  // count can only be positive int
};
