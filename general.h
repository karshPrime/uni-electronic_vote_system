// Aweb Mekhilef (103574757) Utkarsh Kishore Ranjan (102874485) Quang Thanh Tran (102649968)

/*
This header contains declaration to general.cpp functions.
*/

#pragma once
#ifndef Group19_general
#define Group19_general

#include <iostream>   // required for input/output of data
#include <windows.h>  // required to decorate windows console
#include <fstream>    // required to read/write/modify files
#include <vector>
#include <string>

// prints the contents of the given text file
void print_file_content(std::string);

// Given a string, splits it by the delimiter and puts it in a vector
void split_string(const std::string &, const std::string &, std::vector<std::string> &);

#endif //Group19_general
