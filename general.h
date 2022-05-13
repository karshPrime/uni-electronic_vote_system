/*
This header contains declaration to general.cpp functions.
*/

// preventing header from being called more than once
#pragma once

#include <iostream>   // required for input/output of data
#include <windows.h>  // required to decorate windows console
#include <fstream>    // required to read/write/modify files

// contains voter and candidate class
#include "person.cpp"

// print menu and heading
void print_file_content(std::string file_name);
void print_candidate(const Candidate&);
