#include <iostream>

// Parent class for voter and candidate
class Person {
public:
    std::string name, suburb; // name and suburb
    int age;                  // age
};

// Voter class
class Voter : public Person {
public:
    int id;                  // voter id
    bool has_voted = false;  // if voter has voted; by default not.
};

// candidate class
class Candidate : public Person {
public:
    char symbol;        // political party symbol
    std::size_t count;  // count can only be positive int
};
