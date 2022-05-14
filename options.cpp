#pragma once

/*
Contains user option functions
*/

#include <fstream>
#include <iostream>
#include <string>

#include "options.h"
#include "general.h"

// would display passed candidate's vote count
void print_candidate_vote_count(int& id) {
	std::ifstream file("candidates.txt");

	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			auto candidate = construct_candidate(line);

			if (candidate.id == id) {
				std::cout << "Candidate " << id << " has " << candidate.count << " votes." << std::endl;
				break;
			}
		}

		file.close();
	}
	else
		std::cout << "candidate database not found" << std::endl;
}

// would add votes to required candidate
void add_vote_to_candidate(int& cid, int& vid) {

}

// would display candidate with lowest vote count
void print_lowest_candidate_votes() {

}

// would display candidate with highest vote count
void print_highest_candidate_votes() {

}
