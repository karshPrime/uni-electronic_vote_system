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

void print_file_content(std::string file_name);

void print_candidate(const Candidate&);

Candidate construct_candidate(const std::string& text);

void split(const std::string& str, const std::string& delimiters, std::vector<std::string>& tokens);