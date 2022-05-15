/*
This header contains declaration to general.cpp functions.
*/

// preventing header from being called more than once
#pragma once

#include <iostream>   // required for input/output of data
#include <windows.h>  // required to decorate windows console
#include <fstream>    // required to read/write/modify files
#include <vector>

// contains voter and candidate class
#include "person.cpp"

// prints the contents of the given text file
void print_file_content(std::string file_name);

// prints the details of a given candidate in a neat manner
void print_candidate(const Candidate&);

// creates a candidate object given a text string
Candidate construct_candidate(const std::string& text);

// creates a voter object given a text string
Voter construct_voter(const std::string& text);

// Given a string, splits it by the delimiter and puts it in a vector
void split_string(const std::string& str, const std::string& delimiters, std::vector<std::string>& result);